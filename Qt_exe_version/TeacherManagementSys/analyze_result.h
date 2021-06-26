#ifndef ANALYZE_RESULT_H
#define ANALYZE_RESULT_H

#include <QDialog>
#include<analyzeresultdisplay.h>

namespace Ui {
class Analyze_Result;
}

class Analyze_Result : public QDialog
{
    Q_OBJECT

public:
    explicit Analyze_Result(QWidget *parent = nullptr);
    ~Analyze_Result();
    vector<teacherinfo>m_teachers_list;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Analyze_Result *ui;
};

#endif // ANALYZE_RESULT_H
