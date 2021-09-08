#include "showfiledlg.h"
#include "ui_showfiledlg.h"
#include "addfiledlg.h"
#include "previewimagedlg.h"
#include <QDebug>
#include <QGridLayout>
#include <QStandardPaths>
#include <QDir>
#include <QTextCodec>
#include <QMessageBox>

ShowFileDlg::ShowFileDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowFileDlg)
{
    ui->setupUi(this);
}

ShowFileDlg::ShowFileDlg(QString foldName,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowFileDlg)
{
    ui->setupUi(this);
    QGridLayout*layout=new QGridLayout(this);
    QTextCodec::codecForLocale();
    layout->addWidget(ui->shLblTitle,0,0,2,16);
    layout->addWidget(ui->shLblDatePlace,2,0,1,7);
    layout->addWidget(ui->shBtnSeeImage,2,9,1,1);
    layout->addWidget(ui->shTetText,3,1,12,14);
    layout->addWidget(ui->shBtnEdit,15,1,1,1);
    layout->addWidget(ui->shBtnDelete,15,2,1,1);
    layout->addWidget(ui->shBtnReturn,15,14,1,1);
    ui->shTetText->setDisabled(true);
    setLayout(layout);

    folderName=foldName;
    QString absFderLocation=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
            .append("/tourManager_dairy/").append(folderName);
    QString fileName=folderName.mid(folderName.indexOf("/")+1);
    QString filePath=absFderLocation+"/"+fileName+".txt";
    //qDebug()<<"fileName:"<<fileName;
    //qDebug()<<"filePath:"<<filePath;

    QDir*dir2=new QDir(absFderLocation+"/image");
    QStringList filter2;
    QList<QFileInfo> *fileInfo2=new QList<QFileInfo>(dir2->entryInfoList(filter2));
    for(int j=0;j<fileInfo2->size();j++)
    {
        if(!fileInfo2->at(j).filePath().endsWith("."))
            imageFilePaths.append(fileInfo2->at(j).filePath());
    }
    //qDebug()<<"imageFilePaths:"<<imageFilePaths;

    QString date_place=folderName.left(folderName.indexOf("/"));
    QString title=folderName.mid(folderName.indexOf("/")+1);

    //qDebug()<<"date_place:"<<date_place;
    //qDebug()<<"title:"<<title;

    //QFile file(filePath);
    //if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         //return;
    //QString data = file.readAll();

    ui->shLblTitle->setText(title);
    ui->shLblDatePlace->setText(date_place);
    //ui->shTetText->setText(data);

    QFile f(filePath);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return ;
    }
    QTextStream txtInput(&f);
    QString lineStr;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        ui->shTetText->append(lineStr);
    }
    f.close();


}

ShowFileDlg::~ShowFileDlg()
{
    delete ui;
}

void ShowFileDlg::on_shBtnEdit_clicked()
{
    AddFileDlg*addfileDlg=new AddFileDlg(folderName,this);
    addfileDlg->setWindowTitle("编辑日志");
    //this->hide();
    addfileDlg->exec();
    this->close();
}

void ShowFileDlg::on_shBtnDelete_clicked()
{
    QString absFderLocation=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
            .append("/tourManager_dairy/").append(folderName);
    if(AddFileDlg::DeleteDirectory(absFderLocation))
        QMessageBox::information(this,"Delete successful!","Your diary is deleted successfully!");
    else
        QMessageBox::warning(this,"Failed to delete!","Your diary is failed to delete!");
    this->close();
}

void ShowFileDlg::on_shBtnSeeImage_clicked()
{
    PreviewImageDlg*previewImageDlg=new PreviewImageDlg(imageFilePaths,this);
    //this->close();
    previewImageDlg->setWindowTitle("查看相册");
    previewImageDlg->exec();
}
