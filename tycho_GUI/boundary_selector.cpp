#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>


/*!
  Selects the proper number for boundaries
  */
QString MainWindow::boundary_selector(QString boundary){

    QString number;

    if (boundary=="zero gradient") number = "0";
    if (boundary=="reflecting") number = "1";
    if (boundary=="small padding") number = "2";
    if (boundary=="outflow")  number = "3";
    if (boundary=="inflow") number = "4";
    if (boundary=="periodic")  number = "5";

    return number;
}
