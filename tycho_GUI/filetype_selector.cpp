#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>


/*!
  Selects the filetype-number from the input
  */

QString MainWindow::filetype_selector(QString filetype){

    QString number;

    if (filetype=="TYCHO files") number = "0";
    if (filetype=="VTK files") number = "1";
    if (filetype=="AMIRA files") number = "2";
    if (filetype=="IFRIT files")  number = "3";

    return number;
}


