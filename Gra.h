#ifndef GRA_H
#define GRA_H
#include <iostream>
#include "Plansza.h"
#include "Gracz.h"

class Gra : public  Plansza
{
    private:
        int ktoWygral;
        Gracz * graczKrzyzyk;
        Gracz * graczKolko;
    public:
        Gra();
        ~Gra();
        void rozgrywka();
        bool operator==(const Gra& other) const;
        bool operator!=(const Gra& other) const;
};

#endif
