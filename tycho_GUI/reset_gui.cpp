#include "mainwindow.h"
#include "ui_mainwindow.h"


/*!
  Resets the tychoGUI
  */
void MainWindow::reset_gui(){

    initiate_ic_files();

    ui->filename->clear();

    ui->filetype->setCurrentIndex(0);
    ui->initial_conditions->setCurrentIndex(0);
    ui->initial_velocities->setCurrentIndex(0);
    ui->dimension->setCurrentIndex(0);

    ui->res_x->setValue(64);
    ui->res_y->setValue(1);
    ui->res_z->setValue(1);

    ui->extend_x->setText("1");
    ui->extend_y->setText("0");
    ui->extend_z->setText("0");

    ui->ic_density->setDisabled(true);
    ui->ic_temperatur->setDisabled(true);
    ui->ic_velocity->setDisabled(true);
    ui->ic_wind->setDisabled(true);
    ui->ic_obstacle->setDisabled(true);
    ui->ic_marker->setDisabled(true);

    ui->bound_back->setCurrentIndex(0);
    ui->bound_front->setCurrentIndex(0);
    ui->bound_up->setCurrentIndex(0);
    ui->bound_down->setCurrentIndex(0);
    ui->bound_left->setCurrentIndex(0);
    ui->bound_right->setCurrentIndex(0);

    ui->bound_down->setEnabled(true);
    ui->bound_up->setEnabled(true);

    boundary_logic();

    ui->end_time->setText("1");
    ui->output_frequency->setText("0.001");
    ui->restart_frequency->setText("0.01");

    ui->openmp->setText("4");

    ui->cfl->setText("0.3");
    ui->gamma->setText("1.667");
    ui->gasconstant->setText("287.058");

    ui->gravity_off->setChecked(true);
    ui->startified_atmos_off->setChecked(true);
    ui->startified_atmos_on->setDisabled(true);
    ui->startified_atmos_off->setDisabled(true);

    ui->wind_emitter_off->setChecked(true);
    ui->wind_speed->setText("0");
    ui->wind_speed->setDisabled(true);

    ui->obstacle_off->setChecked(true);
    ui->obstacle_density->setText("0");
    ui->obstacle_temp->setText("0");
    ui->obstacle_diff->setText("0");
    ui->obstacle_density->setDisabled(true);
    ui->obstacle_diff->setDisabled(true);
    ui->obstacle_temp->setDisabled(true);

    ui->marker_field_off->setChecked(true);
    ui->marker_density->setText("0");
    ui->marker_density->setDisabled(true);

    ui->viscosity_off->setChecked(true);

    ui->specific_heat_capacity_gas->setText("0");
    ui->specific_heat_capacity_obstacle->setText("0");


    ui->Soundemitter_off->setChecked(true);
    ui->one_pulse_off->setChecked(true);

    soundemitter_logic();
    soundemitter_logic_part2();

}
