#include "enigma.h"

void Enigma::setRotor(WHEELS rotor, int pos, int first, int notch)
{
    switch (rotor)
    {
    case I:
        this->rotors[pos] = new Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", first, notch);
        break;
    case II:
        this->rotors[pos] = new Rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", first, notch);
        break;
    case III:
        this->rotors[pos] = new Rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", first, notch);
        break;
    case IV:
        this->rotors[pos] = new Rotor("ESOVPZJAYQUIRHXLNFTGKDCMWB", first, notch);
        break;
    case V:
        this->rotors[pos] = new Rotor("VZBRGITYUPSDNHLXAWMJQOFECK", first, notch);
        break;
    case VI:
        this->rotors[pos] = new Rotor("JPGVOUMFYQBENHZRDKASXLICTW", first, notch);
        break;
    case VII:
        this->rotors[pos] = new Rotor("NZJHGRCXMYSWBOUFAIVLPEKQDT", first, notch);
        break;
    case VIII:
        this->rotors[pos] = new Rotor("FKQHTLXOCBJSPDZRAMEWNIUYGV", first, notch);
        break;
    default:
    }
}

Enigma::Enigma(WHEELS rotors[3], ZSTW extra_r, UKW reflector, string plugs)
{
    this->plugs = new Plugboard(plugs);
}