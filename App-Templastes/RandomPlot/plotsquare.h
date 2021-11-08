#ifndef PLOTSQUARE_H
#define PLOTSQUARE_H

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QtCore>
#include <QtGui>

class PlotSquare : public QGraphicsItem
{
public:
    PlotSquare();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLOTSQUARE_H
