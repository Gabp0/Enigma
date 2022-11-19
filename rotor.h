#ifndef __ROTOR__
#define __ROTOR__

#include <string>
#include <vector>

using namespace std;

class Rotor
{
private:
#define ASIZE 26
#define ASCII_OFFSET 65
    char wiring[ASIZE];
    char back_wiring[ASIZE];
    char first;
    int ringsetting;
    string turnover;

public:
    Rotor(void);
    Rotor(string wiring, char first, int ringsetting, string notchs);
    char getFirstLetter(void);
    string getNotch(void);
    void spin(void);
    char encode(char input);
    char back_encode(char input);
    void printRotor(void);
};

#endif