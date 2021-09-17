#include "mainsite.h"
#include "ui_mainsite.h"
#include "addfiledlg.h"
#include "searchdlg.h"
#include "usemapdlg.h"
#include "mybutton.h"
#include <QPixmap>
#include <QDebug>
#include <QGridLayout>

MainSite::MainSite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainSite)
{
    ui->setupUi(this);
    this->setWindowTitle("首页");
    MyButton*mBtnAdd=new MyButton(this);
    MyButton*mBtnSch=new MyButton(this);
    MyButton*mBtnMap=new MyButton(this);

    connect(mBtnAdd,SIGNAL(clicked()),this,SLOT(on_mBtnAdd_clicked()));
    connect(mBtnSch,SIGNAL(clicked()),this,SLOT(on_mBtnSch_clicked()));
    connect(mBtnMap,SIGNAL(clicked()),this,SLOT(on_mBtnMap_clicked()));

    mBtnAdd->setButtonPicture(":/buttons/Image/add_1.png");
    mBtnAdd->setPressPicture(":/buttons/Image/add_2.png");
    mBtnSch->setButtonPicture(":/buttons/Image/search_1.png");
    mBtnSch->setPressPicture(":/buttons/Image/search_2.png");
    mBtnMap->setButtonPicture(":/buttons/Image/map_1.png");
    mBtnMap->setPressPicture(":/buttons/Image/map_2.png");

    int x=this->size().width()/3;
    int y=this->size().height()/3;

    mBtnAdd->set_X_Y_width_height(0,0,x,y);
    mBtnSch->set_X_Y_width_height(0,0,x,y);
    mBtnMap->set_X_Y_width_height(0,0,x,y);

    QGridLayout*layout=new QGridLayout(this);
    layout->addWidget(ui->mLblTitle,0,0,1,4);
    layout->addWidget(mBtnAdd,1,0,2,2);
    layout->addWidget(mBtnSch,1,2,2,2);
    layout->addWidget(mBtnMap,3,1,2,2);
    setLayout(layout);





}

MainSite::~MainSite()
{
    delete ui;
}

void MainSite::on_mBtnAdd_clicked()
{
    AddFileDlg*addfileDlg=new AddFileDlg(this);
    this->hide();
    addfileDlg->exec();
    this->show();
}

void MainSite::on_mBtnSch_clicked()
{
    SearchDlg*searchDlg=new SearchDlg(this);
    this->hide();
    searchDlg->exec();
    qDebug()<<"123";
    this->show();
}

void MainSite::on_mBtnMap_clicked()
{
    UseMapDlg*useMapDlg=new UseMapDlg(this);
    this->hide();
    useMapDlg->exec();
    this->show();
}
