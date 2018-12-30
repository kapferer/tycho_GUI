#include "help8.h"
#include "ui_help8.h"

help8::help8(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help8)
{
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help8::~help8()
{
    delete ui;
}
