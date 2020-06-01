#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH
#include "Bryla.hh"
class Plaszczyzna : public Bryla{
public:

void rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi);

void loadfromfile(string plik);

};

#endif
