#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
/*!
 * \file
 * \brief Definicja klasy graniastoslup
 *
 * Plik zawiera definicjê klasy graniastoslup
 */
#include "Bryla.hh"
#include "InterfejsRysowania.hh"
#include "ZbiorWierzcholkow.hh"
/*!
 * \brief Modeluje graniastoslup, sruby drona
 *
 * Modeluje graniastoslup dziedzczacy z klasy bryla
 * Posiada metody rysowania, wczytywania, przesuwania i obracania
 *
 */
class graniastoslup6 : public Bryla{
protected:
    public:
/*!
 * \brief funkcja rysujaca graniastoslup
 */
void rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi);
/*!
 * \brief funkcja wczytujaca z pliku wierzcholki
 */
void loadfromfile(string plik);
/*!
 * \brief Przesuwajaca graniastoslup o wektor
 */
void PrzesunOWektor(Wektor3D W);
/*!
 * \brief Obracajaca graniastoslup o kat wokol danej osi
 */
void Obrot(double, obroc_wokol);
};



#endif

