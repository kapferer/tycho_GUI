#include "configure_path.h"
#include "ui_configure_path.h"
#include <QFileDialog>
#include <stdio.h>


configure_path::configure_path(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configure_path)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(tycho_exectuable_config_ini()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));


}

configure_path::~configure_path()
{
    delete ui;
}


void configure_path::tycho_exectuable_config_ini(){

    QString tycho_exe_config;

    tycho_exe_config = QFileDialog::getOpenFileName(this, tr("The TYCHO Executable"), QString::null);

    //write the new path of the TYCHO executable in the confif_tycho_gui.ini File.
    FILE *fd;

    fd = fopen("config_tycho_gui.ini", "w");
    fprintf(fd,"#THIS IS A TYCHO GUI CONFIG FILE\n#WHICH STORES THE FULL PATH OF THE\n#TYCHO SIMULATION EXECUTABLE\n""");
    fprintf(fd,"%s", tycho_exe_config.toStdString().c_str());

    fclose(fd);

    ui->lineEdit->setText(tycho_exe_config);


}
