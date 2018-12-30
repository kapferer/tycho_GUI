#ifndef HELP2_H
#define HELP2_H

#include <QDialog>

namespace Ui {
class help2;
}

class help2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help2(QWidget *parent = 0);
    ~help2();
    
private:
    Ui::help2 *ui;
};

#endif // HELP2_H
