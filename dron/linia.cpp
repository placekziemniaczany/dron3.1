#include "linia.hh"

void Linia::rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi){
vector<drawNS::Point3D> W1;
kpi->erase_shape(this->id);
for (int i = 0; i<2; i++){
W1.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
this->id = kpi->draw_line(W1[0],W1[1],"black");
}

void Linia::PrzesunOWektor(Wektor3D W){
  this->srodek = this->srodek+(orientacja*W);
}

void Linia::loadfromfile(string plik){
fstream input(plik.c_str(), std::ios::in);
double x, y, z;
for (int i = 0; i < 2; i++){
input>>x;
input>>y;
input>>z;
Linia::Tablica_wierzcholkow.DodajWierzcholek(x, y, z);
}
input.close();
}
