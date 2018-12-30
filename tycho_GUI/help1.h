#ifndef HELP1_H
#define HELP1_H

#include <QDialog>

namespace Ui {
class help1;
}

class help1 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help1(QWidget *parent = 0);
    ~help1();
    
private:
    Ui::help1 *ui;
};

#endif // HELP1_H
