#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <QDebug>


/*!
Save a parameter set into a Parameterfile
*/
void MainWindow::savefile()
{
    QString txtfile = QFileDialog::getSaveFileName(this, tr("Save TYCHO Parameterfile"), ":", tr("Parameterfile (*.txt)"));

    ui->filename->setText(txtfile);

    QList<QString> data;

    QFile file(txtfile);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&file);

        out << "#-------WELCOME TO TYCHOS PARAMETER FILE--------------" << "\n";
        out << "#COMMENTS HAVE TO START WITH #" << "\n";
        out << "#THE ORDER OF PARAMETERS HERE IS MANDATORY" << "\n";
        out << "#IF YOU WISH TO INCLUDE MORE PARAMETERS HERE" << "\n";
        out << "#MAKE SURE TO EDIT START_FILE_READER.C" << "\n";
        out << "#HAVE FUN" << "\n";
        out << "#-----------------------------------------------------" << "\n";

        data.clear();

        out << "\n#TYCHO Files[0], VTK RECTILINEAR_GRID BINARY Files [1], AMIRA MESH [2]";
        out << "\n#or IFRIT uniform scalar data files [3]\n";
        data.append(ui->filetype->currentText());
        out << filetype_selector(data[0]) << "\n";

        out<<  "\n#Make ICs by editing the source file make_ic.c yes [0]";
        out << "\n#Read in initial conditions [1]";
        out << "\n#Only the obstacle distribution is read in [2]";
        out << "\n#A Sod Shock Tube is generated with [3]";
        out << "\n#Kelvin Helmholtz instabilities in 2D [4]";
        out << "\n#Your initial conditions have to be in TYCHO file format!\n";
        data.append(ui->initial_conditions->currentText());
        //std::cout << data[1].toUtf8().constData() << "\n";
        //std::cout << ic_selector(data[1]).toUtf8().constData() << "\n";
        out << ic_selector(data[1]) << "\n";

        out << "\n#Initial Conditions in TYCHO file format";
        out << "\n#Initial density\n";
        data.append(ic_density_file);
        out << data[2] << "\n";
        out << "#Initial temperature\n";
        data.append(ic_temperature_file);
        out << data[3] << "\n";
        out << "#Initial velocity\n";
        data.append(ic_velocity_file);
        out << data[4] << "\n";
        out << "#Initial wind\n";
        data.append(ic_windemitter_file);
        out << data[5] << "\n";
        out << "#Initial obstacle\n";
        data.append(ic_obstacle_file);
        out << data[6] << "\n";
        out << "#Initial soundemitter\n";
        data.append(ic_soundemitter_file);
        out << data[7] << "\n";
        out << "#Initial marker\n";
        data.append(ic_marker_file);
        out << data[8] << "\n";


        out << "\n#Initial velocity field file present [1] or not [0]\n";
        data.append(ui->initial_velocities->currentText());
        if (data[9]=="Initial velocity file exists") out << "1\n";
        if (data[9]=="No initial velocity file") out << "0\n";

        out << "\n#Output directory\n";
        data.append(output_directory);
        out << data[10] << "\n";


        out << "\n#Stratified Atmosphere [1] or constant Atmosphere [0]\n";
        if (ui->startified_atmos_on->isChecked()){
            data.append("1");
        }
        if (ui->startified_atmos_off->isChecked()){
            data.append("0");
        }
        out << data[11] <<"\n";

        out << "\n#Basic properties\n#Resolution\n#x y z\n";
        data.append(ui->res_x->text());
        out << data[12] << "\n";
        data.append(ui->res_y->text());
        out << data[13] << "\n";
        data.append(ui->res_z->text());
        out << data[14] << "\n";

        out << "\n#Dimension\n"        ;
        data.append(ui->dimension->currentText());
        out << data[15] << "\n";

        out << "\n#Length scale\n#meter in x,y,z\n";
        data.append(ui->extend_x->text());
        out << data[16] << "\n";
        data.append(ui->extend_y->text());
        out << data[17] << "\n";
        data.append(ui->extend_z->text());
        out << data[18] << "\n";

        out << "\n#Boundary conditions";
        out << "\n#Boundary conditions";
        out << "\n#0.....zero gradient";
        out << "\n#1.....reflecting";
        out << "\n#2.....small padding";
        out << "\n#3.....outflow boundaries";
        out << "\n#4.....inflow boundaries";
        out << "\n#5.....periodic boundaries";
        out << "\n#Bound.down, bound.up, bound.left, bound.right, bound.front, bound.back";
        out << "\n#Bound.down is set automatically to reflecting in case gravity is";
        out << "\n#switched on\n";
        data.append(ui->bound_down->currentText());
        out << boundary_selector(data[19]) << "\n";
        data.append(ui->bound_up->currentText());
        out << boundary_selector(data[20]) << "\n";
        data.append(ui->bound_left->currentText());
        out << boundary_selector(data[21]) << "\n";
        data.append(ui->bound_right->currentText());
        out << boundary_selector(data[22]) << "\n";
        data.append(ui->bound_front->currentText());
        out << boundary_selector(data[23]) << "\n";
        data.append(ui->bound_back->currentText());
        out << boundary_selector(data[24]) << "\n";

        out << "\n#if inflow boundaries the inflow velocities and density";
        out << "\n#inflow_velocity [m/s], inflow density [kg/m^3] and inflow temperature [K]";
        out << "\n#if you want to start with the constant velocity and direction over the whole";
        out << "\n#computational domain you have to set the last parameter in this section to";
        out << "\n#[1] for everywhere. If you want only inflow from boundaries from the starting";
        out << "\n#you have to set this parameter to [2].\n";
        data.append(ui->inflow_velocity->text());
        out << data[25] << "\n";
        data.append(ui->inflow_density->text());
        out << data[26] << "\n";
        data.append(ui->inflow_temperature->text());
        out << data[27] << "\n";
        if (ui->wind_boundary_0->isChecked()){
            data.append("2");
        }
        if (ui->wind_boundary_1->isChecked()){
            data.append("1");
        }
        out << data[28] << "\n";

        out << "\n#Simulation end-time in minutes\n";
        data.append(ui->end_time->text());
        out << data[29] << "\n";
        out << "#Output frequency in seconds\n";
        data.append(ui->output_frequency->text());
        out << data[30] << "\n";
        out << "#Restart frequency in seconds\n";
        data.append(ui->restart_frequency->text());
        out << data[31] << "\n";

        out << "\n#CFL Number\n";
        data.append(ui->cfl->text());
        out << data[32] << "\n";

        out << "\n#Gravity [on--1] / [off--0]\n";
        if (ui->gravity_off->isChecked()){
            data.append("0");
        }
        if (ui->gravity_on->isChecked()){
            data.append("1");
        }
        out << data[33] <<"\n";

        out << "\n#Gas constant\n";
        data.append(ui->gasconstant->text());
        out << data[34] << "\n";

        out << "\n#Gamma factor\n";
        data.append(ui->gamma->text());
        out << data[35] << "\n";

        out << "\n#Wind-emitters\n";
        if (ui->wind_emitter_on->isChecked()){
            data.append("1");
        }
        if (ui->wind_emitter_off->isChecked()){
            data.append("0");
        }
        out << data[36] << "\n";

        out << "\n#Wind speed [m/s]\n";
        data.append(ui->wind_speed->text());
        out << data[37] << "\n";

        out << "\n#Number of Threads for OpenMP]\n";
        data.append(ui->openmp->text());
        out << data[38] << "\n";

        out << "\n#With obstacle [0--off]/[1--on]\n";
        if (ui->obstacle_off->isChecked()){
            data.append("0");
        }
        if (ui->obstacle_on->isChecked()){
            data.append("1");
        }
        out << data[39] << "\n";

        out << "\n#Obstacle density [kg/m^3]\n";
        data.append(ui->obstacle_density->text());
        out << data[40] << "\n";

        out << "\n#Obstacle temperature [K]\n";
        data.append(ui->obstacle_temp->text());
        out << data[41] << "\n";

        out << "\n#Obstacle Thermal diffusivity [m^2/s]\n";
        data.append(ui->obstacle_diff->text());
        out << data[42] << "\n";

        out << "\n#Specific heat capacity gas [J/kgK]\n";
        data.append(ui->specific_heat_capacity_gas->text());
        out << data[43] << "\n";

        qDebug() << "hallo";

        out << "\n#Specific_heat capacity obstacle [J/kgK]\n";
        data.append(ui->specific_heat_capacity_obstacle->text());
        out << data[44] << "\n";

        out << "\n#A Marker Field is advected with the HYDRO Simulation [0--off]/[1--on]\n";
        if (ui->marker_field_on->isChecked()){
            data.append("1");
        }
        if (ui->marker_field_off->isChecked()){
            data.append("0");
        }
        out << data[45] << "\n";

        out << "\n#Marker density [kg/m^3]\n";
        data.append(ui->marker_density->text());
        out << data[46] << "\n";

        out << "\n#Viscosity of gas [0--off]/[1--on]\n";
        if (ui->viscosity_on->isChecked()){
            data.append("1");
        }
        if (ui->viscosity_off->isChecked()){
            data.append("0");
        }
        out << data[47] << "\n";

        out << "\n#With_sound_emitter [0--off]/[1--on]\n";
        if (ui->Soundemitter_on->isChecked()){
            data.append("1");
        }
        if (ui->Soundemitter_off->isChecked()){
            data.append("0");
        }
        out << data[48] << "\n";

        qDebug() << "hall1";

        out << "\n#Sound Pressure Level dB\n";
        data.append(ui->soundPressureLevel->text());
        out << data[49] << "\n";

        out << "\n#With_one_pulse or periodic[0--off]/[1--on]\n";
        if (ui->one_pulse_on->isChecked()){
            data.append("1");
        }
        if (ui->one_pulse_off->isChecked()){
            data.append("0");
        }
        out << data[50] << "\n";

        out << "\n#Sound Frequency Hz\n";
        data.append(ui->soundEmitterFrequency->text());
        out << data[51] << "\n";

        out << "\n#Sound Reflection on Obstacle coefficient\n";
        data.append(ui->soundReflexionCoefficient->text());
        out << data[52] << "\n";

        out << "\n#Obstacle Absorption Coefficient\n";
        data.append(ui->obstacleSoundAbsoption->text());
        out << data[53] << "\n";

        out << "\n";



        out << "#--------END OF PARAMETERFILE-----------------\n";

    }

    file.close();
}
