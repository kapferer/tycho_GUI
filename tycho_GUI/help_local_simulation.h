#ifndef HELP_LOCAL_SIMULATION_H
#define HELP_LOCAL_SIMULATION_H

#include <QDialog>

namespace Ui {
class help_local_simulation;
}

class help_local_simulation : public QDialog
{
    Q_OBJECT
    
public:
    explicit help_local_simulation(QWidget *parent = 0);
    ~help_local_simulation();
    
private:
    Ui::help_local_simulation *ui;
};

#endif // HELP_LOCAL_SIMULATION_H
