## Tyrolian Computational Hydrodynamics -- tycho_GUI

![Tycho](https://github.com/kapferer/tycho_cfd/blob/master/tycho_logo.jpg "Tycho Logo")

http://tycho-cfd.at/

Welcome to tychoGUI, which is designed to make interaction with TYCHO easier. It is written in C++ with the Qt framework.
You can download tychoGUI here.

To compile the sources you need a C++ compiler (e.g. http://gcc.gnu.org/) and the QT library including the qt-devel packages. Note that QT is available under the open source LGPL version 2.1 license, from the release of Qt 4.5 onward (read more).

The mandatory two steps for building the tychoGUI are:

qmake-qt4
make
You will find the tychoGUI executable within the source directory.

What does tychoGUI provide:

Setting up parameterfiles for TYCHO
Preventing wrong parameter combinations, which lead to common TYCHO errors
Saving and Editing of parameterfiles and
running local TYCHO simulations (provided the TYCHO executable is available on your system)
