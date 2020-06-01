#include "Prostopadloscian.hh"
using namespace std;
/*!
 * Funkcja rysujaca prostopadloscian
 * Funkcja w petlach wrzuca do lokalnych szablonow \e W1 i \e W2 za pomoca
 * metody push_back dane wierzcholkow odczytanych z tablic wierzcholkow danych
 * prostopadloscianu. Pozniej szablony te sa wrzucane do szablonu \e w, z ktorego
 * korzysta funkcja draw_polyhedron. Kazda petla odpowiada za narysowanie podstawy
 * prostopadloscianu. Id tego prostopadloscianu przypisywane jest funkcji draw_polyhedron,
 * zeby z kazdym kolejnym rysowaniem poprzedni obiekt byl wymazywany z gnuplota
 * \param kpi - wskaznik na modul do rysowania w gnuplocie
 */
void Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi){
vector<vector<drawNS::Point3D>> w;
vector<drawNS::Point3D> W1, W2;
kpi->erase_shape(id);
for (int i = 0; i<4; i++){
W1.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
w.push_back(W1);
for (int i = 4; i<8; i++){
W2.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
w.push_back(W2);
id = kpi->draw_polyhedron(vector<vector<drawNS::Point3D>> {w
},"black");
}
/*!
 * Funkcja wczytujaca dane wierzcholkow drona z pliku
 * funkcja ktora obsluguje wczytywanie danych za pomoca fstream. W petli
 * wczytywane sa poszczegole wierzcholki, ktore potem metoda DodajWierzholek
 * trafiaja do Tablicy wierzcholkow
 * \param plik - nazwa pliku
 */
void Prostopadloscian::loadfromfile(string plik){
fstream input(plik.c_str(), std::ios::in);
double x, y, z;
for (int i = 0; i < 8; i++){
input>>x;
input>>y;
input>>z;
Prostopadloscian::Tablica_wierzcholkow.DodajWierzcholek(x, y, z);
}
input.close();
}
/*!
 * Funkcja przesuwajaca prostopadloscian o wektor
 *
 * Do srodka prostopadloscianu dodawany jest nowy wektor o który siê przesuwa
 * przemno¿ony przez obecna orientacje prostopadloscianu
 * \param Wektor3D W - Wektor o ktory mamy przesunac prostopadloscian
 */
void Prostopadloscian::PrzesunOWektor(Wektor3D W){
  this->srodek = this->srodek+(orientacja*W);
}
/*!
 * Funkcja obracajaca prostopadloscian o kat wokol danej osi
 *
 * W zaleznosci od osi orientacja jest przemnazana przez macierz obrotu
 * dla danej osi i nadpisywana
 * \param double kat - kat obrotu
 * \param obroc_wokol os - os o ktora ma sie obrocic zawarta w enum
 *
 */
void Prostopadloscian::Obrot(double kat, obroc_wokol os){
kat = kat * (M_PI/180);
 MacierzOb <double, 3> M,N,O;
switch (os){
case os_ox:
M = M.obrot_ox(kat);
this->orientacja =this->orientacja* M;
break;
case os_oy:
 N = N.obrot_oy(kat);
 this->orientacja =this->orientacja* N;
break;
case os_oz:
    O = O.obrot_oz(kat);
    this->orientacja =this->orientacja* O;
    break;
}
}


