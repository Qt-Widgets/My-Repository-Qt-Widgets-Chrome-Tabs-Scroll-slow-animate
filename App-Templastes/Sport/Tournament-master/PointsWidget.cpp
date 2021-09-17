#include "PointsWidget.h"

#include <QPainter>
#include <QPainterPath>

PointsWidget::PointsWidget(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    m_RoundsWonLabel = new QLabel(QString::number(m_RoundsWon));

    layout = new QHBoxLayout(this);
    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));
    layout->addWidget(m_RoundsWonLabel);
    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));


    //    setGeometry(0, 0, 50, 100);

    //    setFixedSize(50, 50);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setMargin(0);
    setContentsMargins(0, 0, 0, 0);
}


void PointsWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()), 5, 5);

    QColor color = QColor(192, 192, 192);
    m_RoundsWonLabel->setStyleSheet("background-color: 192,192,192;");
    if (m_Winner)
    {
        color = QColor(255, 140, 0);
        m_RoundsWonLabel->setStyleSheet("background-color: 255,140,0;");
    }

    painter.fillPath(path, color);

    painter.drawPath(path);
}

void PointsWidget::setRoundsWon(int value)
{
    m_RoundsWon = value;
    m_RoundsWonLabel->setText(QString::number(value));
    repaint();
}

void PointsWidget::setWinner(bool Winner)
{
    m_Winner = Winner;
    repaint();
}
