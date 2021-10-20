#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPointer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWizardPage>

#include <QDebug>

class BasePage: public QWizardPage{
    Q_OBJECT
public:
    BasePage(QWidget *parent=nullptr): QWizardPage(parent), m_layout(new QVBoxLayout){
        setLayout(m_layout);
    }
    void setWidget(QWidget * widget){
        if(widget)
            m_layout->insertWidget(0, widget);
    }

    QVBoxLayout *verticalLayout() const{
        return m_layout;
    }
private:
    QVBoxLayout *m_layout;
};

class Wizard: public QWizard{
public:
    Wizard(QWidget *parent=nullptr): QWizard(parent){
        connect(this, &QWizard::currentIdChanged, this, &Wizard::change);
    }
    QWidget *widget() const{
        return m_widget;
    }
    void setWidget(QWidget *widget){
        m_widget = widget;
        change();
    }
private:
    void change(){
        if(BasePage *next_page = qobject_cast<BasePage*>(currentPage())){
            next_page->setWidget(m_widget);
        }
    }
    QPointer<QWidget> m_widget;
};


class FirstPage: public BasePage{
public:
    FirstPage(QWidget *parent=nullptr): BasePage(parent){
        verticalLayout()->addWidget(new QLabel("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id justo vel nibh egestas interdum quis vel massa. Curabitur fringilla dui nibh, in cursus libero luctus et. Nullam hendrerit nunc erat, id tempor augue laoreet vitae."));
        verticalLayout()->addWidget(new QLineEdit);
        verticalLayout()->addWidget(new QLabel("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id justo vel nibh egestas interdum quis vel massa. Curabitur fringilla dui nibh, in cursus libero luctus et. Nullam hendrerit nunc erat, id tempor augue laoreet vitae."));
    }
};

class SecondPage: public BasePage{
public:
    SecondPage(QWidget *parent=nullptr): BasePage(parent){
        verticalLayout()->addWidget(new QLineEdit);
        verticalLayout()->addWidget(new QLabel("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id justo vel nibh egestas interdum quis vel massa. Curabitur fringilla dui nibh, in cursus libero luctus et. Nullam hendrerit nunc erat, id tempor augue laoreet vitae."));
        verticalLayout()->addWidget(new QLineEdit);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wizard wizard;
    wizard.setWidget(new QPushButton("Qt is awesome!!!"));
    wizard.addPage(new FirstPage);
    wizard.addPage(new SecondPage);
    wizard.resize(640, 480);
    wizard.show();
    return a.exec();
}
