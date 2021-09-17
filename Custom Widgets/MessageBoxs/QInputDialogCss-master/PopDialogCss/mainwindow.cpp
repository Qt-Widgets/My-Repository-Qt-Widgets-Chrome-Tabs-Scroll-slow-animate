#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initEditDialog(QInputDialog &dialog, const QString &title, const QString &lable_text, const QString text)
{
    dialog.setWindowTitle(title);
    dialog.setInputMode(QInputDialog::InputMode::TextInput);
    dialog.setTextEchoMode(QLineEdit::Normal);
    dialog.setLabelText(lable_text);
    dialog.setOkButtonText(QObject::tr("确定"));
    dialog.setCancelButtonText(QObject::tr("取消"));
    dialog.setFixedSize(350,250);
    dialog.setTextValue(text);
}

void MainWindow::on_ptn_default_clicked()
{
    QInputDialog *dialog = new QInputDialog{this, Qt::WindowCloseButtonHint};
    initEditDialog(*dialog,tr("创建文件夹"), tr("请输入文件夹名称:") );

    QString style = ui->te_default->toPlainText();
    dialog->setStyleSheet(style);

//    if(dialog.exec() == QDialog::Accepted)
//        qDebug() << dialog.intValue();

//    connect(dialog, QInputDialog::textValueSelected, this, MainWindow::test);

    dialog->open(this, SLOT(test(QString)));

}

void MainWindow::on_ptn_new_clicked()
{
    QInputDialog dialog{this, Qt::WindowCloseButtonHint};
    initEditDialog(dialog,tr("创建文件夹"), tr("请输入文件夹名称:") );

    if (QDialogButtonBox *btn_box =  dialog.findChild<QDialogButtonBox*>() ){
        QString ok_style = ui->te_okbtn->toPlainText();
        btn_box->button(QDialogButtonBox::Ok)->setStyleSheet(ok_style);
        QString cancel_style = ui->te_cancelbtn->toPlainText();
        btn_box->button(QDialogButtonBox::Cancel)->setStyleSheet(cancel_style);
    }

    if (QVBoxLayout * layout = dialog.findChild<QVBoxLayout *>() ) {
        int space = ui->spinBox->value();
        layout->setSpacing(space);
    }

    QString style = ui->te_total->toPlainText();
    dialog.setStyleSheet(style);


    if(dialog.exec() == QDialog::Accepted)
        qDebug() << dialog.textValue();
}

void MainWindow::on_ptn_hasparent_clicked()
{
    bool ok = false;
    QTimer::singleShot(0, [this](){
        QInputDialog *dialog = this->findChild<QInputDialog *>();
        QString style = ui->te_default->toPlainText();
        dialog->setStyleSheet(style);
    });
    QString value = QInputDialog::getText(this, tr("创建文件夹"), tr("请输入文件夹名称："),QLineEdit::Normal, "", &ok, Qt::WindowCloseButtonHint );

    if (ok)
        qDebug() << value;
}

void MainWindow::on_ptn_noparent_clicked()
{
    bool ok = false;
    QTimer::singleShot(0, [this](){
        for(QWidget *widget: QApplication::topLevelWidgets()){
            if(QInputDialog *dialog = qobject_cast<QInputDialog*>(widget)){
                QString style = ui->te_default->toPlainText();
                dialog->setStyleSheet(style);
            }
        }
    });
    QString value = QInputDialog::getText(NULL, tr("创建文件夹"), tr("请输入文件夹名称："),QLineEdit::Normal, "", &ok, Qt::WindowCloseButtonHint );

    if (ok)
        qDebug() << value;
}

void MainWindow::test(QString text)
{
    qDebug() << text;
}
