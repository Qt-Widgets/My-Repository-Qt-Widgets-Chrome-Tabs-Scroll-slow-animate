#include "plotsquare.h"

PlotSquare::PlotSquare()
{
    // Ensures the point objects appear in a uniform manner
    setFlag(ItemIgnoresTransformations, true);

    // Sets the point object to random x,y coordinates between 0,0 and 400,400
    int XCoord = 0;
    int YCoord = 0;

    XCoord = (qrand() % 400);
    YCoord = (qrand() % 400);

    setPos(mapToParent(XCoord,YCoord));
}

QRectF PlotSquare::boundingRect() const
{
    // Sets the container for the point
    return QRect(0,0,10,10);
}

void PlotSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Sets the brush and outline (pen) parameters, and draws the point object
    QRectF rec = boundingRect();
    QBrush Brush(Qt::yellow);
    QPen blackPen(Qt::black);
    blackPen.setWidth(3);

    painter->fillRect(rec,Brush);

    painter->drawRect(rec);
}
