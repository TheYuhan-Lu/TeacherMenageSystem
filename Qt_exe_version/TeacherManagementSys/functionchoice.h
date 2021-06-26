#ifndef FUNCTIONCHOICE_H
#define FUNCTIONCHOICE_H

#include <QWidget>

namespace Ui {
class functionchoice;
}

class functionchoice : public QWidget
{
    Q_OBJECT

public:
    explicit functionchoice(QWidget *parent = nullptr);
    ~functionchoice();

private:
    Ui::functionchoice *ui;
};

#endif // FUNCTIONCHOICE_H
