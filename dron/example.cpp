#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include <fstream>
#include <string>
#include "Bryla.hh"
#include "Prostopadloscian.hh"
#include "graniastoslup6.hh"
#include "dron.hh"
#include "ZbiorWierzcholkow.hh"
#include "Zbiornik.hh"
#include "Przeszkoda.hh"

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}


using namespace std;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

int main(){

    Zbiornik z;
    z.Scena();

}

