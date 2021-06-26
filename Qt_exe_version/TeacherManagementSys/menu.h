#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"
#include"addinfo.h"
#include "analyze_result.h"
#include <QTableView>
#include <QStandardItemModel>
#include<QComboBox>
#include<QFileDialog>
#include"rangetext.h"
#include"edit.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
   vector<teacherinfo>m_teachers_list0;
   vector<teacherinfo>m_teachers_list1;
   void showinTableview();
   void readfile(string str,int a);

private slots:


    void on_search_clicked();

    void on_add_clicked();

    void on_order_clicked();

    void on_delete_2_clicked();

    void on_Analyze_clicked();

    void on_writeIntoFile_clicked();


    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::menu *ui;

    QStandardItemModel *model;

};

#endif // MENU_H
