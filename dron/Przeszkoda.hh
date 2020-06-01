#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include "linia.hh"
#include "Prostopadloscian.hh"
#include "Plaszczyzna.hh"

class Dron;

class Przeszkoda{
std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;
std::vector<std::shared_ptr<Dron> > kolekcja_Dronow;
public:
virtual bool kolizja(std::shared_ptr<Dron> D)=0;
};

class Przeszkoda_prostopadloscian : public Przeszkoda, public Prostopadloscian{
public:
    bool kolizja(std::shared_ptr<Dron> D)override;
};

class Przeszkoda_pret : public Przeszkoda, public Linia{
public:
    bool kolizja(std::shared_ptr<Dron> D)override;
};

class Woda : public Przeszkoda, public Plaszczyzna {
public:
    bool kolizja(std::shared_ptr<Dron> D)override;
};
#endif // PRZESZKODA_HH
