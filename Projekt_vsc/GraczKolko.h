#ifndef GRACZKOLKO_H
#define GRACZKOLKO_H

#include "Gracz.h"
#include "Plansza.h"

class GraczKolko : public Gracz 
{
    public:
        void wybierzPole(Plansza * plansza);
};

#endif