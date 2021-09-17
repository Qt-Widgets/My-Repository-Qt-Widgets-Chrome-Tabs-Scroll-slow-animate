#include "previewimagedlg.h"
#include "ui_previewimagedlg.h"
#include <QGridLayout>

PreviewImageDlg::PreviewImageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewImageDlg)
{
    ui->setupUi(this);
}

int imageIndex=0;
QStringList wpImageileNames;
PreviewImageDlg::PreviewImageDlg(QStringList fileNames,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewImageDlg)
{
    ui->setupUi(this);
    ui->wpLblImage->setScaledContents(true);
    wpImageileNames=fileNames;
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(ui->wpLblImage,0,0,9,13);
    layout->addWidget(ui->wpTbtnLastImage,10,4,1,1);
    layout->addWidget(ui->wpLblIndex,10,5,1,3);
    layout->addWidget(ui->wpTbtnNextImage,10,8,1,1);
    ui->wpLblIndex->setAlignment(Qt::AlignCenter);
    setLayout(layout);
    int fileListSize=wpImageileNames.size();
    if(fileListSize!=0)
    {
        ui->wpLblImage->setPixmap(QPixmap(wpImageileNames[imageIndex]));
        ui->wpLblIndex->setText(tr("%1/%2").arg(imageIndex+1).arg(fileListSize));
    }
    else
        ui->wpLblIndex->setText("未选择图片!");
}

PreviewImageDlg::~PreviewImageDlg()
{
    delete ui;
}

void PreviewImageDlg::on_wpTbtnLastImage_clicked()
{
    int fileListSize=wpImageileNames.size();
    if(fileListSize!=0)
    {
        if(imageIndex-1>-1)
        {
            imageIndex--;
            ui->wpLblImage->setPixmap(QPixmap(wpImageileNames[imageIndex]));
            ui->wpLblIndex->setText(tr("%1/%2").arg(imageIndex+1).arg(fileListSize));
        }
    }
}

void PreviewImageDlg::on_wpTbtnNextImage_clicked()
{
    int fileListSize=wpImageileNames.size();
    if(fileListSize!=0)
    {
        if(imageIndex+1<fileListSize)
        {
            imageIndex++;
            ui->wpLblImage->setPixmap(QPixmap(wpImageileNames[imageIndex]));
            ui->wpLblIndex->setText(tr("%1/%2").arg(imageIndex+1).arg(fileListSize));
        }
    }
}

