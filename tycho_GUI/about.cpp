#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

about::~about()
{
    delete ui;
}
