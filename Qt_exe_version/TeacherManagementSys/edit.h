#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include"Teacherinfo.h"

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();
    vector<teacherinfo> a;


private slots:
    void on_pushButton_clicked();

private:
    Ui::Edit *ui;
};

#endif // EDIT_H
