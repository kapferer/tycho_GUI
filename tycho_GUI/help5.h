#ifndef HELP5_H
#define HELP5_H

#include <QDialog>

namespace Ui {
class help5;
}

class help5 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help5(QWidget *parent = 0);
    ~help5();
    
private:
    Ui::help5 *ui;
};

#endif // HELP5_H
