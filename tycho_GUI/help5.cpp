#include "help5.h"
#include "ui_help5.h"

help5::help5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help5)
{
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help5::~help5()
{
    delete ui;
}
