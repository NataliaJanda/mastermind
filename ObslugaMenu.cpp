#include "ObslugaMenu.h"
#include <windows.h>
#include "play.h"

using namespace  std;

void ObslugaMenu::color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void ObslugaMenu::gotoxy(int x, int y) {
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void ObslugaMenu::Rules() {
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



