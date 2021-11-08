#include "plottriangle.h"

PlotTriangle::PlotTriangle()
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

QPainterPath PlotTriangle::shape() const
{
    // Plots the x,y coordinates of the 3 points of the triangle, and returns the path
    // to the origin as the 4th point
    QPointF p1(0,-7);
    QPointF p2(-7,7);
    QPointF p3(7,7);
    QPointF p4(0,-7);

    QPainterPath path;
    path.addPolygon(QPolygonF() << p1 << p2 << p3 << p4);
    return path;
}

QRectF PlotTriangle::boundingRect() const
{
    // Sets the container for the point
    return shape().boundingRect();
}

void PlotTriangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Sets the brush and outline (pen) parameters, and draws the point object
    QBrush Brush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(3);

    painter->drawPath(shape());
    painter->fillPath(shape(),Brush);
}

