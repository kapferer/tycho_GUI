#include "help6.h"
#include "ui_help6.h"

help6::help6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help6)
{
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help6::~help6()
{
    delete ui;
}
