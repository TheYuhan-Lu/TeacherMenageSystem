#include "menu.h"
#include "ui_menu.h"
#include <QDebug>
#include<QString>

using namespace std;

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
   string a = (QCoreApplication::applicationDirPath()).toStdString();
    readfile(a+"\\teacherdata.txt",0);
    showinTableview();
    QObject::connect( ui->comboBox, SIGNAL(currentTextChanged(QString)),
                         ui->add,  SLOT(on_add_clicked()) );
    QObject::connect( ui->comboBox_2, SIGNAL(currentTextChanged(QString)),
                      ui->search,  SLOT(on_search_clicked()) );
    QObject::connect( ui->lineEdit, SIGNAL(returnPressed()),
                      ui->search,  SLOT(on_search_clicked()) );

}



menu::~menu()
{
    delete ui;
}

void menu::showinTableview()
{

    QStandardItemModel* model = new QStandardItemModel(this);
    model->setColumnCount(8);
    model->setHeaderData(0,Qt::Horizontal, "ID");
    model->setHeaderData(1,Qt::Horizontal, "Name");
    model->setHeaderData(2,Qt::Horizontal, "Unit");
    model->setHeaderData(3,Qt::Horizontal, "Number");
    model->setHeaderData(4,Qt::Horizontal, "Basic Salary");
    model->setHeaderData(5,Qt::Horizontal, "Bonus");
    model->setHeaderData(6,Qt::Horizontal, "Tax");
    model->setHeaderData(7,Qt::Horizontal, "Fund");//设置表头



    //将容器中的成员数据输入到tableview中
    int i =0;
    for(auto it=m_teachers_list0.begin();it!=m_teachers_list0.end();it++)
    {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString((*it).t_id)));
        model->setItem(i, 1, new QStandardItem(QString::fromStdString((*it).t_name)));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString((*it).t_unit)));
        model->setItem(i, 3, new QStandardItem(QString::fromStdString((*it).t_number)));
        model->setItem(i, 4, new QStandardItem(QString::number((*it).t_basic_salary)));
        model->setItem(i, 5, new QStandardItem(QString::number((*it).t_bonus)));
        model->setItem(i, 6, new QStandardItem(QString::number((*it).t_tax)));
        model->setItem(i, 7, new QStandardItem(QString::number((*it).t_fund)));
        this->ui->tableView->setModel(model);
        i++;
    }
}

void menu::readfile(string str,int a)
{
    vector<teacherinfo>m_teachers_list;
    const teacherinfo x;
    char line[256];
    ifstream in(str);//使用绝对路径打开文件
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
    if(a==0)m_teachers_list0=m_teachers_list;
    if(a==1)m_teachers_list1=m_teachers_list;

}
void menu::on_add_clicked()
{
    if (ui->comboBox->currentText()=="Add by typing")
    {
        AddInfo thirdwin;
        thirdwin.show();
        thirdwin.exec();
        string a = (QCoreApplication::applicationDirPath()).toStdString();
        readfile(a+"\\TransientData.txt",1);//手动添加后，再从文件读取信息以更新添加后的数据
        for(auto it = m_teachers_list1.begin();it!=m_teachers_list1.end();it++)
        {
            m_teachers_list0.push_back(*it);//将临时数据添加到总数据中
        }
    }
    else
    {
        QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("open a file."),
                "D:/",
                tr("text file(*.txt )"));
            if (fileName.isEmpty())
            {
                QMessageBox::warning(this, "Warning!", "Failed to open the file!");
            }
            else
            {
                readfile(fileName.toStdString(),1);//把从文件添加的信息存储到临时数据中
                for(auto it = m_teachers_list1.begin();it!=m_teachers_list1.end();it++)
                {
                    m_teachers_list0.push_back(*it);//将临时数据添加到总数据中
                }
            }
    }
    showinTableview();

}

void menu::on_search_clicked()
{
    vector<teacherinfo> rightinformation;
    if (ui->comboBox_2->currentText()=="Name Info")
        {

            int k = 0;
            string info2;
            info2=(this->ui->lineEdit->text()).toStdString();
            int i = 1;
            for (auto it = m_teachers_list0.begin(); it != m_teachers_list0.end(); ++it)
            {
                if ((search((*it).t_name,info2) ) ||( search((*it).t_number, info2) ) || (search((*it).t_unit, info2) )||search((*it).t_id,info2))//进行模糊信息匹配
                {
                    rightinformation.push_back(*it);
                    ++i;
                    k = 1;
                }
            }
            if (k == 0)
            {
                QMessageBox::critical(this, tr("Error"),tr("No imformation"),
                                                            QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗

            }
        }
        else
        {
            RangeText thirdwin;
            thirdwin.show();
            thirdwin.exec();
            string a = (QCoreApplication::applicationDirPath()).toStdString();
            readfile(a+"\\TransientData.txt",1);
            rightinformation=m_teachers_list1;
        }
        QStandardItemModel* model = new QStandardItemModel(this);
        model->setColumnCount(8);
        model->setHeaderData(0,Qt::Horizontal, "ID");
        model->setHeaderData(1,Qt::Horizontal, "Name");
        model->setHeaderData(2,Qt::Horizontal, "Unit");
        model->setHeaderData(3,Qt::Horizontal, "Number");
        model->setHeaderData(4,Qt::Horizontal, "Basic Salary");
        model->setHeaderData(5,Qt::Horizontal, "Bonus");
        model->setHeaderData(6,Qt::Horizontal, "Tax");
        model->setHeaderData(7,Qt::Horizontal, "Fund");//设置表头



        //将容器中的成员数据输入到tableview中
        int i =0;
        for(auto it=rightinformation.begin();it!=rightinformation.end();it++)
        {
            model->setItem(i, 0, new QStandardItem(QString::fromStdString((*it).t_id)));
            model->setItem(i, 1, new QStandardItem(QString::fromStdString((*it).t_name)));
            model->setItem(i, 2, new QStandardItem(QString::fromStdString((*it).t_unit)));
            model->setItem(i, 3, new QStandardItem(QString::fromStdString((*it).t_number)));
            model->setItem(i, 4, new QStandardItem(QString::number((*it).t_basic_salary)));
            model->setItem(i, 5, new QStandardItem(QString::number((*it).t_bonus)));
            model->setItem(i, 6, new QStandardItem(QString::number((*it).t_tax)));
            model->setItem(i, 7, new QStandardItem(QString::number((*it).t_fund)));
            this->ui->tableView->setModel(model);
            i++;
        }
        m_teachers_list1=rightinformation;

}



void menu::on_order_clicked()
{
    int n = m_teachers_list0.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (m_teachers_list0[j] < m_teachers_list0[j + 1])
               swap(m_teachers_list0[j], m_teachers_list0[j + 1]);//冒泡排序
        }
    }
    showinTableview();

}





void menu::on_delete_2_clicked()//将tableview的删除写入文件
{

    if (m_teachers_list1.empty() == 0)
    {
            char k = 0;//通过该值的辅助帮助解决当删除容器中的元素而导致的存在野指针的问题
            for (auto it = m_teachers_list0.begin(); it != m_teachers_list0.end();)
            {
                for (auto it1 = m_teachers_list1.begin(); it1 != m_teachers_list1.end(); ++it1)
                {
                    if (*it == *it1) {
                        it = m_teachers_list0.erase(it);//这里可能要调用其他函数释放删除了之后容器的空间
                        k = 1;
                        break;
                    }
                    else k = 0;
                }
                if (k == 0)it++; //当没进行删除操作时，迭代器继续向下进一位
            }//删除两个容器重合的部分，通过两个迭代器分别遍历两个容器中的元素，找出相同的项，通过m_teachers_list.erase(it)
            QMessageBox::critical(this, tr("Complete"),tr("Complete!"),
                                                        QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗

    }
    else { QMessageBox::critical(this, tr("Error"),tr("Nothing can be delete!!"),
                                 QMessageBox::Save | QMessageBox::Discard,  QMessageBox::Discard);//错误弹窗
    }

}
void menu::on_Analyze_clicked()
{
    Analyze_Result thirdwin;
    thirdwin.show();
    thirdwin.exec();
}
void menu::on_writeIntoFile_clicked()
{
    string a = (QCoreApplication::applicationDirPath()).toStdString();
    ofstream out(a+"\\teacherdata.txt");
    if (out.is_open() && !(m_teachers_list0.empty()))//当文件打开且容器不为空时进行写入操作
    {
        for (auto it = m_teachers_list0.begin(); it != m_teachers_list0.end(); ++it)
        {
            out << *it;
        }
        out.close();
    }
}

void menu::on_pushButton_clicked()
{
    showinTableview();
}


void menu::on_tableView_doubleClicked(const QModelIndex &index)
{
    vector<teacherinfo> rightinformation;
    string info;
    int info1, count=0,count1=0;
    info = (index.data().toString()).toStdString();
    info1 = (index.data().toString()).toInt();
    for (auto it = m_teachers_list0.begin(); it != m_teachers_list0.end(); ++it)
    {
        if ((*it).t_id == info || (*it).t_name == info||(*it).t_unit== info||(*it).t_number== info||(*it).t_basic_salary== info1||(*it).t_bonus== info1||(*it).t_tax== info1||(*it).t_fund== info1)//遍历容器进行信息比对
        {
            rightinformation.push_back(*it);//将点击的信息对应的teacherinfo对象保存到临时文件中
            count1=count;
        }
        ++count;
    }
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
    Edit edit;
    edit.show();
    edit.exec();
    if(edit.close())
    {
        string a = (QCoreApplication::applicationDirPath()).toStdString();
        readfile(a+"\\TransientData.txt",1);
        m_teachers_list0.at(count1)=m_teachers_list1.at(0);
    }

}

