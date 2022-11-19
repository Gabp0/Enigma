#ifndef __ENIGMA__
#define __ENIGMA__

#include "rotor.h"
#include "plugboard.h"
#include <vector>
#include <string>

class Enigma
{
private:
#define NOTCH_OFFSET 8

    Plugboard *plugs;
    Rotor *fast_rotor;
    vector<Rotor *> rotors;
    Rotor *reflector;

public:
    Enigma(string plugs, string fast_rotor, string ukw);
    void addRotor(string rotor);
    char encode(char input);
    void printRotors(void);
};

#endif