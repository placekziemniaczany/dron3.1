#ifndef ZBIORWIERZCHOLKOW_HH
#define ZBIORWIERZCHOLKOW_HH
/*!
 * \file
 * \brief Definicja klasy ZbiorWierzcholkow.
 *
 * Plik zawiera definicjê klasy ZbiorWierzcholkow.
 */

#include <fstream>
#include "Wektor3D.hh"
#include <vector>
#include <iostream>


class ZbiorWierzcholkow : public std::vector <Wektor3D> {

public:
 /*!
     * \brief Metoda dodaj¹ca nowy wierzcho³ek
     */
    void DodajWierzcholek(double a, double b, double c);


};

#endif
