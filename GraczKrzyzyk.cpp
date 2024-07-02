#include <iostream>
using namespace std;

#include "GraczKrzyzyk.h"

void GraczKrzyzyk::wybierzPole(Plansza * plansza)
{
    int wiersz, kolumna;
    int gracz = 1;
    cout << "Wybierz pozycje na ktora chcesz wstawic swoj symbol" << endl;
    cout << "Gracz X -> Podaj numer wiersza: ";
    cin >> wiersz;
    cout << "Gracz X -> Podaj numer kolumny: ";
    cin >> kolumna;
    plansza->wstawianieSymbolu(wiersz, kolumna, gracz);
}
