#ifndef PREVIEWIMAGEDLG_H
#define PREVIEWIMAGEDLG_H

#include <QDialog>

namespace Ui {
class PreviewImageDlg;
}

class PreviewImageDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewImageDlg(QWidget *parent = 0);
    PreviewImageDlg(QStringList,QWidget *parent = 0);
    ~PreviewImageDlg();

private slots:
    void on_wpTbtnLastImage_clicked();

    void on_wpTbtnNextImage_clicked();


private:
    Ui::PreviewImageDlg *ui;
};

#endif // PREVIEWIMAGEDLG_H
