#include "enigma.h"
#include <string>
#include <iostream>

Enigma::Enigma(string plugs, string fast_rotor, string ukw)
{
    this->plugs = new Plugboard(plugs);
    this->fast_rotor = new Rotor(fast_rotor.substr(0, 26), stoi(fast_rotor.substr(27, 1)), fast_rotor.substr(29, fast_rotor.size() - 29));
    this->reflector = new Rotor(ukw.substr(0, 26), 1, "A");
}

void Enigma::addRotor(string settings)
{
    this->rotors.push_back(new Rotor(settings.substr(0, 26), stoi(settings.substr(27, 1)), settings.substr(29, settings.size() - 29)));
}

char Enigma::encode(char input)
{
    char p = this->plugs->encode(input); // plugboard

    this->fast_rotor->spin(); // encode through fast rotor
    char r = this->fast_rotor->encode(p);

    string cur_notch = this->fast_rotor->getNotch();
    char last_first = this->fast_rotor->getFirstLetter();

    for (auto rotor : rotors) // next rotors sequence
    {

        if (cur_notch.find(last_first) != string::npos)
        {
            rotor->spin();
        }
        r = rotor->encode(r);
        cur_notch = rotor->getNotch();
    }

    char u = this->reflector->encode(r); // encode through reflector

    for (auto it = this->rotors.rbegin(); it != this->rotors.rend(); it++) // backwards rotors sequence
    {

        u = (*it)->back_encode(u);
    }

    char rs = this->fast_rotor->encode(u); // fast rotor again

    return this->plugs->encode(rs); // plugboard again
}

void Enigma::printRotors(void)
{
    this->fast_rotor->printRotor();
    for (auto rotor : this->rotors)
    {
        rotor->printRotor();
    }
}