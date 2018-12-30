#include "globals.h"
#include "local_simulation.h"
#include "ui_local_simulation.h"

#include <QFileDialog>
#include <QProcess>
#include <QByteArray>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>

/*!
  Here are the connects on local simulations are defined and called
*/
local_simulation::local_simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::local_simulation)
{
    ui->setupUi(this);

    proc = new QProcess(this);
    connect(proc, SIGNAL(readyRead()), this, SLOT(readFromStdout()));

    connect(ui->tycho_exe,SIGNAL(clicked()), this, SLOT(tycho_exectuable()));
    connect(ui->parameterfile, SIGNAL(clicked()), this, SLOT(parameterfile_path()));
    connect(ui->run, SIGNAL(clicked()), this, SLOT(local_simulation_start()));
    connect(ui->restart, SIGNAL(clicked()), this, SLOT(local_simulation_restart()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(local_simulation_stop()));
    connect(ui->savelog, SIGNAL(clicked()), this, SLOT(save_log()));
    connect(ui->reset, SIGNAL(clicked()), this, SLOT(reset_gui()));
    connect(ui->Help, SIGNAL(clicked()), this, SLOT(open_help()));

    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));

    QFile file("config_tycho_gui.ini");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", "No config_tycho_gui.ini File found.");
    }

    QTextStream in(&file);
    QString line;
    QStringList lines;

    while(!in.atEnd()) {
        line = in.readLine();
        lines.append(line);
    }

    file.close();


    //TYCHO exectubale standard directory found in config_tycho_gui.ini File
    tycho_exe = lines.last();
    //Automatically enter TYCHO executable and last saved parameterfile
    ui->tycho_text->setText(tycho_exe);
    ui->parameterfile_text->setText(parameter_file_global);
}

local_simulation::~local_simulation()
{
    delete ui;
}

/*!
  asking for the TYCHO executable
  */
void local_simulation::tycho_exectuable(){

    tycho_exe.clear();

    tycho_exe = QFileDialog::getOpenFileName(this, tr("The TYCHO Executable"), QString::null);

    ui->tycho_text->setText(tycho_exe);

}

/*!
  Asking for the parameterfile
  */
void local_simulation::parameterfile_path(){

    QString parameterfile_QString;

    parameterfile_QString = QFileDialog::getOpenFileName(this, tr("The TYCHO Executable"), QString::null);

    ui->parameterfile_text->setText(parameterfile_QString);

    parameter_file_global=parameterfile_QString;

}

/*!
  Starting a local simulation with given executable and parameterfile
  */
void local_simulation::local_simulation_start(){

    proc->close();

    ui->textBrowser->clear();

    parameterfile.clear();

    parameterfile << parameter_file_global;

    if (tycho_exe.size()==0){
        run_error_gui();
    }
    else
    {
        proc->start(tycho_exe, parameterfile);
    }

}

/*!
  Restarting TYCHO with given parameterfile
  */
void local_simulation::local_simulation_restart(){

    proc->close();

    parameterfile_restart.clear();

    ui->textBrowser->clear();

    parameterfile_restart << parameter_file_global << " restart";

    if (tycho_exe.size()==0){
        run_error_gui();
    }
    else
    {
        proc->start(tycho_exe, parameterfile_restart);
    }

}

/*!
  Stopping a local simulation
  */
void local_simulation::local_simulation_stop(){

    proc->close();

}

/*!
  writes the TYCHO standard out to the textBrowser Widget
  */
void local_simulation::readFromStdout(){

    ui->textBrowser->append(proc->readAll().constData());
}

/*!
  Let you save the output in a text file
  */
void local_simulation::save_log(){

    QString txtfile = QFileDialog::getSaveFileName(this, tr("Save TYCHO Simulation Logfile"), ":", tr("logfile (*.txt)"));

    QFile file(txtfile);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&file);

        out << ui->textBrowser->toPlainText();

    }

}

/*!
  Resets the local simulation gui
  */
void local_simulation::reset_gui(){

    QFile file("config_tycho_gui.ini");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", "No config_tycho_gui.ini File found.");
    }

    //TYCHO exectubale standard directory found in config_tycho_gui.ini File
    QTextStream in(&file);
    QString line;
    QStringList lines;

    while(!in.atEnd()) {
        line = in.readLine();
        lines.append(line);
    }

    file.close();


    //TYCHO exectubale standard directory found in config_tycho_gui.ini File
    tycho_exe = lines.last();
    //Automatically enter TYCHO executable and last saved parameterfile
    ui->tycho_text->setText(tycho_exe);
    ui->parameterfile_text->setText(parameter_file_global);

    parameter_file_global.clear();

    ui->tycho_text->setText(tycho_exe);
    ui->parameterfile_text->setText("");

    ui->textBrowser->clear();

}

/*!
  Reminder to point to TYCHO executable before starting a local simulation
  */
void local_simulation::run_error_gui(){

    pro_run = new run_error;
    pro_run->show();
}

/*!
  Opens a help window for the local simulatio n
  */
void local_simulation::open_help(){

    mylocal_simulation_help = new help_local_simulation;
    mylocal_simulation_help->show();
}

