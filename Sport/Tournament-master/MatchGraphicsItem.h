#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QObject>
#include <QGraphicsItem>

class Match;
class Player;

class MatchGraphicsItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
  public:
    MatchGraphicsItem(const QRectF pos, Match *match, QGraphicsItem *parent = nullptr);

  private:
    int m_PointsPlayer1 = 0;
    int m_PointsPlayer2 = 0;
    QString m_Player1 = "---";
    QString m_Player2 = "---";
    QRectF m_Pos;
    Match *m_Match = Q_NULLPTR;
    QRectF upperHalf;
    QRectF lowerHalf;
    bool ignoreClick = false;
    QColor matchBackgroundColor = QColor(105, 105, 105);
    QColor activeMatchBorderColor = QColor(117, 233, 0);
    QColor separatorColor = QColor(255, 255, 255);
    QColor matchPointsColor = QColor(192, 192, 192);
    QColor matchPointsWinnerColor = QColor(255, 140, 0);
    QColor matchPlayerTextColor = QColor(0, 0, 0);
    QColor matchPointsTextColor = QColor(0, 0, 0);

  signals:
    void clicked(Match *match, Player *player);

  private slots:
    void requestUpdate();

    // QGraphicsItem interface
  public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // QGraphicsItem interface
  protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif  // GRAPHICSITEM_H
