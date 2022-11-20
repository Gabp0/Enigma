#include "enigma.h"
#include <string>
#include <iostream>

Enigma::Enigma(string plugs, string fast_rotor, string ukw)
{
    this->plugs = new Plugboard(plugs);
    this->fast_rotor = new Rotor(fast_rotor.substr(0, 26), fast_rotor.substr(27, 1)[0], stoi(fast_rotor.substr(29, 2)), fast_rotor.substr(32, fast_rotor.size() - 32));
    this->reflector = new Rotor(ukw, 'A', 1, "A");
}

void Enigma::addRotor(string settings)
{ // SOVPZJAYQUIRHXLNFTGKDCMWB:A:16:T
    this->rotors.push_back(new Rotor(settings.substr(0, 26), settings.substr(27, 1)[0], stoi(settings.substr(29, 2)), settings.substr(32, settings.size() - 32)));
}

char Enigma::encode(char input)
{
    char prevf = this->fast_rotor->getFirstLetter();
    string cur_notch = this->fast_rotor->getNotch();
    this->fast_rotor->spin(); // spin fast rotor

    // for (auto rotor : rotors) // next rotors sequence
    // {
    //     if (cur_notch.find(prevf) != string::npos)
    //     {
    //         prevf = rotor->getFirstLetter();
    //         rotor->spin();
    //     }
    //     else
    //     {
    //         prevf = rotor->getFirstLetter();
    //     }
    // }

    char ct = this->plugs->encode(input); // plugboard
    cout << "plugs: " << ct << endl;

    ct = this->fast_rotor->encode(ct);
    cout << "fr: " << ct << endl;

    for (auto rotor : rotors) // next rotors sequence
    {
        ct = rotor->back_encode(ct);
        cout << "fr: " << ct << endl;
    }

    ct = this->reflector->encode(ct); // encode through reflector
    cout << "r: " << ct << endl;

    for (auto it = this->rotors.rbegin(); it != this->rotors.rend(); it++) // backwards rotors sequence
    {

        ct = (*it)->encode(ct);
        cout << "br: " << ct << endl;
    }

    ct = this->fast_rotor->encode(ct); // fast rotor again
    cout << "bf: " << ct << endl;

    cout << "plugs: " << this->plugs->encode(ct) << endl;

    return this->plugs->encode(ct); // plugboard again
}

void Enigma::printRotors(void)
{
    this->fast_rotor->printRotor();
    for (auto rotor : this->rotors)
    {
        rotor->printRotor();
    }
}