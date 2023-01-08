#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include "game.h"

using namespace std;

game::game() {
    guess = new char[Max];
    color = new char[Max];
    srand(time(0));
}
game::~game() {
    delete [] guess;
    delete [] color;
    guess = nullptr;
    color = nullptr;
}
void game::Guess() {
    string tmp;
    getline(cin,tmp,'\n');
    tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace),tmp.end());
    for(int i=0;i<tmp.length();i++){
        guess[i]=tmp[i];
    }
}

int game::Round() const {
    return maxRound;
}
void game::StrikeWin(){
    strike = strike +1;
    cout<<"Strike: "<<strike<<endl;
}
void game::StrikeLose(){
    strike = strike - 1;
    cout<<"Strike: "<<strike<<endl;
}

void game::kolory() {
    color[Max] = '\0';
    int tmp;
    string s;
    char liczba[Max];
    for(int i=0;i<maxTab;i++){
        tmp = 0 + (rand() % 9);
        s = to_string(tmp);
        liczba[i] = s[0];
    }
    if(level == "1"){
        for (int i = 0; i < maxTab; i++){
            if(liczba[i] == '1' || liczba[i]=='5' || liczba[i]=='0') color[i] = 'B';
            else if(liczba[i] == '2' || liczba[i]=='6' || liczba[i]=='9') color[i] = 'C';
            else if(liczba[i] == '3' || liczba[i]=='7') color[i] = 'N';
            else if(liczba[i] == '4' || liczba[i]=='8') color[i] = 'Z';
        }
    }
    if(level == "2"){
        for (int i = 0; i < maxTab; i++){
            if(liczba[i] == '1' || liczba[i]=='5') color[i] = 'B';
            else if(liczba[i] == '2' || liczba[i]=='6') color[i] = 'C';
            else if(liczba[i] == '3' || liczba[i]=='7') color[i] = 'N';
            else if(liczba[i] == '4' || liczba[i]=='8') color[i] = 'Z';
            else if(liczba[i]=='9'||liczba[i]=='0') color[i] = 'F';
        }
    }
    if(level == "3" || level == "4"){
        for (int i = 0; i < maxTab; i++){
            if(liczba[i] == '1' || liczba[i]=='5') color[i] = 'B';
            else if(liczba[i] == '2'|| liczba[i] == '6') color[i] = 'C';
            else if(liczba[i] == '3'|| liczba[i] == '7') color[i] = 'N';
            else if(liczba[i] == '4') color[i] = 'Z';
            else if(liczba[i] == '9') color[i] = 'F';
            else if(liczba[i] == '0') color[i] = 'R';
            else if(liczba[i] == '8') color[i] = 'G';
        }
    }
    //showColors(); //! Pokazanie odpowiedzi
}
void game::showColors() {
    cout<<"Szukany ciag kolorow: ";
    for(int i=0;i<maxTab;i++){
        cout<<color[i];
    }
    cout<<endl;
}
void game::showGuess() {
    for(int i=0;i<maxTab;i++){
        cout<<guess[i];
    }
    cout<<endl;
}
void game ::upperLetter() {
    for(int i=0;i<maxTab;i++){
        guess[i] = toupper(guess[i]);
    }
}

bool game::checkGuess() {
    for(int i=0;i<maxTab;i++){
        if(guess[i]!=color[i]){
            return false;
        }
    }
    return true;
}

void game::chooseLevel() {
    cout<<"Dostepne sa 3 poziomy trudnosci\n"
        <<"1 - latwy\n"
        <<"2 - sredni\n"
        <<"3 - trudny\n"
        <<"4 - wlasne ustawienia\n";
    cout<<"Ktory level wybierasz? : "<<endl;
    getline(cin,level,'\n');
    if(level == "1"){
        maxRound = 12;
        maxTab = 4;
    }
    else if(level == "2"){
        maxRound = 10;
        maxTab = 4;
    }
    else if(level == "3"){
        maxRound = 8;
        maxTab = 4;
    }
    else if(level == "4"){
        string rundy,tablica;
        cout<<"Podaj liczbe rund: ";
        getline(cin,rundy);
        if(check_number(rundy))
            maxRound = stoi(rundy);
        else {
            cout<<"Podana wartosc musi byc liczba badz cyfra\n";
            chooseLevel();
        }
        cout<<"Podaj dlugosc ciagu kolorow (max 10): ";
        getline(cin,tablica);
        if(check_number(tablica))
            maxTab = stoi(tablica);
        else {
            cout<<"Podana wartosc musi byc liczba badz cyfra\n";
            chooseLevel();
        }
    }
    else {
        cout<<"niepoprawny znak"<<endl;
        chooseLevel();
    }
}
bool game::check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
void game::whereColor() const{
    for(int i=0; i<maxTab; i++){
        if(color[i] == guess[i])
            cout<<"X";
    }
    /*sprawdzanie wystepowania poprawnych
     znakow niezaleznie od miejsca w ktorym sa */
    char tmp[Max], tmp2[Max];

    for(int x=0;x<maxTab;x++){ //robienie kopii tablic
        tmp[x]=color[x];
        tmp2[x] = guess[x];
    }

    for(int j=0;j<maxTab;j++){
        if(tmp2[j] == tmp[j]){
            tmp[j] = '0';
            tmp2[j] = '2';
        }
    }
    for(int k=0; k<maxTab; k++){
        for(int z=0; z<maxTab; z++){
            if(tmp[k] == tmp2[z]){
                tmp[k] = '3';
                tmp2[z] = '1';
                cout<<"O";
            }
        }
    }
    cout<<endl;
}

void game::IfCorrectSign()const {
    int x =0;
    for(int i=0; i<maxTab; i++){
        if(level == "1"){
            if(guess[i]=='B'||guess[i]=='N'||guess[i]=='C'||guess[i]=='Z'){
                x++;
            }
        }
        if(level == "2"){
            if(guess[i]=='B'||guess[i]=='N'||guess[i]=='C'||guess[i]=='Z'||guess[i]=='F'){
                x++;
            }
        }
        if(level == "3" || level == "4"){
            if(guess[i]=='B'|| guess[i]=='N'|| guess[i]=='C'|| guess[i]=='Z'|| guess[i]=='F'|| guess[i]=='R'|| guess[i]=='G'){
                x++;
            }
        }
    }
    if(x!=maxTab) cout<<"Podano zly znak\n";
}

void game::comunicat() const {
    if(level=="1") {
        cout<<"Twoje kolory do wyboru to: B - bialy, ";
        cout<<"\x1B[31mC - czerwony \033[0m";
        cout<<"\x1B[94mN - niebieski \033[0m";
        cout<<"\x1B[32mZ - zielony \033[0m"<<endl;
        cout<<"X - oznacza dobry kolor w dobrym miejscu, O - dobry kolor w zlym miejscu"<<endl;
        cout<<"Podaj wybrana ilosc znakow: "<<maxTab<<endl;}

    if(level=="2") {
        cout<<"Twoje kolory do wyboru to: B - bialy, ";
        cout<<"\x1B[31mC - czerwony \033[0m";
        cout<<"\x1B[94mN - niebieski \033[0m";
        cout<<"\x1B[32mZ - zielony \033[0m";
        cout<<"\x1B[35mF - fioletowy\033[0m"<<endl;
        cout<<"X - oznacza dobry kolor w dobrym miejscu, O - dobry kolor w zlym miejscu"<<endl;
        cout<<"Podaj wybrana ilosc znakow: "<<maxTab<<endl;
    }

    if(level=="3" || level == "4") {
        cout<<"Twoje kolory do wyboru to: B - bialy, ";
        cout<<"\x1B[31mC - czerwony \033[0m";
        cout<<"\x1B[94mN - niebieski \033[0m";
        cout<<"\x1B[32mZ - zielony \033[0m";
        cout<<"\x1B[35mF - fioletowy \033[0m";
        cout<<"\x1B[95mR - rozowy \033[0m";
        cout<<"\x1B[34mG - granatowy\033[0m"<<endl;
        cout<<"X - oznacza dobry kolor w dobrym miejscu, O - dobry kolor w zlym miejscu"<<endl;
        cout<<"Podaj wybrana ilosc znakow: "<<maxTab<<endl;
    }
}
