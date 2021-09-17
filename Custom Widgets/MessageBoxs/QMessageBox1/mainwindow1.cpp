#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include<QMessageBox>
#include<QDebug>
#include<QtCore>
#include<QtGui>

MainWindow1::MainWindow1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}


void MainWindow1::on_pushButton_clicked()
{
    QMessageBox :: information(this,"Yogeshwari_212218104188","This is the information box");
}

void MainWindow1::on_pushButton_2_clicked()
{
    QMessageBox:: StandardButton reply;

       reply=QMessageBox:: question(this,"Yogeshwari_212218104188","Do you like cats?",
                              QMessageBox::Yes | QMessageBox::No);
       if(reply==QMessageBox::Yes)
          {
           QMessageBox::information(this,"Title Here","You love cats");
       }
       else
       {
           QMessageBox::information(this,"Title Here","You don't love cats");
       }
}

void MainWindow1::on_pushButton_3_clicked()
{
    QMessageBox::warning(this,"Yogeshwari_212218104188","This is a warning message");
}



void MainWindow1::on_pushButton_4_clicked()
{
    QMessageBox:: StandardButton reply;

    reply=QMessageBox:: question(this,"Yogeshwari_212218104188","Do you like cats?",
                           QMessageBox::Yes | QMessageBox::No |QMessageBox::YesToAll|QMessageBox::YesAll);
    if(reply==QMessageBox::Yes)
       {
        QMessageBox::information(this,"Title Here","You love cats");
    }
    if(reply==QMessageBox::YesToAll)
    {
        QMessageBox::information(this,"Title Here","Yeah i love them all");
    }
    else
    {
        QMessageBox::information(this,"Title Here","You don't love cats");
    }

}
