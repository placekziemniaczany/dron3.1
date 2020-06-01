/*!
 *  \file
 *  \brief Zawiera definicje metod klasy ZbiorWierzcholkow.
 *
 *  Zawiera definicje metod klasy ZbiorWierzcholkow, wraz
 *  z ich opisem.
 */
#include "ZbiorWierzcholkow.hh"
/*!
 * Metoda Tworzy nowy obiekt klasy \e Wektor3D, oraz
 * dodaje do niego pobrane wartoœci. Nastêpnie dziedziczon¹
 * metod¹ \e push_back(), dodaje dany obiekt na pocz¹tek tablicy \e vector.
 *
 * \param a - X'owa wspó³rzêdna wierzcho³ka
 * \param b - Y'owa wspó³rzêdna wierzcho³ka
 * \param c - Z'owa wspó³rzêdna wierzcho³ka
 */
void ZbiorWierzcholkow::DodajWierzcholek(double a, double b, double c) {
Wektor3D nowy;
nowy[0] = a;
nowy[1] = b;
nowy[2] = c;
push_back(nowy);
}

