#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
//    QColor color = QColorDialog::getColor(Qt::red,this,tr("颜色对话框"),QColorDialog::ShowAlphaChannel);
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();

    qDebug()<<"color:"<<color;
}

void Widget::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"文件对话框","D:","Images (*.png *.jpg);;code (*.cpp);;header (*.h)");
    qDebug()<<"filename:"<<filename;
}

void Widget::on_pushButton_3_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,QFont("Times",12),this);
    if(ok)
    {
        ui->pushButton_3->setFont(font);
    }
}

void Widget::on_pushButton_4_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this,tr("字符输入"),tr("输入"),QLineEdit::PasswordEchoOnEdit,"text",&ok);
    if(ok)
    {
        qDebug()<<"string"<<string;
    }

    int i = QInputDialog::getInt(this,"get int","input",0,0,12,1,&ok);
    if(ok)
    {
        qDebug()<<"i"<<i;
    }

    QStringList item;
    item<<"1"<<"2";
    QString list = QInputDialog::getItem(this,"item_get","input",item,1,false,&ok);
}

void Widget::on_pushButton_5_clicked()
{
    int back = QMessageBox::question(this,"hahah","hahaha",QMessageBox::Ok,QMessageBox::No);
    if(back == QMessageBox::Ok)
    {
        qDebug()<<"well";
    }

    back = QMessageBox::information(this,"ha","ha",QMessageBox::Ok,QMessageBox::No);
    if(back == QMessageBox::Ok)
    {
        qDebug()<<"well";
    }

    QMessageBox::warning(this,"ok?","hah",QMessageBox::Ok,QMessageBox::Abort);

    QMessageBox::critical(this,"ok?","hah",QMessageBox::YesAll,QMessageBox::Abort);
}

void Widget::on_pushButton_7_clicked()
{
    QProgressDialog bar("haha","cancel",0,500000,this);
    bar.setWindowTitle("dialog for progress");
    bar.setWindowModality(Qt::WindowModal);
    bar.show();

    for(int i = 0; i <500001; i++)
    {
        bar.setValue(i);
        if(bar.wasCanceled())break;
    }
}

void Widget::on_pushButton_6_clicked()
{
    QErrorMessage *error = new QErrorMessage;
    error->setWindowTitle("error");
    error->showMessage("wrong");
}

void Widget::on_pushButton_8_clicked()
{
    QWizardPage *page1 = new QWizardPage;
    QWizardPage *page2 = new QWizardPage;
    QWizardPage *page3 = new QWizardPage;
    page1->setWindowTitle("introduce");
    page2->setWindowTitle("choose");
    page3->setWindowTitle("exit");

    QWizard wizard(this);
    wizard.addPage(page1);
    wizard.addPage(page2);
    wizard.addPage(page3);
    wizard.setWindowTitle("wizard");
    wizard.exec();
}
