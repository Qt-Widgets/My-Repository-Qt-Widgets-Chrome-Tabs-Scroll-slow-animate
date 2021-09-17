#include "usemapdlg.h"
#include "ui_usemapdlg.h"

UseMapDlg::UseMapDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseMapDlg)
{
    ui->setupUi(this);
}

UseMapDlg::~UseMapDlg()
{
    delete ui;
}
