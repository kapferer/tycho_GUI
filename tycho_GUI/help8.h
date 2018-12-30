#ifndef HELP8_H
#define HELP8_H

#include <QDialog>

namespace Ui {
class help8;
}

class help8 : public QDialog
{
    Q_OBJECT
    
public:
    explicit help8(QWidget *parent = 0);
    ~help8();
    
private:
    Ui::help8 *ui;
};

#endif // HELP8_H
