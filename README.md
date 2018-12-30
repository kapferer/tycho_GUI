## Tyrolian Computational Hydrodynamics -- tycho_GUI

![Tycho](https://github.com/kapferer/tycho_cfd/blob/master/tycho_logo.jpg "Tycho Logo")

http://tycho-cfd.at/

This is tychoGUI, a user interface to make interaction with TYCHO easier.
The UI can set up parameterfiles, save and open them for further editing and start a local simulation. 
tychoGUI is freely available to everyone. You are welcome to download it and do whatever you want with it. I would appreciate, however, if you would acknowledge the package in your publications/work and if you would send me information for what purpose you use the code. Keep in mind that this code does not come with any guarantee. 

![TychoGUI](https://github.com/kapferer/tycho_GUI/blob/master/tycho_gui.jpg "tycho_GUI")

The tychoGUI requires QT. QT is licensed under the terms of the GNU Lesser General Public License (LGPL) version 2.1 (see http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html).
More about the QT license can be found at http://qt.nokia.com/products/licensing/

* To generate tychoGUI you need to execute the following steps:

qmake-qt4
make

After compilation you should find the tychoGUI executable within the sources directory. Additional help is provided within tychoGUI and the TYCHO documentation at TYCHO's homepage http://www.tycho-cfd.at/


# What does tychoGUI provide:

* Setting up parameterfiles for TYCHO
* Preventing wrong parameter combinations, which lead to common TYCHO errors
* Saving and Editing of parameterfiles and
* running local TYCHO simulations (provided the TYCHO executable is available on your system)

---------------

TYCHO is a multidimensional (1D/2D and 3D) compressible hydrodynamics code written in C and parallelized with OpenMP. A Lagrangian remap version of the Piecewise Parabolic Method developed by Paul Woodward and Phil Colella (1984) is applied. The code is based on the freely available VH-1 package.


The simulation package is focused on wind-tunnel experiments and has special routines for obstacles in wind-stream and advection of marker fields for investigating obstacle-gas interactions. In addition momenta and their direction on obstacle surfaces and thermal diffusion can be studied within your simulation. Gravity is included as a constant background-field and a stratified atmosphere can be set up if needed. 
TYCHO is freely available to everyone. You are welcome to download it and do whatever you want with it. I would appreciate, however, if you would acknowledge the package in your publications/work and if you would send me information for what purpose you use the code. Keep in mind that this code does not come with any guarantee. 
TYCHO is developed by Wolfgang Kapferer
TYCHO's home is http://www.tycho-cfd.at/

