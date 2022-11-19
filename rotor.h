#ifndef __ROTOR__
#define __ROTOR__

#include <string>

using namespace std;

#define LETTERS 26
#define ASCII_OFFSET 65
#define NOTCH_OFFSET 18

class Rotor
{
private:
    char wiring[LETTERS];
    char back_wiring[LETTERS];
    char first;
    char notchs[LETTERS];
    bool fast_rotor;

    void spin(void);

public:
    Rotor(string wiring, int first, string notchs, bool fast_rotor);
    int getFirst(void);
    int getNotch(void);
    char encode(char input);
    char back_encode(char input);
};

#endif