#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help1.h"
#include "help2.h"
#include "help3.h"
#include "help4.h"
#include "help5.h"
#include "help6.h"
#include "help7.h"
#include "help7.h"
#include "help8.h"
#include "about.h"
#include "local_simulation.h"
#include "configure_path.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int x_res, y_res, z_res;
    bool resolution_is_yet_determined;

private slots:
    //menus
    void quit();
    void openfile();
    void savefile();
    void reset_gui();
    void open_local_simulation();
    void open_about();
    void open_configure_path();

    //helpbuttons
    void open_help1();
    void open_help2();
    void open_help3();
    void open_help4();
    void open_help5();
    void open_help6();
    void open_help7();
    void open_help8();

    void set_parameters(QList<QString> data);

    void ic_density();
    void ic_temperature();
    void ic_velocity();
    void ic_wind();
    void ic_obstacle();
    void ic_marker();
    void ic_soundemitter();
    void output_path();
    void check_resolution(QString filename);

    //to prevent wrong input
    void ic_logic();
    void boundary_logic();
    void dimension_logic();
    void gravity_logic();
    void windemitter_logic();
    void obstacle_logic();
    void marker_logic();
    void soundemitter_logic();
    void soundemitter_logic_part2();

private:
    Ui::MainWindow *ui;

    help1 *myhelp1;
    help2 *myhelp2;
    help3 *myhelp3;
    help4 *myhelp4;
    help5 *myhelp5;
    help6 *myhelp6;
    help7 *myhelp7;
    help8 *myhelp8;

    configure_path *myconfigure_path;
    local_simulation *mylocal_simulation;

    about *myabout;

    QString ic_density_file;
    QString ic_temperature_file;
    QString ic_velocity_file;
    QString ic_windemitter_file;
    QString ic_obstacle_file;
    QString ic_marker_file;
    QString ic_soundemitter_file;
    QString output_directory;

    QString boundary_selector(QString boundary);
    QString ic_selector(QString ic);
    QString filetype_selector(QString filetype);

    void initiate_ic_files();

};

#endif // MAINWINDOW_H
