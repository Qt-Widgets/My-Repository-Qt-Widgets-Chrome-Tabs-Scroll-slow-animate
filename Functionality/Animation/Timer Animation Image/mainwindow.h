#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QImage>
#include <QGraphicsEllipseItem>
#include <QVBoxLayout>
#include <QLabel>

class SimpleAnimation : public QWidget
{
    Q_OBJECT

public:
    SimpleAnimation(QWidget *parent = nullptr)
        : QWidget(parent)
        , m_image(":/0_0.png")
    {
        m_label = new QLabel();
        m_label->setPixmap(m_image);

        QVBoxLayout* mainLayout = new QVBoxLayout;
        mainLayout->addWidget(m_label);

        setLayout(mainLayout);
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &SimpleAnimation::onTimeout);
        m_timer->start(100);

    }
    ~SimpleAnimation()
    {
    }

protected slots:
    void onTimeout()
    {
        QPoint oldPosition = m_label->pos();
        QPoint newPosition = QPoint(oldPosition.x() + 10, oldPosition.y());

        m_label->move(newPosition);
    }

private:
    QLabel *m_label;
    QTimer* m_timer;
    QPixmap m_image;

};
#endif // MAINWINDOW_H
