#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
  public:
    GraphicsView(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);

    // QWidget interface
  protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // QWidget interface
  protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif  // GRAPHICSVIEW_H
