#ifndef ANALYZERESULTDISPLAY_H
#define ANALYZERESULTDISPLAY_H

#include <QDialog>
#include"Teacherinfo.h"
#include<QMessageBox>
#include "analyze_result.h"

namespace Ui {
class Analyzeresultdisplay;
}

class Analyzeresultdisplay : public QDialog
{
    Q_OBJECT

public:
    explicit Analyzeresultdisplay(QWidget *parent = nullptr);
    ~Analyzeresultdisplay();
    vector<teacherinfo>m_teachers_list;
    friend class Analyze_Result;
private:
    Ui::Analyzeresultdisplay *ui;
};

#endif // ANALYZERESULTDISPLAY_H
