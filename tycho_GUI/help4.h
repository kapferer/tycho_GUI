#ifndef HELP4_H
#define HELP4_H

#include <QDialog>

namespace Ui {
class help4;
}

class help4 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help4(QWidget *parent = 0);
    ~help4();
    
private:
    Ui::help4 *ui;
};

#endif // HELP4_H
