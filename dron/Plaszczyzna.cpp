#include "Plaszczyzna.hh"

void Plaszczyzna::rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi){
vector<vector<drawNS::Point3D>> w;
vector<drawNS::Point3D> W1;
kpi->erase_shape(this->id);
for (int i = 0; i<21; i++){
W1.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
w.push_back(W1);
this->id = kpi->draw_polyhedron(vector<vector<drawNS::Point3D>> {w
},"black");
}

void Plaszczyzna::loadfromfile(string plik){
fstream input(plik.c_str(), std::ios::in);
double x, y, z;
for (int i = 0; i < 2; i++){
input>>x;
input>>y;
input>>z;
Plaszczyzna::Tablica_wierzcholkow.DodajWierzcholek(x, y, z);
}
input.close();
}

