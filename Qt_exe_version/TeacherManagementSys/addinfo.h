#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include"Teacherinfo.h"
#include"menu.h"
#include <QMessageBox>


namespace Ui {
class AddInfo;
}

class AddInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = nullptr);
    ~AddInfo();

    vector<teacherinfo>m_teachers_list0;

private slots:

    void on_pushButton_clicked();


private:
    Ui::AddInfo *ui;
};

#endif // ADDINFO_H
