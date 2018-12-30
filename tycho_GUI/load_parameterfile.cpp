#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <QDebug>


/*!
Saves a parameter-set into a Parameterfile
*/

void MainWindow::openfile()
{
    QString txtfile = QFileDialog::getOpenFileName(this, tr("Open TYCHO Parameterfile"), QString::null);

    ui->filename->setText(txtfile);

    QList<QString> data;
    QString tmp_data;

    QFile file(txtfile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QTextStream in(&file);
        while (!in.atEnd()) {
            tmp_data = in.readLine(0);

            if ((tmp_data.contains("#"))||(tmp_data.mid(0,1) == "")) {
                tmp_data.clear();
            }
            else {
                data.append(tmp_data);
                tmp_data.clear();
            }
        }
    }

    //to debug
    //std::cout << "LÄNGE" << data.size() << "\n";

    if (data.size() > 0 ) set_parameters(data);

    data.clear();

    file.close();
}


/*!
  Set the parameters from the specified parameterfile.
  */
void MainWindow::set_parameters(QList<QString> data)
{
    //to debug

    /*
    QString tmp;

    for (int i=0; i<data.size(); ++i){
        tmp = data[i];
        std::cout << tmp.toUtf8().constData() << " index:" << i << "\n";
        tmp.clear();
    }
    */


    //set fileformat
    ui->filetype->setCurrentIndex(data[0].toInt());
    //set IC generator
    ui->initial_conditions->setCurrentIndex(data[1].toInt());
    //set IC files
    ic_density_file = data[2];
    //if file given, make the loading buttons active
    if (data[2]!="dummy") ui->ic_density->setEnabled(true);
    ic_temperature_file = data[3];
    //if file given, make the loading buttons active
    if (data[3]!="dummy") ui->ic_temperatur->setEnabled(true);
    ic_velocity_file = data[4];
    //if file given, make the loading buttons active
    if (data[4]!="dummy") ui->ic_velocity->setEnabled(true);
    ic_windemitter_file = data[5];
    //if file given, make the loading buttons active
    if (data[5]!="dummy") ui->ic_wind->setEnabled(true);
    ic_obstacle_file = data[6];
    //if file given, make the loading buttons active
    if (data[6]!="dummy") ui->ic_obstacle->setEnabled(true);
    ic_soundemitter_file = data[7];
    //if file given, make the loading buttons active
    if (data[7]!="dummy") ui->ic_soundemitter->setEnabled(true);
    ic_marker_file = data[8];
    //if file given, make the loading buttons active
    if (data[8]!="dummy") ui->ic_marker->setEnabled(true);
    //set initial velocities
    ui->initial_velocities->setCurrentIndex(data[9].toInt());
    //output_directory
    output_directory = data[10];
    ui->output_path_line->setText(output_directory);
    //stratified atmosphere
    if (data[11]=="1"){
        ui->startified_atmos_on->setChecked(true);
        ui->startified_atmos_off->setChecked(false);
    }
    if (data[11]=="0"){
        ui->startified_atmos_on->setChecked(false);
        ui->startified_atmos_off->setChecked(true);
    }
    //set Resolution
    ui->res_x->setValue(data[12].toInt());
    ui->res_y->setValue(data[13].toInt());
    ui->res_z->setValue(data[14].toInt());
    //set Dimension
    ui->dimension->setCurrentIndex(data[15].toInt()-1);
    //set physical extend
    ui->extend_x->setText(data[16]);
    ui->extend_y->setText(data[17]);
    ui->extend_z->setText(data[18]);
    //set boundary conditions
    ui->bound_down->setCurrentIndex(data[19].toInt());
    ui->bound_up->setCurrentIndex(data[20].toInt());
    ui->bound_left->setCurrentIndex(data[21].toInt());
    ui->bound_right->setCurrentIndex(data[22].toInt());
    ui->bound_front->setCurrentIndex(data[23].toInt());
    ui->bound_back->setCurrentIndex(data[24].toInt());
    //set inflow conditions
    ui->inflow_velocity->setText(data[25]);
    ui->inflow_density->setText(data[27]);
    ui->inflow_temperature->setText(data[28]);
    if (data[28]=="1"){
        ui->wind_boundary_1 ->setChecked(true);
        ui->wind_boundary_0 ->setChecked(false);
    }
    if (data[28]=="2"){
        ui->wind_boundary_1->setChecked(false);
        ui->wind_boundary_0->setChecked(true);
    }
    //Timing
    ui->end_time->setText(data[29]);
    ui->output_frequency->setText(data[30]);
    ui->restart_frequency->setText(data[31]);
    //CFL
    ui->cfl->setText(data[32]);
    //Gravity
    if (data[33]=="1"){
        ui->gravity_on->setChecked(true);
        ui->gravity_off->setChecked(false);
    }
    if (data[33]=="0"){
        ui->gravity_off->setChecked(true);
        ui->gravity_on->setChecked(false);
    }
    //Gasconstant
    ui->gasconstant->setText(data[34]);
    //Gammafactor
    ui->gamma->setText(data[35]);
    //Windemitters
    if (data[36]=="1"){
        ui->wind_emitter_on->setChecked(true);
        ui->wind_emitter_off->setChecked(false);
        ui->wind_speed->setEnabled(true);
    }
    if (data[36]=="0"){
        ui->wind_emitter_on->setChecked(false);
        ui->wind_emitter_off->setChecked(true);
    }
    //wind-speed
    ui->wind_speed->setText(data[37]);
    //OpenMP Threads
    ui->openmp->setText(data[38]);
    //obstacles
    if (data[39]=="1"){
        ui->obstacle_on->setChecked(true);
        ui->obstacle_off->setChecked(false);
    }
    if (data[39]=="0"){
        ui->obstacle_on->setChecked(false);
        ui->obstacle_off->setChecked(true);
    }
    //obstacle dens
    ui->obstacle_density->setText(data[40]);
    //obstacle temperature
    ui->obstacle_temp->setText(data[41]);
    //obstacle diffusion
    ui->obstacle_diff->setText(data[42]);
    //specific heat capacity gas
    ui->specific_heat_capacity_gas->setText(data[43]);
    //specific_heat capacity obstacle
    ui->specific_heat_capacity_obstacle->setText(data[44]);
    //Markerfield
    if (data[45]=="1"){
        ui->marker_field_on->setChecked(true);
        ui->marker_field_off->setChecked(false);
    }
    if (data[45]=="0"){
        ui->marker_field_on->setChecked(false);
        ui->marker_field_off->setChecked(true);
    }
    //markerfield density
    ui->marker_density->setText(data[45]);
    //gas viscosity
    if (data[47]=="1"){
        ui->viscosity_on->setChecked(true);
        ui->viscosity_off->setChecked(false);
    }
    if (data[47]=="0"){
        ui->viscosity_on->setChecked(false);
        ui->viscosity_off->setChecked(true);
    }
    //sound emitter
    if (data[48]=="1"){
        ui->Soundemitter_on->setChecked(true);
        ui->Soundemitter_off->setChecked(false);
    }
    if (data[48]=="0"){
        ui->Soundemitter_on->setChecked(false);
        ui->Soundemitter_off->setChecked(true);
    }

    //soundPressureLevel
    ui->soundPressureLevel->setText(data[49]);

    //sound emitter
    if (data[50]=="1"){
        ui->one_pulse_on->setChecked(true);
        ui->one_pulse_off->setChecked(false);
    }
    if (data[50]=="0"){
        ui->one_pulse_on->setChecked(false);
        ui->one_pulse_off->setChecked(true);
    }

    ui->soundEmitterFrequency->setText(data[51]);

    ui->soundReflexionCoefficient->setText(data[52]);

    ui->obstacleSoundAbsoption->setText(data[53]);

    soundemitter_logic();
    soundemitter_logic_part2();

}

