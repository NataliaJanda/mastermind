#include "info.h"
#include <iostream>
using namespace std;

void info::Rules(){

    cout<<
        "\rGra polega na odgadnieciu wybranej liczby ukrytych kolorow.\n"
        "Gra zostanie rozwiazana, jesli w ciagu wybranej liczby tur gracz odgadnie te kolory.\n"
        "W kazdej turze gracz wybiera pierwsze litery kolorow (np. Z- zielony), po czym sprawdza czy trafil.\n"
        "Kazdy prawidlowo odgadniety kolor(na wlasciwym miejscu) sygnalizowana jest X.\n"
        "Jesli gracz odgadl kolor, ale nie odgadl lokalizacji, jest to sygnalizowane O.\n"
        "Gracz nie wie, ktore kolory sa wlasciwe, ktore zas nie.\n"
        "Gra dostepna jest w 4 wariantach : prosty z 4 kolorami i 12 rundami\n"
        "srednim z 5 kolorami i 10 runadmi\n"
        "trudnym z 7 kolorami i 8 rundami\n"
        "oraz trybem dowolnym gdzie mozna samemy wybrac opcje rozgrywki\n"
        "\n";
}

bool info::playAgain() {
    char input;
    cout << "Czy chcesz zagrac jeszcze raz? (t - tak, n - nie): \n";
    cin >> input;
    if (input == 'T' || input == 't' || input == 'n' || input == 'N') {

        if (input == 'T' || input == 't') {
            system("cls");
            return true;
        }
        if (input == 'N' || input == 'n'){
            system("cls");
            return false;
        }
    }
    else {
        cout <<"Niepoprawny znak";
        playAgain();
    }
    return true;
}


