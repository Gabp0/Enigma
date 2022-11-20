#include "rotor.h"
#include <iostream>

Rotor::Rotor(void)
{
    for (size_t i = 0; i < ASIZE; i++)
    {
        this->wiring[i] = i;
        this->back_wiring[i] = i;
    }
    this->first = 0;
}

Rotor::Rotor(string wiring, char first, int ringsetting, string notchs)
{
    for (size_t i = 0; i < wiring.size(); i++)
    {
        this->wiring[i] = wiring[(i + ringsetting - 1) % ASIZE] - ASCII_OFFSET;
        this->back_wiring[wiring[i] - ASCII_OFFSET] = (i + ringsetting - 1) % ASIZE;
    }

    this->turnover = notchs;
    this->first = first - ASCII_OFFSET;
    this->ringsetting = ringsetting;
}

char Rotor::getFirstLetter(void)
{
    return this->first + ASCII_OFFSET;
}

string Rotor::getNotch(void)
{
    return this->turnover;
}

void Rotor::spin(void)
{
    first = (first + 1) % ASIZE;
}

char Rotor::encode(char input)
{
    int i = input - ASCII_OFFSET;
    return ((this->wiring[(i - first) % ASIZE] + first) % ASIZE) + ASCII_OFFSET;
}

char Rotor::back_encode(char input)
{
    int i = input - ASCII_OFFSET;
    return ((this->back_wiring[(i - first) % ASIZE] + first) % ASIZE) + ASCII_OFFSET;
}

void Rotor::printRotor(void)
{
    char out = ' ';
    for (auto wire : this->wiring)
    {
        out = wire + ASCII_OFFSET;
        cout << out;
    }
    cout << ":" << this->getFirstLetter() << ":" << this->ringsetting << ":" << this->turnover << endl;
}
