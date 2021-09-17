#include "RoundWidget.h"

#include "MatchWidget.h"

#include <QPainter>
#include <QPainterPath>
#include <QLabel>

RoundWidget::RoundWidget(const QString &roundName, QWidget *parent) : QWidget(parent)
{
    QLabel *roundNameLabel = new QLabel(roundName);
    layout = new QVBoxLayout(this);
    layout->addWidget(roundNameLabel);
    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));
}

void RoundWidget::addMatchWidgets(QList< MatchWidget * > machtWidgets)
{
    foreach (auto mw, machtWidgets)
        layout->addWidget(mw);

    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));
}

void RoundWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()), 5, 5);
    painter.fillPath(path, QColor(54, 54, 54));

    painter.drawPath(path);
}
