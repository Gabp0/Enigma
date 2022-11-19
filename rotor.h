#ifndef __ROTOR__
#define __ROTOR__

#include <string>
#include <vector>

using namespace std;

#define LETTERS 26
#define ASCII_OFFSET 65

class Rotor
{
private:
    char wiring[LETTERS];
    char back_wiring[LETTERS];
    char first;
    string notchs;

public:
    Rotor(void);
    Rotor(string wiring, int first, string notchs);
    char getFirstLetter(void);
    string getNotch(void);
    void spin(void);
    char encode(char input);
    char back_encode(char input);
    void printRotor(void);
};

#endif