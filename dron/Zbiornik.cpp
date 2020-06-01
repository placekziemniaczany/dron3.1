#include "Zbiornik.hh"
using namespace std;
using drawNS::APIGnuPlot3D;
using drawNS::Point3D;
/*!
 * Funkcja wyswietlajaca menu
 *
 * Funkcja po prostu wyswietla co mozna zrobic z dronem, to znaczy
 * za co odpowiadaja poszczegolne litery kiedy sie je wpisze
 */
void Zbiornik::WyswietlMenu(){
cout<<"\t CENTRUM STEROWANIA DRONEM PODWODNYM! " <<endl;
    cout << "p -> Plywanie" << endl;
    cout << "o -> Obrot: "<<endl;
    cout << "w -> Ponowne wyswietlenie menu" << endl;
    cout << "k -> Zakonczenie dzialania programu" << endl;
}
/*!
 * Funkcja obslugujaca ruch drona i animujaca go
 *
 * Funkcja prosi na poczatku uzytkownika o wpisanie mozliwego znaku ktory odpowiada za
 * dana akcje. Sprawdzana jest poprawnosc wpisanego mozliwego znaku
 *
 *\param kpi - wskaznik do programu rysowania gnuplot
 */
void Zbiornik::Menu(std::shared_ptr<drawNS::Draw3DAPI> kpi){
    char znak;
    double kat, odleglosc;
    while(znak != 'k'){
    cin>>znak;
    switch(znak){
    case 'p':
        cout<<"Na jaką odleglosc ma plynac? "<<endl;
        cin>>odleglosc;
        cout<<"Podaj kat wznoszenia/opadania drona "<<endl;
        cin>>kat;
        for(double i = 0; i<odleglosc; i++){
            this->D->Plyn(i, kat, kpi);
        }
        break;
    case 'o':
        cout<<"Podaj kat na jaki chcesz obrocic drona "<<endl;
        cin>>kat;
        for(double i = 0; i<2*kat; i++){
        this->D->Obrot(i, kpi);
    }
    break;
    case 'w':
        this->WyswietlMenu();
        break;
    case 'k':
        cout<<"Koniec pracy z programem!"<<endl;
        exit(0);
    }
}
}
/*!
 * Funkcja zbierajaca wszystkie elementy zbiornika razem
 *
 * Funkcja inicjuje program gnuplot o danych rozmiarach, rysuje poczatkowa pozycje drona
 * rysuje takze dno oraz powierzchnie wody, wyswietla menu poczatkowe oraz uruchamia funkcje
 * menu odpowiadajaca za ruch drona
 *
 */

void Zbiornik::Scena(){
  std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-30,30,-30,30,-30,30,0));
  this->D->rysuj(api);
  this->D->rysuj(api);
  api->draw_surface(vector<vector<Point3D>>{{
	drawNS::Point3D(-30,-30,28), drawNS::Point3D(-30,0,30), drawNS::Point3D(-30,30,28)},{
	drawNS::Point3D(-20,-30,30), drawNS::Point3D(-20,0,28), drawNS::Point3D(-20,30,30)},{
	drawNS::Point3D(-10,-30,28), drawNS::Point3D(-10,0,30), drawNS::Point3D(-10,30,28)},{
	drawNS::Point3D(0,-30,30), drawNS::Point3D(0,0,28), drawNS::Point3D(0,30,30)}, {
	drawNS::Point3D(10,-30,28), drawNS::Point3D(10,0,30), drawNS::Point3D(10,30,28)},{
	drawNS::Point3D(20,-30,30), drawNS::Point3D(20,0,28), drawNS::Point3D(20,30,30)},{
	drawNS::Point3D(30,-30,28), drawNS::Point3D(30,0,30), drawNS::Point3D(30,30,28)}
    },"blue");
  api->draw_surface(vector<vector<Point3D>>{{
	drawNS::Point3D(-30,-30,-30), drawNS::Point3D(-30,0,-30), drawNS::Point3D(-30,30,-30)},{
	drawNS::Point3D(-20,-30,-30), drawNS::Point3D(-20,0,-30), drawNS::Point3D(-20,30,-30)},{
	drawNS::Point3D(-10,-30,-30), drawNS::Point3D(-10,0,-30), drawNS::Point3D(-10,30,-30)},{
	drawNS::Point3D(0,-30,-30), drawNS::Point3D(0,0,-30), drawNS::Point3D(0,30,-30)}, {
	drawNS::Point3D(10,-30,-30), drawNS::Point3D(10,0,-30), drawNS::Point3D(10,30,-30)},{
	drawNS::Point3D(20,-30,-30), drawNS::Point3D(20,0,-30), drawNS::Point3D(20,30,-30)},{
	drawNS::Point3D(30,-30,-30), drawNS::Point3D(30,0,-30), drawNS::Point3D(30,30,-30)}
    },"blue");
  this->WyswietlMenu();
  this->Menu(api);
}

