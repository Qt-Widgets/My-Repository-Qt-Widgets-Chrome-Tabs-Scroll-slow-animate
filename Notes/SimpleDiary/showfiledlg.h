#ifndef SHOWFILEDLG_H
#define SHOWFILEDLG_H

#include <QDialog>

namespace Ui {
class ShowFileDlg;
}

class ShowFileDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ShowFileDlg(QWidget *parent = 0);
    ShowFileDlg(QString,QWidget *parent = 0);
    ~ShowFileDlg();
    QString folderName;
    QStringList imageFilePaths;

private slots:
    void on_shBtnEdit_clicked();

    void on_shBtnDelete_clicked();

    void on_shBtnSeeImage_clicked();

private:
    Ui::ShowFileDlg *ui;
};

#endif // SHOWFILEDLG_H
