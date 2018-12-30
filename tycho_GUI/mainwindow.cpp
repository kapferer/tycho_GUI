#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help1.h"
#include "local_simulation.h"
#include "configure_path.h"


#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QScrollArea>
#include <iostream>

/*!
  Here are the connects on the mainform defined and called
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //scrollbars
    QScrollArea *const scroll(new QScrollArea);
    scroll->setWidget(ui->frame);
    setCentralWidget(scroll);


    //menus
    connect(ui->actionQuit_2, SIGNAL(triggered()), this, SLOT(quit()));
    connect(ui->actionOpen_2, SIGNAL(triggered()), this, SLOT(openfile()));
    connect(ui->actionSave_Parameterfile, SIGNAL(triggered()), this, SLOT(savefile()));
    connect(ui->actionLocal_Simulation, SIGNAL(triggered()), this, SLOT(open_local_simulation()));
    connect(ui->actionReset, SIGNAL(triggered()), this, SLOT(reset_gui()));
    connect(ui->actionTycho_GUI, SIGNAL(triggered()), this, SLOT(open_about()));
    connect(ui->actionConfigure_Path, SIGNAL(triggered()), this, SLOT(open_configure_path()));


    //helpbuttons
    connect(ui->help_1, SIGNAL(clicked()), this, SLOT(open_help1()));
    connect(ui->help_2, SIGNAL(clicked()), this, SLOT(open_help2()));
    connect(ui->help_3, SIGNAL(clicked()), this, SLOT(open_help3()));
    connect(ui->help_4, SIGNAL(clicked()), this, SLOT(open_help4()));
    connect(ui->help_5, SIGNAL(clicked()), this, SLOT(open_help5()));
    connect(ui->help_6, SIGNAL(clicked()), this, SLOT(open_help6()));
    connect(ui->help_7, SIGNAL(clicked()), this, SLOT(open_help7()));
    connect(ui->help_8, SIGNAL(clicked()), this, SLOT(open_help8()));


    //for the IC files and the output directory
    initiate_ic_files();
    connect(ui->ic_density, SIGNAL(clicked()), this, SLOT(ic_density()));
    connect(ui->ic_temperatur, SIGNAL(clicked()), this, SLOT(ic_temperature()));
    connect(ui->ic_velocity, SIGNAL(clicked()), this, SLOT(ic_velocity()));
    connect(ui->ic_wind, SIGNAL(clicked()), this, SLOT(ic_wind()));
    connect(ui->ic_obstacle, SIGNAL(clicked()), this, SLOT(ic_obstacle()));
    connect(ui->ic_marker, SIGNAL(clicked()), this, SLOT(ic_marker()));
    connect(ui->ic_soundemitter, SIGNAL(clicked()), this, SLOT(ic_soundemitter()));
    connect(ui->output_path, SIGNAL(clicked()), this, SLOT(output_path()));

    //the save, open and reset button on the mainwindow
    connect(ui->save, SIGNAL(clicked()), this, SLOT(savefile()));
    connect(ui->open, SIGNAL(clicked()), this, SLOT(openfile()));
    connect(ui->reset, SIGNAL(clicked()), this, SLOT(reset_gui()));

    //section to prevent wrong usage
    ic_logic();
    connect(ui->initial_conditions, SIGNAL(currentIndexChanged(int)), this, SLOT(ic_logic()));

    //the inflow settings are disabled by default
    ui->inflow_velocity->setDisabled(true);
    ui->inflow_density->setDisabled(true);
    ui->inflow_temperature->setDisabled(true);
    ui->wind_boundary_0->setDisabled(true);
    ui->wind_boundary_1->setDisabled(true);
    connect(ui->bound_down,SIGNAL(currentIndexChanged(int)), this, SLOT(boundary_logic()));
    connect(ui->bound_up,SIGNAL(currentIndexChanged(int)), this, SLOT(boundary_logic()));
    connect(ui->bound_left,SIGNAL(currentIndexChanged(int)), this, SLOT(boundary_logic()));
    connect(ui->bound_right,SIGNAL(currentIndexChanged(int)), this, SLOT(boundary_logic()));
    connect(ui->bound_front,SIGNAL(currentIndexChanged(int)), this, SLOT(boundary_logic()));
    connect(ui->bound_back,SIGNAL(currentIndexChanged(int)), this, SLOT(boundary_logic()));

    //dimension_logic
    dimension_logic();
    connect(ui->dimension,SIGNAL(currentIndexChanged(int)), this, SLOT(dimension_logic()));

    //gravity_logic
    gravity_logic();
    connect(ui->gravity_on, SIGNAL(clicked()), this, SLOT(gravity_logic()));
    connect(ui->gravity_off, SIGNAL(clicked()), this, SLOT(gravity_logic()));

    //windemitter_logic
    windemitter_logic();
    connect(ui->wind_emitter_on, SIGNAL(clicked()), this, SLOT(windemitter_logic()));
    connect(ui->wind_emitter_off, SIGNAL(clicked()), this, SLOT(windemitter_logic()));

    //obstacle_logic
    obstacle_logic();
    connect(ui->obstacle_on, SIGNAL(clicked()), this, SLOT(obstacle_logic()));
    connect(ui->obstacle_off, SIGNAL(clicked()), this, SLOT(obstacle_logic()));

    //marker_logic
    marker_logic();
    connect(ui->marker_field_on, SIGNAL(clicked()), this, SLOT(marker_logic()));
    connect(ui->marker_field_off, SIGNAL(clicked()), this, SLOT(marker_logic()));

    //soundemitter
    soundemitter_logic();
    connect(ui->Soundemitter_on, SIGNAL(clicked()), this, SLOT(soundemitter_logic()));
    connect(ui->Soundemitter_off, SIGNAL(clicked()), this, SLOT(soundemitter_logic()));

    //soundemitter_part2
    soundemitter_logic_part2();
    connect(ui->one_pulse_on, SIGNAL(clicked()), this, SLOT(soundemitter_logic_part2()));
    connect(ui->one_pulse_off, SIGNAL(clicked()), this, SLOT(soundemitter_logic_part2()));

    //Aufloesung
    x_res = 0;
    y_res = 0;
    z_res = 0;

    resolution_is_yet_determined = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit()
{

    qApp->exit();
}

/*!
  Open the local simulation form
  */
void MainWindow::open_local_simulation(){

    mylocal_simulation = new local_simulation;
    mylocal_simulation->show();
}

/*!
  Open the help on Filetypes and resolution
  */
void MainWindow::open_help1(){

    myhelp1 = new help1;
    myhelp1->show();

}

/*!
  Open the help on boundary conditions
  */
void MainWindow::open_help2(){

    myhelp2 = new help2;
    myhelp2->show();

}

/*!
  Open help on timings
  */
void MainWindow::open_help3(){

    myhelp3 = new help3;
    myhelp3->show();

}

/*!
  Open help on OpenMP
  */
void MainWindow::open_help4(){

    myhelp4 = new help4;
    myhelp4->show();

}

/*!
  Open help on solver and gas physics
  */
void MainWindow::open_help5(){

    myhelp5 = new help5;
    myhelp5->show();

}

/*!
  Open help on gravity
  */
void MainWindow::open_help6(){

    myhelp6 = new help6;
    myhelp6->show();

}

/*!
  Open help on Obstacles - Winemitters and Markerfields
  */
void MainWindow::open_help7(){

    myhelp7 = new help7;
    myhelp7->show();

}

/*!
  Open help on Sound Emitter
  */
void MainWindow::open_help8(){

    myhelp8 = new help8;
    myhelp8->show();

}

/*!
  Open the about tychoGUI
  */
void MainWindow::open_about(){

    myabout = new about;
    myabout->show();

}


/*!
  Open the configure_path
  */
void MainWindow::open_configure_path(){

    myconfigure_path = new configure_path;
    myconfigure_path->show();

}
