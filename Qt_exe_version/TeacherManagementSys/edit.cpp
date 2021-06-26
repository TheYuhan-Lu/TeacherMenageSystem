#include "edit.h"
#include "ui_edit.h"
#include<QMessageBox>

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
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
        a.push_back(new_t);
    }

    ui->ID->setText(QString::fromStdString(a.at(0).t_id)) ;
    ui->Name->setText(QString::fromStdString(a.at(0).t_name));
    ui->Unit->setText(QString::fromStdString(a.at(0).t_unit));
    ui->TeleNumber->setText(QString::fromStdString(a.at(0).t_number)) ;
    ui->BS->setText(QString::number(a.at(0).t_basic_salary)) ;
    ui->Bonus->setText(QString::number(a.at(0).t_bonus)) ;
    ui->Tax->setText(QString::number(a.at(0).t_tax)) ;
    ui->Fund->setText(QString::number(a.at(0).t_fund));

}

Edit::~Edit()
{

    delete ui;
}

void Edit::on_pushButton_clicked()
{
    teacherinfo newitem;//读取输入框内的值并将其赋给teacherinfo类对象
    newitem.t_name = (this->ui->Name->text()).toStdString();
    newitem.t_id=(this->ui->ID->text()).toStdString();
    newitem.t_unit=(this->ui->Unit->text()).toStdString();
    newitem.t_number=(this->ui->TeleNumber->text()).toStdString();
    newitem.t_basic_salary=(this->ui->BS->text()).toInt();
    newitem.t_bonus=(this->ui->Bonus->text()).toInt();
    newitem.t_tax=(this->ui->Tax->text()).toInt();
    newitem.t_fund=(this->ui->Fund->text()).toInt();
    if(newitem.t_name != " "&&newitem.t_id!=" "&&newitem.t_unit!=" "&&newitem.t_number!=" "&& newitem.t_basic_salary !=0&& newitem.t_bonus!=0&&newitem.t_tax!=0&&newitem.t_fund!=0)
    {
        string d = (QCoreApplication::applicationDirPath()).toStdString();
        ofstream out(d+"\\TransientData.txt");
        if (out.is_open() && !(a.empty()))//当文件打开且容器不为空时进行写入操作
        {
            out << newitem;

            out.close();//每添加一个值就对临时文件进行写入操作，令文件保存添加的信息
        }
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),tr("The Information is not completed"),
                               QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗
    }
    this->close();
}

