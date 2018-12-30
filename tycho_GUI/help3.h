#ifndef HELP3_H
#define HELP3_H

#include <QDialog>

namespace Ui {
class help3;
}

class help3 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help3(QWidget *parent = 0);
    ~help3();
    
private:
    Ui::help3 *ui;
};

#endif // HELP3_H
