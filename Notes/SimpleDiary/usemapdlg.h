#ifndef USEMAPDLG_H
#define USEMAPDLG_H

#include <QDialog>

namespace Ui {
class UseMapDlg;
}

class UseMapDlg : public QDialog
{
    Q_OBJECT

public:
    explicit UseMapDlg(QWidget *parent = 0);
    ~UseMapDlg();

private:
    Ui::UseMapDlg *ui;
};

#endif // USEMAPDLG_H
