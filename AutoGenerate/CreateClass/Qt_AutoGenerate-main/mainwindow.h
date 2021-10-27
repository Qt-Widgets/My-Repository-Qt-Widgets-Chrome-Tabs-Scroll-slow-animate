#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <subwindow.h>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    QString GetClassName();

private slots:
    void GenerateCode();

private:
    QLineEdit *m_txtClassName;
    QLineEdit *m_txtInheritClass;
    QLineEdit *m_txtAuth;
    QTextEdit *m_txtPurpose;
    QDateEdit *m_date;
    QPushButton *m_btnExit;
    QPushButton *m_btnGenerate;
    QGroupBox *grpMid;
};
#endif // MAINWINDOW_H
