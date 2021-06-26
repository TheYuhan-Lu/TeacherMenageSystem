#include "rangetext.h"
#include "ui_rangetext.h"


RangeText::RangeText(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RangeText)
{
    ui->setupUi(this);

    const teacherinfo x;
    char line[256];
    string a = (QCoreApplication::applicationDirPath()).toStdString();
    ifstream in(a+"\\teacherdata.txt");//使用绝对路径打开文件
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
        m_teachers_list0.push_back(new_t);
    }

}

RangeText::~RangeText()
{
    delete ui;
}

void RangeText::on_Finish_clicked()
{
    vector<teacherinfo> rightinformation;
    int a=0, b=0, c=0, d=0, e=0, f=0,k=0;

    a=(this->ui->a->text()).toInt();
    b=(this->ui->b->text()).toInt();
    c=(this->ui->c->text()).toInt();
    d=(this->ui->d->text()).toInt();
    e=(this->ui->e->text()).toInt();
    f=(this->ui->f->text()).toInt();
    if(b==0)b=10000000;
    if(d==0)d=10000000;
    if(f==0)f=10000000;
    for (auto it = m_teachers_list0.begin(); it != m_teachers_list0.end(); ++it)
    {
        if ((((*it).t_sum_should <= b) && ((*it).t_sum_should >= a)) && (((*it).t_sum_exact <= d) && ((*it).t_sum_exact >= c)) && (((*it).t_fund <= f) && ((*it).t_fund >= e)))
        {
            rightinformation.push_back(*it);
            k = 1;
        }
    }
    if (k == 0)
    {
        QMessageBox::critical(this, tr("Error"),tr("No imformation"),
                                                    QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗

    }
    else
    {
        string a = (QCoreApplication::applicationDirPath()).toStdString();
    ofstream out(a+"\\TransientData.txt");
    if (out.is_open() && !(rightinformation.empty()))//当文件打开且容器不为空时进行写入操作
    {
        for (auto it = rightinformation.begin(); it !=rightinformation.end(); ++it)
        {
            out << *it;
        }
        out.close();//将符合要求的信息存入临时文件中
    }
    }
    this->close();
}

