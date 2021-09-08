#include "MatchWidget.h"

#include <QPainter>
#include <QPainterPath>

MatchWidget::MatchWidget(Match *match, QWidget *parent) : QWidget(parent)
{
    connect(match, SIGNAL(finished()), this, SLOT(onUpdateRequest()));
    connect(match, SIGNAL(requestUpdate()), this, SLOT(onUpdateRequest()));
    m_Player1 = match->getPlayer1();
    m_Player2 = match->getPlayer2();
    int pointsWidgetWidth = height();
    int pointsWidgetHeight = height();

    layout = new QVBoxLayout(this);

    player1Widget = new QWidget();
    player1Layout = new QHBoxLayout(player1Widget);
    p1Label = new QLabel("---");
    if (m_Player1) p1Label->setText((m_Player1->getName()));
    pointsPlayer1Widget = new PointsWidget(/*pointsWidgetWidth, pointsWidgetHeight, */ this);
    p1Label->setStyleSheet("color: white;font-size: 14px;");

    player1Layout->addWidget(p1Label);
    player1Layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Preferred, QSizePolicy::Preferred));
    player1Layout->addWidget(pointsPlayer1Widget);

    player2Widget = new QWidget();
    player2Layout = new QHBoxLayout(player2Widget);
    p2Label = new QLabel("---");
    if (m_Player2) p2Label->setText((m_Player2->getName()));
    pointsPlayer2Widget = new PointsWidget(/*pointsWidgetWidth, pointsWidgetHeight,*/ this);
    p2Label->setStyleSheet("color: white; font-size: 14px;");

    player2Layout->addWidget(p2Label);
    player2Layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Preferred, QSizePolicy::Preferred));
    player2Layout->addWidget(pointsPlayer2Widget);

    layout->addWidget(player1Widget);
    layout->addWidget(player2Widget);

    player1Widget->setContentsMargins(10, 0, 0, 0);
    player2Widget->setContentsMargins(10, 0, 0, 0);

    player1Layout->setContentsMargins(0, 0, 0, 0);
    player1Layout->setMargin(0);
    player2Layout->setContentsMargins(0, 0, 0, 0);
    player2Layout->setMargin(0);
    p1Label->setContentsMargins(0, 0, 0, 0);
    p1Label->setMargin(0);
    p2Label->setContentsMargins(0, 0, 0, 0);
    p2Label->setMargin(0);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setMargin(0);
}

void MatchWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()), 5, 5);

    //    painter.setPen(QColor(105, 105, 105));
    painter.fillPath(path, QColor(105, 105, 105));

    painter.drawPath(path);

    QPainterPath seperator;
    seperator.addRect(0, height() / 2, width(), 1);
    //    painter.setPen(QColor(0, 0, 0));
    painter.fillPath(seperator, QColor(0, 0, 0));
    painter.drawPath(seperator);
}

void MatchWidget::onUpdateRequest()
{
    Match *match = static_cast< Match * >(sender());
    m_Player1 = match->getPlayer1();
    m_Player2 = match->getPlayer2();
    if (m_Player1) p1Label->setText((m_Player1->getName()));
    if (m_Player2) p2Label->setText((m_Player2->getName()));

    if (match->isFinished())
    {
        auto player = match->getWinner();
        if (player == m_Player1)
        {
            pointsPlayer1Widget->setWinner(true);
            pointsPlayer1Widget->setRoundsWon(1);
        }
        else if (player == m_Player2)
        {
            pointsPlayer2Widget->setWinner(true);
            pointsPlayer2Widget->setRoundsWon(1);
        }
    }
}
