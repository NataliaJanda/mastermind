#include <iostream>

using namespace std;

const int Max = 10;

class game{
private:
    char *color;
    char *guess;
    int maxRound{};
    char *sequencex;
    char *sequenceo;
    char *sequencexo;
public:
    game();
    ~game();
    void showColors();
    char *showGuess();
    void Guess();
    int Round() const;
    int Tab() const;
    char *Sequenceo();
    char *Sequencex();
    bool playAgain();
    static bool check_number(string str);
    void StrikeWin();
    void StrikeLose();
    void whereColor();
    void kolory();
    bool checkGuess();
    bool IfCorrectSign();
    void chooseLevel();
    void upperLetter();
    void comunicat() const;
protected:
    string level{};
    int maxTab = 0;
    int strike = 0;

};



