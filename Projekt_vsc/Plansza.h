#ifndef PLANSZA_H
#define PLANSZA_H
#include <iostream>

class Plansza
{
    private:
        int numerTury;
        bool czyKoniec;
        char symbol;
    public:
        int ktoWygral;
        int czyjaKolej;
        int ** tablica;
        Plansza();
        Plansza(int wiersz, int kolumna);
        virtual ~Plansza();
        void wyswietleniePlanszy();
        bool stanRozgrywki();
        void wstawianieSymbolu(int &wiersz, int &kolumna, int &gracz);
        friend std::ostream& operator<<(std::ostream& os, const Plansza& plansza);
};

#endif
