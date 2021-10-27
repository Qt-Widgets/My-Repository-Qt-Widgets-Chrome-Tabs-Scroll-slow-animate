#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QtWidgets>
#include <QFileDialog>

class SubWindow : public QDialog
{
    Q_OBJECT

public:
    SubWindow(QString &header, QString &code, QWidget *mainWindow);
    ~SubWindow();
    void save(QString &fileName, QString &src);

private slots:
    void saveToFile();
private:

    QTextEdit *m_txtCode;
    QTextEdit *m_txtHeader;
    QPushButton *m_btnClose;
    QPushButton *m_btnSave;
    QString m_headerCode;
    QString m_cppCode;
};
#endif // SUBWINDOW_H
