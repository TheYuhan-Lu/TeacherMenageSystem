#include "addinfo.h"
#include "ui_addinfo.h"

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo)
{
    ui->setupUi(this);

    vector<teacherinfo>m_teachers_list;


}

AddInfo::~AddInfo()
{
    delete ui;
}





void AddInfo::on_pushButton_clicked()
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
       m_teachers_list0.push_back(newitem);
       string d = (QCoreApplication::applicationDirPath()).toStdString();
       ofstream out(d+"\\TransientData.txt");
       if (out.is_open() && !(m_teachers_list0.empty()))//当文件打开且容器不为空时进行写入操作
       {
           for (auto it = m_teachers_list0.begin(); it != m_teachers_list0.end(); ++it)
           {
               out << *it;
           }
           out.close();//每添加一个值就对临时文件进行写入操作，令文件保存添加的信息
       }

   this->ui->ID->clear();
   this->ui->Name->clear();
   this->ui->Unit->clear();
   this->ui->TeleNumber->clear();
   this->ui->BS->clear();
   this->ui->Bonus->clear();
   this->ui->Tax->clear();
   this->ui->Fund->clear();
   }
   else
   {
       QMessageBox::critical(this, tr("Error"),tr("The Information is not completed"),
                              QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗
   }
}



