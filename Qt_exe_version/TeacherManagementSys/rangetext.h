#ifndef RANGETEXT_H
#define RANGETEXT_H

#include <QDialog>
#include"Teacherinfo.h"
#include <QMessageBox>

namespace Ui {
class RangeText;
}

class RangeText : public QDialog
{
    Q_OBJECT

public:
    explicit RangeText(QWidget *parent = nullptr);
    ~RangeText();
    vector<teacherinfo>m_teachers_list0;

private slots:
    void on_Finish_clicked();

private:
    Ui::RangeText *ui;
};

#endif // RANGETEXT_H
