#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    //保存图片成员初始化
    //buttonPicture = new QPixmap();
    //pressPicture = new QPixmap();
    //releasePicture = new QPixmap();

    //关闭按钮的默认显示
    this -> setFlat(true);
}


MyButton::~MyButton()
{

}


void MyButton::setButtonPicture(QString path)
{
    buttonPicture = new QPixmap(path);

    this->setIcon(QIcon(*buttonPicture));
}

void MyButton::setPressPicture(QString path)
{
    pressPicture = new QPixmap(path);
}


void MyButton::set_X_Y_width_height(int x, int y, int width, int height)
{
    this -> setIconSize(QSize(width, height));
    this -> setGeometry(x, y, width, height);
}

void MyButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    //null
}

void MyButton::mousePressEvent (QMouseEvent *event)
{
    //pressPicture=new QPixmap("C:/Users/dell/Pictures/test01.jpg");
    this->setIcon(QIcon(*pressPicture));
    //this->show();
}

void MyButton::mouseMoveEvent(QMouseEvent *event)
{

}


void MyButton::mouseReleaseEvent (QMouseEvent *event)
{
    //this -> setIcon(QIcon(*releasePicture));
    this->setIcon(QIcon(*buttonPicture));
    //this->show();
    emit clicked();
}


