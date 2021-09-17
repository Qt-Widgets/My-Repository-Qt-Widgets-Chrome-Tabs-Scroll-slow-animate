#include "itemdelegate.h"

#include <QApplication>
#include <QPainter>
#include <QProxyStyle>
#include <QStylePainter>

ItemDelegate::ItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionProgressBar progressBarOption;
    progressBarOption.rect = option.rect;
    progressBarOption.minimum = 0;
    progressBarOption.maximum = 100;
    progressBarOption.progress = index.data().toInt();

    // This line crashes a QMessageBox
    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
}
