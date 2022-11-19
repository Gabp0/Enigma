#include "enigma.h"

void Enigma::setRotor(WHEELS rotor, int pos, int first, int notch)
{
}

Enigma::Enigma(WHEELS rotors[3], ZSTW extra_r, UKW reflector, string plugs)
{
    this->plugs = new Plugboard(plugs);
}