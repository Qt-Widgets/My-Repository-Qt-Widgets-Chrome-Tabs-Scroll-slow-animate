#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void initEditDialog(QInputDialog &dialog, const QString &title, const QString &lable_text, const QString text = "");

    void on_ptn_default_clicked();

    void on_ptn_new_clicked();

    void on_ptn_hasparent_clicked();

    void on_ptn_noparent_clicked();

    void test(QString text);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
