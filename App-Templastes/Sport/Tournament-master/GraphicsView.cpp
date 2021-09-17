#include "GraphicsView.h"

#include <QMouseEvent>
#include <QDebug>
#include <QTimer>

GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent)
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignCenter);
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        setDragMode(QGraphicsView::ScrollHandDrag);
        QGraphicsView::mousePressEvent(event);
    }
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    scene()->update();
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
        scale(1.25, 1.25);
    else
        scale(0.8, 0.8);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    setDragMode(QGraphicsView::NoDrag);
    QGraphicsView::mouseReleaseEvent(event);
}
