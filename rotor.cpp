#include "rotor.h"
#include <iostream>

Rotor::Rotor(void)
{
    for (size_t i = 0; i < LETTERS; i++)
    {
        this->wiring[i] = i;
        this->back_wiring[i] = i;
    }
    this->first = 0;
}

Rotor::Rotor(string wiring, int first, string notchs)
{
    for (size_t i = 0; i < wiring.size(); i++)
    {
        this->wiring[i] = wiring[i] - ASCII_OFFSET;
        this->back_wiring[wiring[i] - ASCII_OFFSET] = i;
    }
    this->notchs = notchs;
    this->first = first - 1;
}

char Rotor::getFirstLetter(void)
{
    return this->first + ASCII_OFFSET;
}

string Rotor::getNotch(void)
{
    return this->notchs;
}

void Rotor::spin(void)
{
    first = (first + 1) % LETTERS;
}

char Rotor::encode(char input)
{
    return this->wiring[(input - ASCII_OFFSET + first) % LETTERS] + ASCII_OFFSET;
}

char Rotor::back_encode(char input)
{
    return this->back_wiring[(input - ASCII_OFFSET + first) % LETTERS] + ASCII_OFFSET;
}

void Rotor::printRotor(void)
{
    char out = ' ';
    for (auto wire : this->wiring)
    {
        out = wire + ASCII_OFFSET;
        cout << out;
    }
    cout << ":" << first + 1 << ":" << this->notchs << endl;
}

// EKUTGBH