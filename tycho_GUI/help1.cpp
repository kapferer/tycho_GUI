#include "help1.h"
#include "ui_help1.h"

help1::help1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help1)
{
    ui->setupUi(this);

    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help1::~help1()
{
    delete ui;
}
