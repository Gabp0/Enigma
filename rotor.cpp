#include "rotor.h"
#include <iostream>

void Rotor::setWiring(string wiring)
{
    char l = 'A';
    for (size_t i = 0; i < wiring.size(); i++)
    {
        this->wiring[l] = wiring[i];
        l++;
    }
}

Rotor::Rotor(string wiring, int first, int notch)
{
    setWiring(wiring);
    this->first = first;
    this->notch = notch;
    this->extra_n = 0;
}

Rotor::Rotor(string wiring, int first, int notch, int extra_n)
{
    setWiring(wiring);
    this->first = first;
    this->notch = notch;
    this->extra_n = extra_n;
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