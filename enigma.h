#ifndef __ENIGMA__
#define __ENIGMA__

#include "rotor.h"
#include "plugboard.h"
#include <map>
#include <string>

class Enigma
{
    enum WHEELS
    {
        I,
        II,
        III,
        IV,
        V,
        VI,
        VII,
        VIII
    };
    enum ZSTW
    {
        beta,
        gamma
    };
    enum UKW
    {
        b,
        c
    };

private:
    Plugboard *plugs;
    Rotor *rotors[3];
    Rotor *extra_rotor;
    Rotor *reflector;
    void setRotor(WHEELS rotor, int pos, int first, int notch);

public:
    Enigma(WHEELS rotors[3], ZSTW extra_r, UKW reflector, string plugs);
};

#endif