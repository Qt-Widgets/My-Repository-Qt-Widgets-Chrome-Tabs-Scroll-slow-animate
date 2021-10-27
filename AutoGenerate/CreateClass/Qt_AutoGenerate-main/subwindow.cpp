#include "subwindow.h"

SubWindow::SubWindow(QString &header, QString &code, QWidget *mainWindow) : QDialog(mainWindow)
{
    m_cppCode = code;
    m_headerCode = header;
    m_txtHeader = new QTextEdit();
    m_txtHeader->setFont(QFont("Consolas"));
    m_txtHeader->setPlainText(header);
    m_txtHeader->setReadOnly(true);
    //
    m_txtCode = new QTextEdit();
    m_txtCode->setFont(QFont("Consolas"));
    m_txtCode->setPlainText(code);
    m_txtCode->setReadOnly(true);

    QTabWidget *tab = new QTabWidget();
    tab->addTab(m_txtHeader, "*.h");
    tab->addTab(m_txtCode, "*.cpp");
    m_btnClose = new QPushButton("Thoat");
    m_btnSave = new QPushButton("Luu");
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(m_btnSave);
    layout->addWidget(m_btnClose);
    layout->setAlignment(Qt::AlignRight);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(tab);
    lay->addLayout(layout);
    resize(350, 450);
    setLayout(lay);

    connect(m_btnClose, SIGNAL(clicked()), this, SLOT(accept()));
    connect(m_btnSave, SIGNAL(clicked(bool)), this, SLOT(saveToFile()));
}

SubWindow::~SubWindow()
{

}

void SubWindow::save(QString &fileName, QString &src)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }
    QTextStream stream(&file);
    stream << src;
}

void SubWindow::saveToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Luu file", "", "Header file (*.h);;CPP file (*.cpp)");
    if (fileName.isEmpty())
        return;
    else
    {
        int dot = fileName.lastIndexOf('.');
        int len = fileName.length();
        QString tail = fileName.right(len - dot - 1);
        if(tail == "h")
        {
            save(fileName, m_headerCode);
            fileName.replace(dot+1, len - dot, "cpp");
            save(fileName, m_cppCode);
        }
        else
        {
            save(fileName, m_cppCode);
            fileName.replace(dot+1, len - dot, "h");
            save(fileName, m_headerCode);
        }
    }
    this->accept();
}
