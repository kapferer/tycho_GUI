#ifndef CONFIGURE_PATH_H
#define CONFIGURE_PATH_H

#include <QDialog>

namespace Ui {
class configure_path;
}

class configure_path : public QDialog
{
    Q_OBJECT
    
public:
    explicit configure_path(QWidget *parent = 0);
    ~configure_path();
    
private:
    Ui::configure_path *ui;

private slots:

    void tycho_exectuable_config_ini();


};

#endif // CONFIGURE_PATH_H
