#include <iostream>
using namespace std;

const int Max = 10;

class game{
private:
    char *color;
    char *guess;
    int maxRound{};

public:
    game();
    ~game();
    void showColors();
    void Guess();
    int Round() const;
    bool check_number(string str);
    void StrikeWin();
    void StrikeLose();
    void whereColor()const;
    void kolory();
    bool checkGuess();
    void IfCorrectSign()const;
    void chooseLevel();
    void upperLetter();
    void comunicat() const;
protected:
    string level{};
    int maxTab = 0;
    int strike = 0;

};



