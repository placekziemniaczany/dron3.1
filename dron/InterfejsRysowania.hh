#ifndef INTERFEJS_RYSOWANIA_HH
#define INTERFEJS_RYSOWANIA_HH
#include "Dr3D_gnuplot_api.hh"
class InterfejsRysowania {

public:
    virtual void rysuj(std::shared_ptr<drawNS::Draw3DAPI>kpi)=0;
};

#endif // INTERFEJS_RYSOWANIA_HH
