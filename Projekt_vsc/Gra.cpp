#include <iostream>
#include <cstdlib>
#include "Gra.h"
#include "Plansza.h"
#include "Plansza.cpp"
#include "GraczKrzyzyk.cpp"
#include "GraczKolko.cpp"
using namespace std;

Gra::Gra()
{
    graczKrzyzyk = new GraczKrzyzyk();
    graczKolko = new GraczKolko();
    this -> ktoWygral = 0;
}

Gra::~Gra()
{
    delete graczKolko;
    delete graczKrzyzyk;
}

bool Gra::operator==(const Gra& other) const
{
    return ktoWygral == other.ktoWygral;
}

bool Gra::operator!=(const Gra& other) const
{
    return ktoWygral != other.ktoWygral;
}

void Gra::rozgrywka() //rozpoczęcie rozgrywki
{
    Plansza * plansza = new Plansza(3, 3);
    plansza -> wyswietleniePlanszy();
    while (plansza -> stanRozgrywki())
    {
        cout << *plansza; //przeciążenie operatora << i wyświetlanie informacji o tym czyja jest aktualnie kolej
        if (plansza -> czyjaKolej == 1)
            graczKrzyzyk -> wybierzPole(plansza);
        else if (plansza -> czyjaKolej == 2)
            graczKolko -> wybierzPole(plansza);
    }

    ktoWygral = plansza->ktoWygral;
    delete plansza;
}

int main()
{
    char znak;
    Gra * gra = new Gra();
    gra -> rozgrywka();
    cout << "Czy chcesz zagrac ponownie? (t/n) ";
    cin >> znak;
    if (znak == 't' || znak == 'T')
    {
        Gra * gra1 = new Gra(); //utworzenie drugiej gry do porównania zwycięzców obu gier
        gra1 -> rozgrywka();
        if (*gra == *gra1) //wykorzystanie przeciążenia operatora == który porównuje wartości zmiennej == dla obu rozegranych gier i sprawdza czy w obu grach wygrał ten sam zawodnik
            cout << "W obu grach wygral ten sam gracz!" << endl;
        else if (*gra != *gra1) //wykorzystanie przeciążęnia operatora !=
            cout << "W tych grach wygrali rozni zawodnicy!" << endl;
        delete gra1;
    }
    delete gra;
    
    system("pause");
    return 0;
}


