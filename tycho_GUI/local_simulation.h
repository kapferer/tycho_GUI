#ifndef LOCAL_SIMULATION_H
#define LOCAL_SIMULATION_H

#include <QDialog>
#include <stdlib.h>
#include <QProcess>
#include "run_error.h"
#include "help_local_simulation.h"

namespace Ui {
class local_simulation;
}

class local_simulation : public QDialog
{
    Q_OBJECT
    
public:
    explicit local_simulation(QWidget *parent = 0);
    ~local_simulation();

    QStringList parameterfile;
    QStringList parameterfile_restart;

private:
    Ui::local_simulation *ui;
    QProcess *proc;

    run_error *pro_run;

    help_local_simulation *mylocal_simulation_help;



private slots:

    void tycho_exectuable();
    void parameterfile_path();
    void local_simulation_start();
    void local_simulation_restart();
    void local_simulation_stop();
    void readFromStdout();
    void save_log();
    void reset_gui();
    void run_error_gui();
    void open_help();
};

#endif // LOCAL_SIMULATION_H
