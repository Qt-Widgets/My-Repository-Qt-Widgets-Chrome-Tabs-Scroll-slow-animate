#include "AddPlayerWidget.h"

AddPlayerWidget::AddPlayerWidget(QWidget *parent) : QWidget(parent) { layout = new QVBoxLayout(this); }

void AddPlayerWidget::addPlayerLineEdit(const QString &name)
{
    QLineEdit *lineEdit = new QLineEdit(name, this);
    layout->addWidget(lineEdit);
    lineEdits.append(lineEdit);
}

void AddPlayerWidget::removePlayerLineEdit()
{
    if (lineEdits.size() <= 1) return;

    auto w = lineEdits.takeLast();
    layout->removeWidget(w);
    delete w;
}

void AddPlayerWidget::randomise(QList< QString > players)
{
    removeAll();

    foreach (auto s, players)
    {
        addPlayerLineEdit(s);
    }
}

QList< QString > AddPlayerWidget::getPlayerNames()
{
    QList< QString > list;
    foreach (auto w, lineEdits)
    {
        list.append(w->text());
    }
    return list;
}

void AddPlayerWidget::removeAll()
{
    foreach (auto w, lineEdits)
    {
        layout->removeWidget(w);
        delete w;
    }
    lineEdits.clear();
}
