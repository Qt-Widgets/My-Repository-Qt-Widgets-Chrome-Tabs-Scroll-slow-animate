#ifndef MAINSITE_H
#define MAINSITE_H

#include <QDialog>

namespace Ui {
class MainSite;
}

class MainSite : public QDialog
{
    Q_OBJECT

public:
    explicit MainSite(QWidget *parent = 0);
    ~MainSite();

private slots:
    void on_mBtnAdd_clicked();

    void on_mBtnSch_clicked();

    void on_mBtnMap_clicked();

private:
    Ui::MainSite *ui;
};

#endif // MAINSITE_H
