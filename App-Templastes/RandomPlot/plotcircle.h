#ifndef PLOTCIRCLE_H
#define PLOTCIRCLE_H

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QtCore>
#include <QtGui>

class PlotCircle : public QGraphicsItem
{
public:
    PlotCircle();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLOTCIRCLE_H
