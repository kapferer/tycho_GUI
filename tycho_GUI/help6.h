#ifndef HELP6_H
#define HELP6_H

#include <QDialog>

namespace Ui {
class help6;
}

class help6 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help6(QWidget *parent = 0);
    ~help6();
    
private:
    Ui::help6 *ui;
};

#endif // HELP6_H
