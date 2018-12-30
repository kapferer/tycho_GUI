#include "help2.h"
#include "ui_help2.h"

help2::help2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help2)
{
    ui->setupUi(this);

    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help2::~help2()
{
    delete ui;
}
