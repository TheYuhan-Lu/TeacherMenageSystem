#include "analyzeresultdisplay.h"
#include "ui_analyzeresultdisplay.h"
#include<QTabBar>


Analyzeresultdisplay::Analyzeresultdisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analyzeresultdisplay)
{
    ui->setupUi(this);

    const teacherinfo x;
    char line[256];
    string d = (QCoreApplication::applicationDirPath()).toStdString();
    ifstream in(d+"\\TransientData.txt");//使用绝对路径打开文件
    if (!in.is_open())
    {
        QMessageBox::critical(this, tr("Error"),tr("Error opening file"),
                                                    QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗

    }
    while (!in.eof())
    {
        in.getline(line, 100);//逐行读入
        teacherinfo new_t;
        new_t = line;
        if (new_t == x)continue;//将读入的信息用于给teacherinfo对象赋值
        m_teachers_list.push_back(new_t);
    }



    ui->textBrowser->setText(QString::number(averaging(m_teachers_list, 1)));
    ui->textBrowser_2->setText(QString::number(Standard_deviation(m_teachers_list, 1)));
    ui->textBrowser_3->setText(QString::number(averaging(m_teachers_list, 2)));
    ui->textBrowser_4->setText(QString::number(Standard_deviation(m_teachers_list, 2)));
    ui->textBrowser_5->setText(QString::number(averaging(m_teachers_list, 3)));
    ui->textBrowser_6->setText(QString::number(Standard_deviation(m_teachers_list, 3)));
}

Analyzeresultdisplay::~Analyzeresultdisplay()
{
    delete ui;
}
