#ifndef BRYLA_HH
#define BRYLA_HH
#include "ZbiorWierzcholkow.hh"
#include "SMacierz.hh"
#include "InterfejsRysowania.hh"
#define M_PI 3.14159265358979323846

/*!
 * \file
 * \brief Definicja klasy Bryla
 *
 * Plik zawiera definicje klasy Bryla
 */

/*!
 * \brief Enum pozwalajacy wybrac oœ obrotu
 *
 * \param os_ox - obrót wokol osi ox
 * \param os_oy - obrót wokol osi oy
 * \param os_oz - obrót wokol osi oz
 */

enum obroc_wokol {os_ox, os_oy, os_oz};
/*!
 * \brief Modeluje bryly, z których zbudowany jest dron
 *
 * Posiada metody virtualne z ktorych korzystaja powstale bryly
 * (prostopadloscian i graniastoslup)
 *
 */
class Bryla : public InterfejsRysowania {
public:
/*!
 * \brief Tablica wierzchołków
 *
 * Zawiera współrzędne wierzchołków obiektów graficznych.
 */
ZbiorWierzcholkow Tablica_wierzcholkow;
/*!
 * \brief srodek
 *
 * Zawiera informacje o aktualnym polozeniu srodka bryly za pomoca wektora
 */
Wektor3D srodek;
/*!
 * \brief id
 *
 * Zawiera aktualna orientacje bryly za pomoca macierzy obrotu
 */
MacierzOb <double, 3> orientacja;
/*!
 * \brief id
 *
 * Jest to id obiektu potrzebne do jego usuniecia z programu gnuplot
 */
int id;
public:
/*!
 * \brief Wirtualna metoda zmieniająca aktualne położenie obiektu
 */
virtual void PrzesunOWektor (Wektor3D W) = 0;
/*!
 * \brief Wirtualna metoda rysujaca bryle
 */
virtual void rysuj(shared_ptr<drawNS::Draw3DAPI> kpi)=0;
/*!
 * \brief Metoda wczytujaca wierzcholki z pliku
 */
virtual void loadfromfile(string plik) = 0;
};
#endif

