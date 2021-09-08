#ifndef ADDFILEDLG_H
#define ADDFILEDLG_H
#define ADD_MODE 1
#define EDIT_MODE 2

#include <QDialog>

namespace Ui {
class AddFileDlg;
}

class AddFileDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddFileDlg(QWidget *parent = 0);
    explicit AddFileDlg(QString folderPaths,QWidget *parent=0);
    ~AddFileDlg();
    QStringList imageFileNames;
    bool saveFile(QString);
    static bool DeleteDirectory(const QString &path);
    int mode;

private slots:
    void on_wBtnAddImage_clicked();

    void on_wBtnPreviewImage_clicked();

    void on_wBtnDelete_clicked();

    void on_wBtnSubmit_clicked();

private:
    Ui::AddFileDlg *ui;
};

#endif // ADDFILEDLG_H
