#include "help7.h"
#include "ui_help7.h"

help7::help7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help7)
{
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help7::~help7()
{
    delete ui;
}
