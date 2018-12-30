#include "run_error.h"
#include "ui_run_error.h"

/*!
  Opens the reminder window to set the TYCHO executable before starting a local simulation
  */
run_error::run_error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::run_error)
{
    ui->setupUi(this);
}

run_error::~run_error()
{
    delete ui;
}
