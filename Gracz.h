#ifndef GRACZ_H
#define GRACZ_H
#include "Plansza.h"


class Gracz
{
    public:
        virtual void wybierzPole(Plansza * plansza) = 0;
};

#endif // GRACZ_H
