#include "help_local_simulation.h"
#include "ui_help_local_simulation.h"

help_local_simulation::help_local_simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_local_simulation)
{
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

help_local_simulation::~help_local_simulation()
{
    delete ui;
}
