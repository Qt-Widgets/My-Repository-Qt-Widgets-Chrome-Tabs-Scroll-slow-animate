#include "searchdlg.h"
#include "ui_searchdlg.h"
#include "showfiledlg.h"
#include "previewimagedlg.h"
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QGridLayout>
#include <QMouseEvent>
#include <QMessageBox>

int resIndex=1;
QLabel*lblRes[6];
QStringList fileList;   //filePath: C:/Document/diary/20010101place/title
QStringList diaryList;  //fileName: 20010101place/title

SearchDlg::SearchDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDlg)
{
    ui->setupUi(this);
    this->setWindowTitle("查询");
    lblRes[0]=ui->sLblResult1;
    lblRes[1]=ui->sLblResult2;
    lblRes[2]=ui->sLblResult3;
    lblRes[3]=ui->sLblResult4;
    lblRes[4]=ui->sLblResult5;
    lblRes[5]=ui->sLblResult6;

    ui->sLblResult1->installEventFilter(this);
    ui->sLblResult2->installEventFilter(this);
    ui->sLblResult3->installEventFilter(this);
    ui->sLblResult4->installEventFilter(this);
    ui->sLblResult5->installEventFilter(this);
    ui->sLblResult6->installEventFilter(this);

    QGridLayout*layout=new QGridLayout;
    layout->addWidget(ui->sLblLlcx,0,0,2,8);
    layout->addWidget(ui->sLblRstTitle,2,0,2,8);
    layout->addWidget(ui->sLblResult1,4,1,1,16);
    layout->addWidget(ui->sLblResult2,5,1,1,16);
    layout->addWidget(ui->sLblResult3,6,1,1,16);
    layout->addWidget(ui->sLblResult4,7,1,1,16);
    layout->addWidget(ui->sLblResult5,8,1,1,16);
    layout->addWidget(ui->sLblResult6,9,1,1,16);
    layout->addWidget(ui->sTbtnRstInxLast,10,8,1,1);
    layout->addWidget(ui->sLblRstIndex,10,9,1,1);
    layout->addWidget(ui->sTbtnRstInxNext,10,10,1,1);
    layout->addWidget(ui->sLblSearch,3,18,1,6);
    layout->addWidget(ui->sLblSearchWay,4,18,1,3);
    layout->addWidget(ui->sCboxSearchWay,4,21,1,3);
    layout->addWidget(ui->sLblSearchDate,5,18,1,2);
    layout->addWidget(ui->sDetSearchDate,5,20,1,4);
    layout->addWidget(ui->sLblSearchPlace,6,18,1,2);
    layout->addWidget(ui->sLetSearchPlace,6,20,1,4);
    layout->addWidget(ui->sLblSearchTitle,7,18,1,2);
    layout->addWidget(ui->sLetSearchTitle,7,20,1,4);
    layout->addWidget(ui->sTbtnSearch,8,18,1,2);
    layout->addWidget(ui->sBtnReturn,10,19,1,2);
    setLayout(layout);

    //先显示最近添加的日志
    QString documentsLocation=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
            .append("/tourManager_dairy");
    //QStringList fileList;
    //QStringList diaryList;
    fileList.clear();
    diaryList.clear();


    QDir*dir1=new QDir(documentsLocation);
    QStringList filter1;
    QList<QFileInfo> *fileInfo1=new QList<QFileInfo>(dir1->entryInfoList(filter1));

    for(int i=fileInfo1->size()-1,count=0;i>=0;i--)
    {
        if(fileInfo1->at(i).filePath().endsWith("."))
            continue;
        QDir*dir2=new QDir(fileInfo1->at(i).filePath());
        QStringList filter2;
        QList<QFileInfo> *fileInfo2=new QList<QFileInfo>(dir2->entryInfoList(filter2));
        for(int j=fileInfo2->size()-1;j>=0;j--)
        {
            if(fileInfo2->at(j).filePath().endsWith("."))
                continue;
            fileList.append(fileInfo2->at(j).filePath());
            diaryList.append(fileList.at(count).mid(documentsLocation.size()+1));
            count++;
        }
        if(count>=6)
            break;
    }

    for(int i=0;(i<diaryList.size())&&(i<6);i++)
    {
        lblRes[i]->setText(diaryList.at(i));
    }
    resIndex=1;
    ui->sLblRstIndex->setText(tr("%1/%2").arg(resIndex).arg((diaryList.size()-1)/6+1));
}


SearchDlg::~SearchDlg()
{
    delete ui;
}


void SearchDlg::on_sTbtnSearch_clicked()
{
    resIndex=1;
    //QLabel*lblRes[6];
    //lblRes[0]=ui->sLblResult1;
    //lblRes[1]=ui->sLblResult2;
    //lblRes[2]=ui->sLblResult3;
    //lblRes[3]=ui->sLblResult4;
    //lblRes[4]=ui->sLblResult5;
    //lblRes[5]=ui->sLblResult6;
    QStringList fileList;
    switch(ui->sCboxSearchWay->currentIndex())
    {
    case 0:fileList=search(ui->sDetSearchDate->date().toString(Qt::ISODate));break;
    case 1:fileList=search(ui->sLetSearchPlace->text());break;
    case 2:fileList=search(ui->sLetSearchTitle->text());break;
    default:break;
    }
    //qDebug()<<fileList;
    for(int i=0;i<6;i++)
    {
        i<fileList.size()?lblRes[i]->setText(fileList.at(i)):lblRes[i]->clear();
    }
    QFont tempFont;
    tempFont.setPointSize(16);
    ui->sLblRstTitle->setFont(tempFont);

    ui->sLblRstTitle->setText("查询结果");
    QPalette tempPalette;
    tempPalette.setColor(QPalette::WindowText,QColor(0,85,255));
    ui->sLblRstTitle->setPalette(tempPalette);
    ui->sLblRstIndex->setText(tr("%1/%2").arg(resIndex).arg((diaryList.size()-1)/6+1));

}


QStringList SearchDlg::search(QString searchKey)
{
    QString documentsLocation=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
            .append("/tourManager_dairy");
    //QStringList fileList;
    //QStringList diaryList;
    fileList.clear();
    diaryList.clear();
    QDir*dir1=new QDir(documentsLocation);
    QStringList filter1;
    QList<QFileInfo> *fileInfo1=new QList<QFileInfo>(dir1->entryInfoList(filter1));

    for(int i=fileInfo1->size()-1,count=0;i>=0;i--)
    {
        if(fileInfo1->at(i).filePath().endsWith("."))
            continue;
        QDir*dir2=new QDir(fileInfo1->at(i).filePath());
        QStringList filter2;
        QList<QFileInfo> *fileInfo2=new QList<QFileInfo>(dir2->entryInfoList(filter2));
        for(int j=fileInfo2->size()-1;j>=0;j--)
        {
            if(fileInfo2->at(j).filePath().endsWith("."))
                continue;
            fileList.append(fileInfo2->at(j).filePath());
            if(fileList.last().indexOf(searchKey)!=-1)
            {
                diaryList.append(fileList.last().mid(documentsLocation.size()+1));
                count++;
            }
        }
    }
    return diaryList;
}


void SearchDlg::on_sTbtnRstInxLast_clicked()
{
    if(resIndex<=1)
        return;
    resIndex--;
    //qDebug()<<resIndex;
    int temp;
    for(int i=0;i<6;i++)
    {
        temp=6*(resIndex-1)+i;
        if(temp<diaryList.size())
            lblRes[i]->setText(diaryList.at(temp));
        else
            lblRes[i]->clear();
    }
     ui->sLblRstIndex->setText(tr("%1/%2").arg(resIndex).arg((diaryList.size()-1)/6+1));

}


void SearchDlg::on_sTbtnRstInxNext_clicked()
{
    if(resIndex*6>=diaryList.size())
        return;
    resIndex++;
    int temp;
    for(int i=0;i<6;i++)
    {
        temp=6*(resIndex-1)+i;
        if(temp<diaryList.size())
            lblRes[i]->setText(diaryList.at(temp));
        else
            lblRes[i]->clear();
    }
     ui->sLblRstIndex->setText(tr("%1/%2").arg(resIndex).arg((diaryList.size()-1)/6+1));
}

bool SearchDlg::eventFilter(QObject*obj, QEvent*event)
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        QDir *dir = new QDir;
        for(int i=0;i<6;i++)
        {
            if(obj==lblRes[i])
            {
                QString absFderLocation2=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
                        .append("/tourManager_dairy/").append(lblRes[i]->text());
                if(dir->exists(absFderLocation2))
                {
                    ShowFileDlg*showFileDlg=new ShowFileDlg(lblRes[i]->text(),this);
                    showFileDlg->exec();
                    return true;
                }
                else
                {
                    QMessageBox::warning(this,"waining","The file is not existed!");
                }
                break;
            }
        }
    }
    return QDialog::eventFilter(obj,event);
}


