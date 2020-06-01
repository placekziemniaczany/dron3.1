#include "graniastoslup6.hh"
/*!
 * Funkcja rysujaca graniastoslup
 * Funkcja w petlach wrzuca do lokalnych szablonow \e W1 i \e W2 za pomoca
 * metody push_back dane wierzcholkow odczytanych z tablic wierzcholkow danych
 * graniastoslupow. Pozniej szablony te sa wrzucane do szablonu \e w, z ktorego
 * korzysta funkcja draw_polyhedron. Kazda petla odpowiada za narysowanie podstawy
 * graniastoslupa. Id tego graniastoslupa przypisywane jest funkcji draw_polyhedron,
 * zeby z kazdym kolejnym rysowaniem poprzedni obiekt byl wymazywany z gnuplota
 * \param kpi - wskaznik na modul do rysowania w gnuplocie
 */
void graniastoslup6::rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi){
vector<vector<drawNS::Point3D>> w;
vector<drawNS::Point3D> W1, W2;
kpi->erase_shape(this->id);
for (int i = 0; i<6; i++){
  W1.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
w.push_back(W1);
for (int i = 6; i<12; i++){
  W2.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
w.push_back(W2);
this->id = kpi->draw_polyhedron(vector<vector<drawNS::Point3D>> {w
},"black");
}
/*!
 * Funkcja wczytujaca dane wierzcholkow drona z pliku
 * funkcja ktora obsluguje wczytywanie danych za pomoca fstream. W petli
 * wczytywane sa poszczegole wierzcholki, ktore potem metoda DodajWierzholek
 * trafiaja do Tablicy wierzcholkow
 * \param plik - nazwa pliku
 */

void graniastoslup6::loadfromfile(string plik){
fstream input(plik.c_str(), std::ios::in);
double x, y, z;
for (int i = 0; i < 12; i++){
input>>x;
input>>y;
input>>z;
Tablica_wierzcholkow.DodajWierzcholek(x,y,z);
}
input.close();
}
/*!
 * Funkcja przesuwajaca graniastoslup o wektor
 *
 * Do srodka graniastoslupa dodawany jest nowy wektor o który siê przesuwa
 * przemno¿ony przez obecna orientacje graniastoslupa
 * \param Wektor3D W - Wektor o ktory mamy przesunac graniastoslup
 */
void graniastoslup6::PrzesunOWektor(Wektor3D W){
  this->srodek = this->srodek+(orientacja*W);
}
/*!
 * Funkcja obracajaca graniastoslup o kat wokol danej osi
 *
 * W zaleznosci od osi orientacja jest przemnazana przez macierz obrotu
 * dla danej osi i nadpisywana
 * \param double kat - kat obrotu
 * \param obroc_wokol os - os o ktora ma sie obrocic zawarta w enum
 *
 */
void graniastoslup6::Obrot(double kat, obroc_wokol os){
kat = kat * (M_PI/180);
 MacierzOb <double, 3> M, N;
switch (os){
case os_ox:
M = M.obrot_ox(kat);
orientacja = this->orientacja*M;
 break;
case os_oy:
 M = M.obrot_oy(kat);
 orientacja = this->orientacja*M;
break;
case os_oz:
    M = M.obrot_oz(kat);
    N = N.obrot_ox(10);
   orientacja =  this->orientacja*M;
break;
}
}
