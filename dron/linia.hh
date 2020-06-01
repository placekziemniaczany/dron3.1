#ifndef LINIA_HH
#define LINIA_HH
#include "Bryla.hh"
#include "InterfejsRysowania.hh"
#include "ZbiorWierzcholkow.hh"
class Linia : public Bryla{

public:

void rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi);

void loadfromfile(string plik);

void PrzesunOWektor(Wektor3D W);

};

#endif
