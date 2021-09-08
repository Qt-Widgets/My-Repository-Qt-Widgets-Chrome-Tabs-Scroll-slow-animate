#include "TournamentGraphicScene.h"

#include "Tournament.h"
#include "MatchWidgetForm.h"
#include "MatchGraphicsItem.h"
#include "Match.h"
#include "Player.h"
#include "Settings.h"
#include "SettingsData.h"

#include <QMap>
#include <QList>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QPainter>

TournamentGraphicScene::TournamentGraphicScene(Tournament *tournament)
{
    m_Tournament = tournament;
    connect(m_Tournament, &Tournament::requestUpdate, this, &TournamentGraphicScene::requestUpdate);

    SettingsData *s = Settings::instance()->getSettingsData();
    backgroundColor1 = s->getBackgroundColor1();
    backgroundColor2 = s->getBackgroundColor2();
    backgroundColor3 = s->getBackgroundColor3();
    backgroundColor4 = s->getBackgroundColor4();
    backgroundColor5 = s->getBackgroundColor5();
    backgroundColor6 = s->getBackgroundColor6();
    roundsBackgroundColor = s->getRoundsBackgroundColor();
    roundsBorderColor = s->getRoundsBorderColor();
    roundsLineColor = s->getRoundsLineColor();

    init();
}

void TournamentGraphicScene::updateColors()
{
    SettingsData *s = Settings::instance()->getSettingsData();
    backgroundColor1 = s->getBackgroundColor1();
    backgroundColor2 = s->getBackgroundColor2();
    backgroundColor3 = s->getBackgroundColor3();
    backgroundColor4 = s->getBackgroundColor4();
    backgroundColor5 = s->getBackgroundColor5();
    backgroundColor6 = s->getBackgroundColor6();
    roundsBackgroundColor = s->getRoundsBackgroundColor();
    roundsBorderColor = s->getRoundsBorderColor();
    roundsLineColor = s->getRoundsLineColor();

    update();
}

void TournamentGraphicScene::requestUpdate() { update(); }

void TournamentGraphicScene::onItemClicked(Match *match, Player *winner) { itemClicked(match, winner); }

void TournamentGraphicScene::init()
{
    auto rounds = m_Tournament->getRounds();
    if (rounds.isEmpty()) return;
    int nRounds = rounds.size();
    int tmp = rounds.first()->nMatches();
    if (tmp != 1 && tmp % 2 != 0) tmp++;

    int totalHeight = tmp * m_MatchWidgetHeight + (tmp - 1) * m_RowSpacing;

    setSceneRect(-100, -100, nRounds * m_MatchWidgetWidth + (nRounds - 1) * m_ColumnSpacing + 200, totalHeight + m_RowSpacing + 200);

    QPen roundsBorderPen(roundsBorderColor);
    QPen roundsLinePen(roundsLineColor);
    QBrush brush(roundsBackgroundColor);

    QList< QGraphicsItem * > previousRoundItems;
    QMap< Match *, QGraphicsItem * > items;
    for (int i = 0; i < rounds.size(); i++)
    {
        QList< QGraphicsItem * > roundItems;
        qDebug() << "Round " << i + 1;
        auto matches = rounds[i]->getMatches();

        int x = i * (m_MatchWidgetWidth + m_ColumnSpacing);
        for (int j = 0; j < matches.size(); j++)
        {
            auto match = matches[j];

            int y = j * (m_MatchWidgetHeight + m_RowSpacing);

            auto pm1 = match->getPreviousMatch1();
            if (pm1)
            {
                auto pi0 = previousRoundItems[0];
                auto pi1 = previousRoundItems[1];
                auto y0 = pi0->mapToScene(pi0->boundingRect().bottomLeft()).y();  // Unterkante
                auto y1 = pi1->mapToScene(pi1->boundingRect().topLeft()).y();     // Oberkante

                auto dist = y1 - y0;

                auto item1 = items[pm1];
                auto bb1 = item1->boundingRect();
                auto br1 = item1->mapToScene(bb1.bottomRight());

                auto px0 = br1.x();
                auto py0 = br1.y() - m_MatchWidgetHeight * 0.5;
                auto px1 = px0 + m_ColumnSpacing * 0.5;
                auto py1 = py0;
                auto px2 = px1;
                auto py2 = br1.y() + dist * 0.5;
                auto px3 = px2 + m_ColumnSpacing * 0.5;
                auto py3 = py2;
                auto px4 = px2;
                auto py4 = py2 + (py2 - py1);
                auto px5 = px0;
                auto py5 = py4;

                y = py3 - m_MatchWidgetHeight * 0.5;

                if (py2 > totalHeight)  // In some cases the lowest widget is outbound at bottom.
                {
                    addLine(px0, py0, px1, py1, roundsLinePen);
                    int tmp = m_MatchWidgetHeight + m_ColumnSpacing * 0.5;
                    py2 -= tmp;
                    py3 -= tmp;
                    y -= tmp;
                    addLine(px1, py1, px2, py2, roundsLinePen);
                    addLine(px2, py2, px3, py3, roundsLinePen);
                }
                else
                {
                    addLine(px0, py0, px1, py1, roundsLinePen);
                    addLine(px1, py1, px2, py2, roundsLinePen);
                    addLine(px2, py2, px3, py3, roundsLinePen);
                }

                if (match->getPreviousMatch2())
                {
                    addLine(px5, py5, px4, py4, roundsLinePen);
                    addLine(px4, py4, px2, py2, roundsLinePen);
                }
            }

            //            MatchWidgetForm *mw = new MatchWidgetForm(match);
            //            mw->setFixedSize(m_MatchWidgetWidth, m_MatchWidgetHeight);
            //            auto item = addWidget(mw);
            //            item->setPos(x, y);
            //            roundItems.append(item);
            //            items.insert(match, item);


            MatchGraphicsItem *graphicsItem = new MatchGraphicsItem(QRectF(0, 0, m_MatchWidgetWidth, m_MatchWidgetHeight), match);
            connect(graphicsItem, SIGNAL(clicked(Match *, Player *)), this, SLOT(onItemClicked(Match *, Player *)));
            graphicsItem->setPos(x, y);
            roundItems.append(graphicsItem);
            items.insert(match, graphicsItem);
            addItem(graphicsItem);
        }

        auto textItem = addText(rounds[i]->getName(), QFont("sans", 16, 2));
        textItem->moveBy(x - 5 + (m_MatchWidgetWidth + 10 - textItem->boundingRect().width()) * 0.5, -30);
        textItem->setZValue(1);


        QPainterPath path;
        path.addRoundedRect(x - 5, -30, m_MatchWidgetWidth + 10, totalHeight + 35, 10, 10);
        QGraphicsPathItem *rectItem = new QGraphicsPathItem(path);
        rectItem->setZValue(-1);
        rectItem->setOpacity(0.5);
        rectItem->setPen(roundsBorderPen);
        rectItem->setBrush(brush);
        addItem(rectItem);

        previousRoundItems.clear();
        previousRoundItems.append(roundItems);
    }

    settingsPushButton = new QPushButton("Settings");
    connect(settingsPushButton, SIGNAL(pressed()), this, SIGNAL(settingsPressed()));
    settingsPushButton->setGeometry(0, -100, 32, 32);
    addWidget(settingsPushButton);

    addPlayerPushButton = new QPushButton("Add Player");
    connect(addPlayerPushButton, SIGNAL(pressed()), this, SIGNAL(addPlayerPressed()));
    addPlayerPushButton->setGeometry(100, -100, 32, 32);
    addWidget(addPlayerPushButton);
}


void TournamentGraphicScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QLinearGradient linearGrad(rect.topLeft(), rect.bottomRight());
    linearGrad.setColorAt(0, backgroundColor1);
    linearGrad.setColorAt(0.2, backgroundColor2);
    linearGrad.setColorAt(0.4, backgroundColor3);
    linearGrad.setColorAt(0.6, backgroundColor4);
    linearGrad.setColorAt(0.8, backgroundColor5);
    linearGrad.setColorAt(1, backgroundColor6);
    painter->fillRect(rect, linearGrad);
}
