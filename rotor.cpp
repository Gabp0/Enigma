#include "rotor.h"
#include <iostream>

Rotor::Rotor(string wiring, int first, int notch)
{
    string keys = "";
    while (wiring.size()) // split the wiring string
    {
        cout << wiring << endl;
        keys = wiring.substr(0, 2);
        wiring.erase(0, 2);
        this->wiring[keys[0]] = keys[1];
        this->wiring[keys[1]] = keys[0];
    }

    this->first = first;
    this->notch = notch;
}

int Rotor::getFirst(void)
{
    return this->first;
}

int Rotor::getNotch(void)
{
    return this->notch;
}

void Rotor::spin(void)
{
    if (++this->first > 26)
        this->first = 1;
}

char Rotor::encode(char input, bool shouldSpin)
{
    if (shouldSpin)
        spin();

    return this->wiring[input];
}