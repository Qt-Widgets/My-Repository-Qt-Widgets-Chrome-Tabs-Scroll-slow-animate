#include "MatchGraphicsItem.h"

#include "Match.h"
#include "Settings.h"
#include "SettingsData.h"

#include <QPainter>
#include <QPainterPath>
#include <QFontMetrics>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

MatchGraphicsItem::MatchGraphicsItem(const QRectF pos, Match *match, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    m_Match = match;
    m_Pos = pos;
    if (match->getPlayer1()) m_Player1 = match->getPlayer1()->getName();
    if (match->getPlayer2()) m_Player2 = match->getPlayer2()->getName();
    QObject::connect(match, &Match::finished, this, &MatchGraphicsItem::requestUpdate);
    QObject::connect(match, &Match::requestUpdate, this, &MatchGraphicsItem::requestUpdate);

    if (match->isFinished())
    {
        if (match->getWinner() == match->getPlayer1())
        {
            m_PointsPlayer1 = 1;
        }
        else if (match->getWinner() == match->getPlayer2())
        {
            m_PointsPlayer2 = 1;
        }
    }

    SettingsData *s = Settings::instance()->getSettingsData();
    matchBackgroundColor = s->getMatchBackgroundColor();
    activeMatchBorderColor = s->getActiveMatchBorderColor();
    separatorColor = s->getMatchSeparatorColor();
    matchPointsColor = s->getMatchPointsBackgroundColor();
    matchPointsWinnerColor = s->getMatchPointsWinnerBackgroundColor();
    matchPlayerTextColor = s->getMatchPlayerTextColor();
    matchPointsTextColor = s->getMatchPointsTextColor();
}

void MatchGraphicsItem::requestUpdate()
{
    Match *match = static_cast< Match * >(QObject::sender());
    if (match->getPlayer1()) m_Player1 = match->getPlayer1()->getName();
    if (match->getPlayer2()) m_Player2 = match->getPlayer2()->getName();

    if (match->isFinished())
    {
        auto player = match->getWinner();
        if (player == match->getPlayer1())
        {
            m_PointsPlayer1 = 1;
        }
        else if (player == match->getPlayer2())
        {
            m_PointsPlayer2 = 1;
        }
    }
    update();
}

QRectF MatchGraphicsItem::boundingRect() const { return m_Pos; }

void MatchGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    upperHalf = QRectF(0, 0, rect.width(), rect.height() * 0.5);
    lowerHalf = QRectF(0, rect.height() - rect.height() * 0.5, rect.width(), rect.height() * 0.5);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setFont(QFont("sans", 14, 2));
    QTextOption options;
    options.setAlignment(Qt::AlignLeft);
    QFontMetrics fmetrics = painter->fontMetrics();
    int textHeight = fmetrics.height();

    // Full Rect
    QPainterPath path;
    path.addRoundedRect(rect, 5, 5);
    painter->fillPath(path, matchBackgroundColor);
    if (m_Match->IsActive())
    {
        painter->setPen(activeMatchBorderColor);
    }
    painter->drawPath(path);
    painter->setPen(QColor(0, 0, 0));

    // Middle Seperator
    QPainterPath separator;
    separator.addRect(rect.x() + 5, rect.height() / 2, rect.width() - 10, 1);
    painter->fillPath(separator, separatorColor);

    // Upper Half
    // Player Name
    QRectF upperTextRect = boundingRect();
    upperTextRect.setX(upperTextRect.x() + 5);
    upperTextRect.setY((upperTextRect.height() * 0.5 * 0.5) - (textHeight * 0.5 - 3));
    QPen matchPointsTextPen(matchPointsTextColor);
    QPen playerTextPen(matchPlayerTextColor);
    painter->setPen(playerTextPen);
    painter->drawText(upperTextRect, m_Player1, options);
    painter->setPen(QColor(0, 0, 0));

    // Upper Half Points Rect
    QRectF upperPointsRect = QRectF(boundingRect().topRight().x() - (boundingRect().width() / 5) - 5, boundingRect().y() + 5, boundingRect().width() / 5, boundingRect().height() / 2 - 10);
    QPainterPath upperPointsPath;
    upperPointsPath.addRoundedRect(upperPointsRect, 5, 5);
    if (m_Match->getWinner() && m_Match->getWinner() == m_Match->getPlayer1())
        painter->fillPath(upperPointsPath, matchPointsWinnerColor);
    else
        painter->fillPath(upperPointsPath, matchPointsColor);

    // Upper Half Points Text
    QRectF pointsTextRect = upperPointsRect;
    pointsTextRect.setX(upperPointsRect.x() + 15);
    pointsTextRect.setY(upperPointsRect.height() / 2 / 2 + 5);
    painter->setPen(matchPointsTextPen);
    painter->drawText(pointsTextRect, QString::number(m_PointsPlayer1), options);
    painter->setPen(QColor(0, 0, 0));

    // Lower Half
    // Player Name
    QRectF lowerTextRect = boundingRect();
    lowerTextRect.setX(lowerTextRect.x() + 5);
    lowerTextRect.setY(boundingRect().height() - (lowerTextRect.height() * 0.5) + (textHeight * 0.5 + 5));
    painter->setPen(playerTextPen);
    painter->drawText(lowerTextRect, m_Player2, options);
    painter->setPen(QColor(0, 0, 0));

    // Lower Half Points Rect
    QRectF lowerPointsRect =
        QRectF(boundingRect().topRight().x() - (boundingRect().width() / 5) - 5, boundingRect().y() + (boundingRect().height() / 2 + 5), boundingRect().width() / 5, boundingRect().height() / 2 - 10);
    QPainterPath lowerPointsPath;
    lowerPointsPath.addRoundedRect(lowerPointsRect, 5, 5);
    if (m_Match->getWinner() && m_Match->getWinner() == m_Match->getPlayer2())
        painter->fillPath(lowerPointsPath, matchPointsWinnerColor);
    else
        painter->fillPath(lowerPointsPath, matchPointsColor);

    // Lower Half Points Text
    QRectF lowerPointsTextRect = lowerPointsRect;
    lowerPointsTextRect.setX(lowerPointsRect.x() + 15);
    lowerPointsTextRect.setY(lowerPointsRect.height() + lowerPointsRect.height() / 2 + 5);
    painter->setPen(matchPointsTextPen);
    painter->drawText(lowerPointsTextRect, QString::number(m_PointsPlayer2), options);
    painter->setPen(QColor(0, 0, 0));
}


void MatchGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!m_Match->IsActive()) QGraphicsItem::mousePressEvent(event);
    ignoreClick = false;
}

void MatchGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (!m_Match || ignoreClick)
    {
        QGraphicsItem::mouseReleaseEvent(event);
        return;
    }
    QPointF pos = event->buttonDownPos(Qt::LeftButton);
    if (upperHalf.contains(pos))
    {
        clicked(m_Match, m_Match->getPlayer1());
        qDebug() << "MouseRelease On UpperHalf";
        //        QGraphicsItem::mouseReleaseEvent(event);
    }
    else if (lowerHalf.contains(pos))
    {
        clicked(m_Match, m_Match->getPlayer2());
        qDebug() << "MouseRelease On LowerHalf";
        //        QGraphicsItem::mouseReleaseEvent(event);
    }
}

void MatchGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    ignoreClick = true;
    QGraphicsItem::mouseMoveEvent(event);
}
