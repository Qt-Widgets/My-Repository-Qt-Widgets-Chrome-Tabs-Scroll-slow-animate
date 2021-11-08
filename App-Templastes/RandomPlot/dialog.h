#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QGraphicsScene>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:   
    QString *pointType;
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    //void plotPoint(QGraphicsScene *scene);
    void plot();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QTimer *timer;


};

#endif // DIALOG_H
