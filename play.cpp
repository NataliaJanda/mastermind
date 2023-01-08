#include <iostream>
#include "play.h"

using namespace std;

int play::main() {
    int token=0;
    cout<<"Witaj w grze!\n";
    do{
        cout<<"Wybierz poziom trudnosci\n";
        gra.chooseLevel();
        gra.kolory();

        for(int i=0;i<gra.Round();i++){
            gra.comunicat();
            cout<<"\x1B[33mTwoj strzal: \033[0m";
            gra.Guess();
            cout<<"Odczytana sekwencja: ";
            gra.showGuess();
            gra.upperLetter();
            gra.IfCorrectSign();
            gra.whereColor();
            if (gra.checkGuess()) {
                cout << "Zgadles\n";
                gra.StrikeWin();
                token = 1;
                break;
            }
        }
        if(token!=1){
            cout<<"no more moves\n";
            gra.showColors();
            gra.StrikeLose();
        }
    }while(play.playAgain());

    return 0;
}
