#include "functionchoice.h"
#include "ui_functionchoice.h"

functionchoice::functionchoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::functionchoice)
{
    ui->setupUi(this);
}

functionchoice::~functionchoice()
{
    delete ui;
}
