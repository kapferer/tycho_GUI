#ifndef RUN_ERROR_H
#define RUN_ERROR_H

#include <QWidget>

namespace Ui {
class run_error;
}

class run_error : public QWidget
{
    Q_OBJECT
    
public:
    explicit run_error(QWidget *parent = 0);
    ~run_error();
    
private:
    Ui::run_error *ui;
};

#endif // RUN_ERROR_H
