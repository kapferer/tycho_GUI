#include "help4.h"
#include "ui_help4.h"

help4::help4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help4)
{
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help4::~help4()
{
    delete ui;
}
