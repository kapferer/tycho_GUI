#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <QDebug>
#include <sstream>
#include <string>
#include <QMessageBox>


/*!
  Loads the ic density file
  */
void MainWindow::ic_density()
{
    QString ic_dens = QFileDialog::getOpenFileName(this, tr("The initial density file"), QString::null);
    if (ic_dens.size()==0) ic_dens = "dummy";
    ic_density_file = ic_dens;

    //to read out the size of the computational domain
    if (ic_dens.size()>0){
        check_resolution(ic_dens);
    }
}

/*!
  Loads the ic temperature file
  */
void MainWindow::ic_temperature()
{

    QString ic_temp = QFileDialog::getOpenFileName(this, tr("The initial temperature file"), QString::null);

    if (ic_temp.size()==0) ic_temp ="dummy";

    ic_temperature_file = ic_temp;

    //to read out the size of the computational domain
    if (ic_temp.size()>0){
        check_resolution(ic_temp);
    }
}

/*!
  Loads the ic velocity file
  */
void MainWindow::ic_velocity()
{

    QString ic_velo = QFileDialog::getOpenFileName(this, tr("The initial velocity file"), QString::null);

    if (ic_velo.size()==0) ic_velo = "dummy";

    ic_velocity_file = ic_velo;

    //to read out the size of the computational domain
    if (ic_velo.size()>0){
        check_resolution(ic_velo);
    }
}

/*!
  Loads the ic wind file
  */
void MainWindow::ic_wind()
{

    QString ic_wind = QFileDialog::getOpenFileName(this, tr("The initial wind-emitter file"), QString::null);

    if (ic_wind.size()==0) ic_wind = "dummy";

    ic_windemitter_file = ic_wind;

    //to read out the size of the computational domain
    if (ic_wind.size()>0){
        check_resolution(ic_wind);
    }
}

/*!
  Loads the ic obstacles file
  */
void MainWindow::ic_obstacle()
{

    QString ic_obstacle = QFileDialog::getOpenFileName(this, tr("The initial obstacles-distribution file"), QString::null);

    if (ic_obstacle.size()==0) ic_obstacle = "dummy";

    ic_obstacle_file = ic_obstacle;

    //to read out the size of the computational domain
    if (ic_obstacle.size()>0){
        check_resolution(ic_obstacle);
    }
}

/*!
  Loads the ic marker file
  */
void MainWindow::ic_marker()
{

    QString ic_marker = QFileDialog::getOpenFileName(this, tr("The initial marker-field distribution file"), QString::null);

    if (ic_marker.size()==0) ic_marker = "dummy";

    ic_marker_file = ic_marker;

    //to read out the size of the computational domain
    if (ic_marker.size()>0){
        check_resolution(ic_marker);
    }
}

/*!
  Loads the ic marker file
  */
void MainWindow::ic_soundemitter()
{

    QString ic_soundemitter = QFileDialog::getOpenFileName(this, tr("The initial soundemitter file"), QString::null);

    if (ic_soundemitter.size()==0) ic_soundemitter = "dummy";

    ic_soundemitter_file = ic_soundemitter;

    //to read out the size of the computational domain
    if (ic_soundemitter.size()>0){
        check_resolution(ic_soundemitter);
    }
}


/*!
  Loads the output file path
  */
void MainWindow::output_path()
{

    QString output_path = QFileDialog::getExistingDirectory(this, tr("The output directory"), QString::null);

    if (output_path.size()==0) output_path = "/tmp/";

    output_path = output_path.append("/");

    output_directory = output_path;

    ui->output_path_line->setText(output_directory);
}

/*!
  resets the initial conditions files
  */
void MainWindow::initiate_ic_files(){

    ic_density_file = "dummy";
    ic_temperature_file = "dummy";
    ic_velocity_file = "dummy";
    ic_windemitter_file = "dummy";
    ic_obstacle_file = "dummy";
    ic_soundemitter_file = "dummy";
    ic_marker_file = "dummy";
    output_directory= "/tmp/";

    ui->output_path_line->setText(output_directory);
}

/*!
 *Checks the resolution of the IC file and make some plausibility checks
 */
void MainWindow::check_resolution(QString filename){

    int read_x_res = 0;
    int read_y_res = 0;
    int read_z_res = 0;

    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int i = 0;
    while(i<4)
    {
        QString line = in.readLine();
        std::istringstream iss(line.toStdString());
        std::string name;
        if (i == 1) iss >> name >> read_x_res;
        if (i == 2) iss >> name >> read_y_res;
        if (i == 3) iss >> name >> read_z_res;
        i++;
    }

    if (resolution_is_yet_determined){

        if ((read_x_res != MainWindow::x_res)||
                (read_y_res != MainWindow::y_res)||
                (read_z_res != MainWindow::z_res)){


            ui->res_x->setValue(0);
            ui->res_y->setValue(0);
            ui->res_z->setValue(0);

            QMessageBox msgBox;
            msgBox.setText("Attention!");
            msgBox.setInformativeText("The file has a different resolution as a already loaded, plaese check the IC files.");
            msgBox.exec();
        }
    }

    MainWindow::x_res = read_x_res;
    MainWindow::y_res = read_y_res;
    MainWindow::z_res = read_z_res;

    ui->res_x->setValue(read_x_res);
    ui->res_y->setValue(read_y_res);
    ui->res_z->setValue(read_z_res);

    if ((read_y_res==1)&&(read_z_res==1)) ui->dimension->setCurrentIndex(0);
    if (read_z_res ==1) ui->dimension->setCurrentIndex(1);
    if ((read_y_res!=1)&&(read_z_res!=1)) ui->dimension->setCurrentIndex(2);

    resolution_is_yet_determined = true;

}
