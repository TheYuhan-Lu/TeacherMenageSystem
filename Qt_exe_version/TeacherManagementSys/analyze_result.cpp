#include "analyze_result.h"
#include "ui_analyze_result.h"

Analyze_Result::Analyze_Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analyze_Result)
{
    ui->setupUi(this);

    const teacherinfo x;
    char line[256];
    string d = (QCoreApplication::applicationDirPath()).toStdString();
    ifstream in(d+"\\teacherdata.txt");//使用绝对路径打开文件
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
}

Analyze_Result::~Analyze_Result()
{
    delete ui;
}

void Analyze_Result::on_pushButton_clicked()
{
    int k = 0;
    string info;
    info=(this->ui->Unitname->text()).toStdString();
    vector<teacherinfo> rightinformation;
    if (info == "all")rightinformation = m_teachers_list;
    else
    {
        for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
        {
            if ((*it).t_unit == info)   //筛选出某个单位的所有信息
            {
                rightinformation.push_back(*it);
                k = 1;
            }
        }
    }
    if(k==0)
    {
        QMessageBox::critical(this, tr("Error"),tr("No imformation"),
                                                    QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗

    }
    else
    {
        string d = (QCoreApplication::applicationDirPath()).toStdString();
        ofstream out(d+"\\TransientData.txt");
        if (out.is_open() && !(rightinformation.empty()))//当文件打开且容器不为空时进行写入操作
        {
            for (auto it = rightinformation.begin(); it !=rightinformation.end(); ++it)
            {
                out << *it;
            }
            out.close();//将符合要求的信息存入临时文件中
        }
    }
    Analyzeresultdisplay thirdwin;
    thirdwin.show();
    thirdwin.exec();

}










