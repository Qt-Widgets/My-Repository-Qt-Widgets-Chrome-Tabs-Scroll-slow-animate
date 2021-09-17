#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "itemdelegate.h"

#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new QStandardItemModel(this);

    for(int i = 0; i < 10; ++i) {
        QStandardItem *item = new QStandardItem(QString::number(i * 10));
        m_model->appendRow(item);
    }

    ui->treeView->setModel(m_model);
    ui->treeView->setItemDelegate(new ItemDelegate(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
