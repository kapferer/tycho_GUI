#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>

/*!
  Function to prevent wrong initial conditions logic
  */
void MainWindow::ic_logic(){

    if (ic_selector(ui->initial_conditions->currentText()) == "0"){
        ui->ic_density->setDisabled(true);
        ui->ic_temperatur->setDisabled(true);
        ui->ic_velocity->setDisabled(true);
        ui->ic_wind->setDisabled(true);
        ui->ic_obstacle->setDisabled(true);
        ui->ic_marker->setDisabled(true);

        obstacle_logic();
        windemitter_logic();
        marker_logic();
    }


    if (ic_selector(ui->initial_conditions->currentText()) == "1"){
        ui->ic_density->setDisabled(false);
        ui->ic_temperatur->setDisabled(false);
        ui->ic_velocity->setDisabled(false);
        ui->ic_wind->setDisabled(true);
        ui->ic_obstacle->setDisabled(true);
        ui->ic_marker->setDisabled(true);

        if (ui->obstacle_on->isChecked()) ui->ic_obstacle->setEnabled(true);
        if (ui->wind_emitter_on->isChecked()) ui->ic_wind->setEnabled(true);
        if (ui->marker_field_on->isChecked()) ui->ic_marker->setEnabled(true);

    }

    if (ic_selector(ui->initial_conditions->currentText()) == "2"){
        ui->ic_density->setDisabled(true);
        ui->ic_temperatur->setDisabled(true);
        ui->ic_velocity->setDisabled(true);
        ui->ic_wind->setDisabled(true);
        ui->ic_obstacle->setDisabled(false);
        ui->ic_marker->setDisabled(true);

        ui->obstacle_on->setChecked(true);
        ui->obstacle_off->setChecked(false);

        ui->obstacle_density->setDisabled(false);
        ui->obstacle_temp->setDisabled(false);
        ui->obstacle_diff->setDisabled(false);

        ui->obstacle_density->setText("7874");
        ui->obstacle_temp->setText("300");
        ui->obstacle_diff->setText("0.000023");
    }

    if (ic_selector(ui->initial_conditions->currentText()) == "3"){
        ui->ic_density->setDisabled(true);
        ui->ic_temperatur->setDisabled(true);
        ui->ic_velocity->setDisabled(true);
        ui->ic_wind->setDisabled(true);
        ui->ic_obstacle->setDisabled(true);
        ui->ic_marker->setDisabled(true);

        ui->obstacle_on->setChecked(false);
        ui->obstacle_off->setChecked(true);
        ui->obstacle_density->setDisabled(true);
        ui->obstacle_temp->setDisabled(true);
        ui->obstacle_diff->setDisabled(true);
        ui->obstacle_density->setText("0");
        ui->obstacle_temp->setText("0");
        ui->obstacle_diff->setText("0");

        ui->wind_emitter_off->setChecked(true);
        ui->wind_emitter_on->setChecked(false);
        ui->wind_speed->setDisabled(true);
        ui->wind_speed->setText("0");

        ui->marker_field_off->setChecked(true);
        ui->marker_field_on->setChecked(false);
        ui->marker_density->setDisabled(true);
        ui->marker_density->setText("0");

    }

    if (ic_selector(ui->initial_conditions->currentText()) == "4"){
        ui->ic_density->setDisabled(true);
        ui->ic_temperatur->setDisabled(true);
        ui->ic_velocity->setDisabled(true);
        ui->ic_wind->setDisabled(true);
        ui->ic_obstacle->setDisabled(true);
        ui->ic_marker->setDisabled(true);

        ui->obstacle_on->setChecked(false);
        ui->obstacle_off->setChecked(true);

        //set the boundaries periodic
        ui->bound_down->setCurrentIndex(5);
        ui->bound_up->setCurrentIndex(5);
        ui->bound_left->setCurrentIndex(5);
        ui->bound_right->setCurrentIndex(5);
        ui->bound_front->setCurrentIndex(5);
        ui->bound_back->setCurrentIndex(5);

        ui->dimension->setCurrentIndex(1);
        ui->res_x->setValue(128);
        ui->res_y->setValue(128);
        ui->res_z->setValue(1);

        ui->inflow_density->setText("0");
        ui->inflow_velocity->setText("0");
        ui->inflow_temperature->setText("0");

        ui->gravity_off->setChecked(true);
        ui->gravity_on->setChecked(false);

        ui->startified_atmos_off->setChecked(true);
        ui->startified_atmos_on->setChecked(false);

        ui->obstacle_on->setChecked(false);
        ui->obstacle_off->setChecked(true);
        ui->obstacle_density->setDisabled(true);
        ui->obstacle_temp->setDisabled(true);
        ui->obstacle_diff->setDisabled(true);
        ui->obstacle_density->setText("0");
        ui->obstacle_temp->setText("0");
        ui->obstacle_diff->setText("0");

        ui->wind_emitter_off->setChecked(true);
        ui->wind_emitter_on->setChecked(false);
        ui->wind_speed->setDisabled(true);
        ui->wind_speed->setText("0");

        ui->marker_field_off->setChecked(true);
        ui->marker_field_on->setChecked(false);
        ui->marker_density->setDisabled(true);
        ui->marker_density->setText("0");

    }

}

/*!
  Function to make boundary-condition inflow setting possible
  */
void MainWindow::boundary_logic(){

    if ((ui->bound_down->currentIndex() == 4)||
            (ui->bound_up->currentIndex() == 4)||
            (ui->bound_left->currentIndex() == 4)||
            (ui->bound_right->currentIndex() == 4)||
            (ui->bound_front->currentIndex() == 4)||
            (ui->bound_back->currentIndex() == 4))
    {
        ui->inflow_velocity->setDisabled(false);
        ui->inflow_density->setDisabled(false);
        ui->inflow_temperature->setDisabled(false);
        ui->wind_boundary_0->setDisabled(false);
        ui->wind_boundary_1->setDisabled(false);
    }
    else
    {
        ui->inflow_velocity->setDisabled(true);
        ui->inflow_density->setDisabled(true);
        ui->inflow_temperature->setDisabled(true);
        ui->wind_boundary_0->setDisabled(true);
        ui->wind_boundary_1->setDisabled(true);
        ui->wind_boundary_0->setChecked(true);

        ui->inflow_density->setText("1.229");
        ui->inflow_temperature->setText("300");
        ui->inflow_velocity->setText("100");
    }


}

/*!
  Function to set the dimensions and extends
  */
void MainWindow::dimension_logic(){

    if (ui->dimension->currentIndex()==0){
        ui->res_x->setDisabled(false);
        ui->res_y->setDisabled(true);
        ui->res_z->setDisabled(true);

        ui->extend_x->setDisabled(false);
        ui->extend_y->setDisabled(true);
        ui->extend_z->setDisabled(true);

    }
    if (ui->dimension->currentIndex()==1){
        ui->res_x->setDisabled(false);
        ui->res_y->setDisabled(false);
        ui->res_z->setDisabled(true);

        ui->extend_x->setDisabled(false);
        ui->extend_y->setDisabled(false);
        ui->extend_z->setDisabled(true);

    }
    if (ui->dimension->currentIndex()==2){
        ui->res_x->setDisabled(false);
        ui->res_y->setDisabled(false);
        ui->res_z->setDisabled(false);

        ui->extend_x->setDisabled(false);
        ui->extend_y->setDisabled(false);
        ui->extend_z->setDisabled(false);
    }

}

/*!
  Setting the right boundary conditions and stratified atmosphere button logic
  if gravity is enabled
  */
void MainWindow::gravity_logic(){

    if (ui->gravity_on->isChecked()){
        ui->startified_atmos_off->setDisabled(false);
        ui->startified_atmos_on->setDisabled(false);

        ui->bound_down->setCurrentIndex(1);
        ui->bound_up->setCurrentIndex(0);
        ui->bound_down->setDisabled(true);
        ui->bound_up->setDisabled(true);

    }
    if (!ui->gravity_on->isChecked()){
        ui->startified_atmos_off->setDisabled(true);
        ui->startified_atmos_on->setDisabled(true);
        ui->startified_atmos_off->setChecked(true);

        ui->bound_down->setCurrentIndex(0);
        ui->bound_up->setCurrentIndex(0);
        ui->bound_down->setDisabled(false);
        ui->bound_up->setDisabled(false);

    }

}

/*!
  Enbales Wind-emitter input
  */
void MainWindow::windemitter_logic(){

    if (ui->wind_emitter_off->isChecked()){
        ui->wind_speed->setDisabled(true);
        ui->wind_speed->setText("0");
    }
    if (ui->wind_emitter_on->isChecked()) ui->wind_speed->setDisabled(false);

    if (ui->wind_emitter_on->isChecked()) ui->ic_wind->setDisabled(false);
    if (ui->wind_emitter_off->isChecked()){
        ui->ic_wind->setDisabled(true);
        ic_windemitter_file = "dummy";
    }
}

/*!
  Enables obstacles logic
  */

void MainWindow::obstacle_logic(){

    if (ui->obstacle_on->isChecked()){
        ui->obstacle_density->setDisabled(false);
        ui->obstacle_temp->setDisabled(false);
        ui->obstacle_diff->setDisabled(false);

        ui->obstacle_density->setText("7874");
        ui->obstacle_temp->setText("300");
        ui->obstacle_diff->setText("0.000023");

        ui->ic_obstacle->setDisabled(false);

        }

    if (ui->obstacle_off->isChecked()){
        ui->obstacle_density->setDisabled(true);
        ui->obstacle_temp->setDisabled(true);
        ui->obstacle_diff->setDisabled(true);

        ui->obstacle_density->setText("0");
        ui->obstacle_temp->setText("0");
        ui->obstacle_diff->setText("0");

        ui->ic_obstacle->setDisabled(true);

        if (ui->initial_conditions->currentIndex()==2){
            ui->initial_conditions->setCurrentIndex(0);
            ui->ic_obstacle->setDisabled(true);
        }

        ic_obstacle_file = "dummy";
    }


}

/*!
  Enables markerfield logic
  */
void MainWindow::marker_logic(){

    if (ui->marker_field_on->isChecked()){
        ui->marker_density->setDisabled(false);
        ui->marker_density->setText("0.1");
        ui->ic_marker->setDisabled(false);
    }

    if (ui->marker_field_off->isChecked()){
        ui->marker_density->setDisabled(true);
        ui->marker_density->setText("0");
        ui->ic_marker->setDisabled(true);
        ic_marker_file = "dummy";
    }
}

/*!
  Enables soundemitter logic
  */
void MainWindow::soundemitter_logic(){

    if (ui->Soundemitter_on->isChecked()){
        ui->ic_soundemitter->setEnabled(true);
        ui->soundReflexionCoefficient->setEnabled(true);
        ui->soundPressureLevel->setEnabled(true);
        ui->obstacleSoundAbsoption->setEnabled(true);
    }

    if (ui->Soundemitter_off->isChecked()){
         ui->ic_soundemitter->setEnabled(false);
         ic_soundemitter_file = "dummy";
         ui->soundEmitterFrequency->setEnabled(false);
         ui->soundReflexionCoefficient->setEnabled(false);
         ui->soundPressureLevel->setEnabled(false);
         ui->obstacleSoundAbsoption->setEnabled(false);
         ui->soundEmitterFrequency->setText("0");
         ui->soundReflexionCoefficient->setText("0");
         ui->obstacleSoundAbsoption->setText("0");
         ui->soundPressureLevel->setText("0");
    }

    soundemitter_logic_part2();
}

/*!
  Enables soundemitter logic part2
  */
void MainWindow::soundemitter_logic_part2(){

    if (ui->one_pulse_off->isChecked()){
        if (ui->Soundemitter_on->isChecked()) ui->soundEmitterFrequency->setEnabled(true);
        if (ui->Soundemitter_off->isChecked()) ui->soundEmitterFrequency->setEnabled(false);
    }
    if (ui->one_pulse_on->isChecked()){
        ui->soundEmitterFrequency->setEnabled(false);
        ui->soundEmitterFrequency->setText("0");
    }
}


