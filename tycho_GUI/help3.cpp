#include "help3.h"
#include "ui_help3.h"

help3::help3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help3)
{
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help3::~help3()
{
    delete ui;
}
