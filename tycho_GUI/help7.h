#ifndef HELP7_H
#define HELP7_H

#include <QDialog>

namespace Ui {
class help7;
}

class help7 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help7(QWidget *parent = 0);
    ~help7();
    
private:
    Ui::help7 *ui;
};

#endif // HELP7_H
