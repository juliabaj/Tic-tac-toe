#include <iostream>
using namespace std;

#include "GraczKolko.h"

void GraczKolko::wybierzPole(Plansza * plansza) 
{
    int wiersz, kolumna;
    int gracz = 2;
    cout << "Wybierz pozycje na ktora chcesz wstawic swoj symbol" << endl;
    cout << "Gracz O -> Podaj numer wiersza: ";
    cin >> wiersz;
    cout << "Gracz O -> Podaj numer kolumny: ";
    cin >> kolumna;
    plansza->wstawianieSymbolu(wiersz, kolumna, gracz);
}