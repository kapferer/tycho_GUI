#include <QApplication>
#include "mainwindow.h"


/*!
This is tycho-GUI a user interface to make interaction with TYCHO easier.
The UI can set up parameterfiles, save and open them for further editing and start a local simulation.

TYCHO is developed by Wolfgang Kapferer
TYCHO's home is http://www.tycho-cfd.at/

This is version 0.3
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}

