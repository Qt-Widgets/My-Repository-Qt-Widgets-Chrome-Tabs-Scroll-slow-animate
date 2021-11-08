#ifndef PLOTTRIANGLE_H
#define PLOTTRIANGLE_H

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QtCore>
#include <QtGui>

class PlotTriangle : public QGraphicsItem
{
public:
    PlotTriangle();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLOTTRIANGLE_H
