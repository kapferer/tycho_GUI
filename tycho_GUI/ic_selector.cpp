#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>


/*!
  Selects the number for initial conditions for the parameterfile
  */

QString MainWindow::ic_selector(QString ic){

    QString number;

    if (ic=="TYCHO generated") number = "0";
    if (ic=="Read ICs in TYCHO file-format") number = "1";
    if (ic=="Only obstacle distribution") number = "2";
    if (ic=="A Sod Shock Tube")  number = "3";
    if (ic=="Kelvin Helmholtz instability") number = "4";

    return number;
}

