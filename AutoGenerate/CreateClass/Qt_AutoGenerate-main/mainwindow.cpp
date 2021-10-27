#include "mainwindow.h"

MainWindow::MainWindow()
{
    //group 1
    m_txtClassName = new QLineEdit();
    m_txtInheritClass = new QLineEdit();
    QFormLayout *layout1 = new QFormLayout();
    layout1->addRow("Ten lop", m_txtClassName);
    layout1->addRow("Ten lop ke thua", m_txtInheritClass);
    QGroupBox *grpTop = new QGroupBox("Thong tin lop");
    grpTop->setLayout(layout1);
    //group 2
    m_txtAuth = new QLineEdit();
    m_date = new QDateEdit();
    m_date->setDate(QDate::currentDate());
    m_txtPurpose = new QTextEdit();
    QFormLayout *layout2 = new QFormLayout();
    layout2->addRow("Tac gia", m_txtAuth);
    layout2->addRow("Ngay", m_date);
    layout2->addRow("Muc dich", m_txtPurpose);
    grpMid = new QGroupBox("Them chu thich");
    grpMid->setCheckable(true);
    grpMid->setLayout(layout2);
    //group button
    m_btnExit = new QPushButton("&Thoat");
    m_btnGenerate = new QPushButton("&Sinh ma");
    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(m_btnExit);
    layout3->addWidget(m_btnGenerate);
    layout3->setAlignment(Qt::AlignRight);
    //
    QVBoxLayout *_mainLayout1 = new QVBoxLayout();
    _mainLayout1->addWidget(grpTop);
    _mainLayout1->addWidget(grpMid);
    _mainLayout1->addLayout(layout3);
    //
    setLayout(_mainLayout1);
    setWindowTitle("Auto generate code");
    resize(300, 350);
    //
    connect(grpMid, SIGNAL(isChecked), grpMid, SLOT(setEnabled(bool)));
    connect(m_btnExit, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(m_btnGenerate, SIGNAL(clicked(bool)), this, SLOT(GenerateCode()));
}

MainWindow::~MainWindow()
{

}

QString MainWindow::GetClassName()
{
    return m_txtClassName->text();
}

void MainWindow::GenerateCode()
{
    if(m_txtClassName->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Class name is empty");
        return;
    }
    QString header, code;
    QString clsName = m_txtClassName->text();
    //.h
    if(grpMid->isChecked())
    {
        header += "/*\n";
        header += "Tac gia: " + m_txtAuth->text() + "\n";
        header += "Ngay tao: " + m_date->date().toString("dd/MM/yyyy") + "\n";
        header += "Muc dich: " + m_txtPurpose->toPlainText() + "\n";
        header += "*/\n\n";
    }
    header += "#ifndef " + clsName.toUpper() + "_H\n";
    header += "#define " + clsName.toUpper() + "_H\n";
    header += "class " + clsName;
    if(!m_txtInheritClass->text().isEmpty())
    {
        header += " : public " + m_txtInheritClass->text();
    }
    header += "\n{\n";
    header += "public:\n";
    header += "\t"+clsName+"()\n";
    header += "\t~"+clsName+"()\n";
    header += "private:\n\n";
    header += "}\n";
    header += "#endif //" + clsName.toUpper() +"_H";
    //.cpp
    code += "#include \""+clsName+".h\"\n\n";
    code += clsName +"::"+clsName+"()";
    code += "\n{\n\n";
    code += "}\n\n";
    code += clsName +"::~"+clsName+"()";
    code += "\n{\n\n";
    code += "}\n";
    SubWindow *subWindow = new SubWindow(header, code, this);
    subWindow->exec();
}
