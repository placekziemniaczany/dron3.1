#ifndef DRON_HH
#define DRON_HH
/*!
 * \file
 * \brief Definicja klasy Dron
 *
 * Plik zawiera definicjê klasy Dron
 */
#include "Prostopadloscian.hh"
#include "graniastoslup6.hh"
#include <cmath>
#include "Przeszkoda.hh"

/*!
 * \brief Modeluje drona którym bêdziemy sie poruszaæ
 *
 * Modeluje drona, czyli jego kszta³t (3 bryly), cechy (kat nachylenia)
 * oraz wszystkie czynnoœci, które mo¿e wykonaæ.
 */
class Dron : public Przeszkoda{
public:
/*!
 * \brief Glowna czesc drona - korpus
 *
 * Przyjmuje ksztalt prostopadloscianu
 */
Prostopadloscian P;
/*!
 * \brief Dwie dodatkowe czesci drona - sruby
 *
 * Przyjmuja ksztalt graniastoslupa podstawie szesciakata foremnego
 */
graniastoslup6 S1, S2;
/*!
 * \brief Kat nachylenia drona do plaszczyzny XY
 *
 * Przyjmuje obecny kat naychlenia drona do tej plaszczyzny w stopniach
 */
 double Alpha = 0;
 double promien;
public:
/*!
 * \brief Konstruktor bezparametryczny
 */
Dron();
/*!
 * Metoda rysujaca ksztalt drona
 */
void rysuj(std::shared_ptr<drawNS::Draw3DAPI>);
/*!
 * Metoda poruszajaca w plaszczyznie XY drona
 */
void Plyn(double odleglosc, double kat, std::shared_ptr<drawNS::Draw3DAPI> & kpi);
/*!
 * Metoda obracajaca drona
 */
  void Obrot(double kat, std::shared_ptr<drawNS::Draw3DAPI> & kpi);
/*!
 * Metoda poruszajaca drona w plaszczyznie OZ
 */
 bool kolizja(std::shared_ptr<Dron> D)override;
};
#endif // DRON_HH
