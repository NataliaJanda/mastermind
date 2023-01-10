#include <iostream>
#include "play.h"

using namespace std;

int play::main() {
    do {
        cout<<"Witaj w grze!\n";
        cout<<"Wybierz poziom trudnosci\n";
        gra.chooseLevel();
        system("cls");
        gra.kolory();
        system("cls");
        int r=1;
        int token=0;
        int z=0;
        char tmp[gra.Round()][gra.Tab()];
        char tmp1[gra.Round()][gra.Tab()];
        char tmp2[gra.Round()][gra.Tab()];
        for(int i=0;i<gra.Round();i++){
            for(int k=0;k<gra.Tab();k++){
                tmp[i][k] = '_';
                tmp1[i][k] = '.';
                tmp2[i][k] = '.';
            }
        }
        for(int g=0;g<gra.Round();g++) {
            system("cls");
            gra.comunicat();
            cout << "========================================================\n";
            for (int i = 0; i < gra.Round(); i++) {
                cout << r++ << ".\t";
                for (int j = 0; j < gra.Tab(); j++) {
                    cout << tmp[i][j] << "\t ";
                }
                cout<<" | ";
                for (int k =0; k < gra.Tab(); k++) {
                    cout << tmp1[i][k];
                }
                for (int k =0; k < gra.Tab(); k++) {
                    cout << tmp2[i][k];
                }
                cout<<" | ";
                cout << endl;
            }
            cout << "========================================================\n";
            r = 1;
            do{
                cout << "Twoj strzal: ";
                gra.Guess();
                gra.upperLetter();
            }while(gra.IfCorrectSign());
            gra.whereColor();
            for (int i = 0; i < gra.Tab(); i++) {
                tmp[z][i] = gra.showGuess()[i];
                tmp1[z][i] = gra.Sequencex()[i];
                tmp2[z][i] = gra.Sequenceo()[i];
            }
            z++;
            gra.showColors(); //pokazanie odpowiedzi
            if (gra.checkGuess()) {
                system("cls");
                cout << "========================================================\n";
                for (int i = 0; i < gra.Round(); i++) {
                    cout << r++ << ".\t";
                    for (int j = 0; j < gra.Tab(); j++) {
                        cout << tmp[i][j] << "\t ";
                    }
                    cout<<" | ";
                    for (int k =0; k < gra.Tab(); k++) {
                        cout << tmp1[i][k];
                    }
                    for (int k =0; k < gra.Tab(); k++) {
                        cout << tmp2[i][k];
                    }
                    cout<<" | ";
                    cout << endl;
                }
                cout << "========================================================\n";
                cout << "Zgadles\n";
                gra.StrikeWin();
                token = 1;
                break;
            }

        }

        if (token != 1) {
            system("cls");
            cout << "========================================================\n";
            for (int i = 0; i < gra.Round(); i++) {
                cout << r++ << ".\t";
                for (int j = 0; j < gra.Tab(); j++) {
                    cout << tmp[i][j] << "\t ";
                }
                cout<<" | ";
                for (int k =0; k < gra.Tab(); k++) {
                    cout << tmp1[i][k];
                }
                for (int k =0; k < gra.Tab(); k++) {
                    cout << tmp2[i][k];
                }
                cout<<" | ";
                cout << endl;
            }
            cout << "========================================================\n";
            cout << "no more moves\n";
            gra.showColors();
            gra.StrikeLose();
        }
    }while(gra.playAgain());
    return 0;
}
