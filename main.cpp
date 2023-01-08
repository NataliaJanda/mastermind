#include <iostream>
#include <conio.h>
#include "play.h"
#include "menu.h"

using namespace std;

int main()
{
    play game;
    menu menu;
    int Set[] = {7,7,7}; // podstawowe kolory
    int counter = 3;
    char key;

    menu::gotoxy(1,1);
    cout<<"Mastermind\n";

    for(int i=0;;) {

        menu::gotoxy(5, 3);
        menu::color(Set[0]);
        cout << "Graj";

        menu::gotoxy(5, 4);
        menu::color(Set[1]);
        cout << "Jak grac?";

        menu::gotoxy(5, 5);
        menu::color(Set[2]);
        cout << "Exit";

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3)) //strzalka do gory
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2)) //strzalka w dol
        {
            counter++;
        }

        if (key == '\r') //carriage return
        {
            if (counter == 1) {
                system("cls");
                game.main();
            }
            if (counter == 2) {
                system("cls");
                menu.gotoxy(10,10);
                info::Rules();
            }
            if (counter == 3) {
                system("cls");
                exit(0);
            }
        }

        Set[0] = 7; //powrot do poprzedniego koloru
        Set[1] = 7;
        Set[2] = 7;

        if (counter == 1) {
            Set[0] = 12;
        }
        if (counter == 2) {
            Set[1] = 12;
        }
        if (counter == 3) {
            Set[2] = 12;
        }
    }

}
