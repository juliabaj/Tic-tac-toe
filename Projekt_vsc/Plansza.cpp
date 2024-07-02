#include <iostream>
#include <cstdlib>
#include "Plansza.h"
using namespace std;

Plansza::Plansza()
{

}

Plansza::Plansza(int wiersz, int kolumna) //konstruktor nadający początkowe wartości i wypełniający plansze zerami
{
    tablica = new int * [wiersz];
    ktoWygral = 0;
    numerTury = 0;
    czyjaKolej = 1;
    czyKoniec = false;

    for (int i = 0; i < wiersz; i++) //wypełnianie planszy zerami
    {
        tablica[i] = new int[kolumna];
        for (int j = 0; j < kolumna; j++)
        {
            tablica[i][j] = 0;
        }
    }
}

Plansza::~Plansza()
{
    for (int i = 0; i < 3; i++)
        delete [] tablica[i];

    delete [] tablica;
}

//wypisanie tablicy na ekran
void Plansza::wyswietleniePlanszy()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " | " << tablica[i][j] << " | ";
        }
        cout << "" << endl;
    }
}


//wyloswanie pola i wstawienie "1" lub "2" w zależności od tury, wypisanie tablicy na ekran
void Plansza::wstawianieSymbolu(int &wiersz, int &kolumna, int &gracz) //do gry
{
    int i, j;
    i = wiersz;
    i -= 1;
    j = kolumna;
    j -= 1;

    while (tablica[i][j] != 0)
    {
        cout << "Ta pozycja jest zajeta, wybierz inna pozycje" << endl;
        cout << "Podaj numer wiersza: ";
        cin >> i;
        i -= 1;
        cout << "Podaj numer kolumny: ";
        cin >> j;
        j -= 1;
    }

    if (gracz == 1)
    {
        tablica[i][j] = 1;
        czyjaKolej = 2;
        ktoWygral = 1;
        numerTury += 1;
        wyswietleniePlanszy();
    }
    else if (gracz == 2)
    {
        tablica[i][j] = 2;
        czyjaKolej = 1;
        ktoWygral = 2;
        numerTury += 1;
        wyswietleniePlanszy();
    }
}

bool Plansza::stanRozgrywki() // funkcja logiczna sprawdzająca, czy gra powinna być kontynuowana, czy przerwana
{
    //wszystkie możliwości na wygraną tj. pion, poziom i skosy
    if ((tablica[0][0] != 0 && tablica[0][0] == tablica[0][1] && tablica[0][0] == tablica[0][2]) || (tablica[1][0] != 0 && tablica[1][0] == tablica[1][1] && tablica[1][0] == tablica[1][2]) ||
        (tablica[2][0] != 0 && tablica[2][0] == tablica[2][1] && tablica[2][0] == tablica[2][2]) || (tablica[0][0] != 0 && tablica[0][0] == tablica[1][0] && tablica[0][0] == tablica[2][0]) ||
        (tablica[0][1] != 0 && tablica[0][1] == tablica[1][1] && tablica[0][1] == tablica[2][1]) || (tablica[0][2] != 0 && tablica[0][2] == tablica[1][2] && tablica[0][2] == tablica[2][2]) ||
        (tablica[0][0] != 0 && tablica[0][0] == tablica[1][1] && tablica[0][0] == tablica[2][2]) || (tablica[2][0] != 0 && tablica[2][0] == tablica[1][1] && tablica[2][0] == tablica[0][2]) )
    {
        if (ktoWygral == 1)
            symbol = 'X';
        else
            symbol = 'O';

        cout << "Koniec gry!" << endl;
        cout << "Zwycieza zawodnik: " << symbol << endl;
        return false;
    }
    else if (numerTury == 9) //maksymalna ilość tur
    {
        cout << "Gra zakonczona remisem!" << endl;
        return false;
    }
    else
        return true;
}

std::ostream& operator<<(std::ostream& os, const Plansza& plansza)
{
    if (plansza.czyjaKolej == 1)
    {
        os << "Ruch zawodnika X" << endl;
    }
    else if (plansza.czyjaKolej == 2)
    {
        os << "Ruch zawodnika O" << endl;
    }
    return os;
}