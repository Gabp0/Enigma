#include "rotor.h"
#include <iostream>

Rotor::Rotor(string wiring, int first, string notchs, bool fast_rotor)
{
    for (size_t i = 0; i < wiring.size(); i++)
    {
        this->wiring[i] = wiring[i] - ASCII_OFFSET;
        this->back_wiring[wiring[i] - ASCII_OFFSET] = i;
    }
    for (size_t i = 0; i < notchs.size(); i++)
    {
        this->notchs[i] = notchs[i] - ASCII_OFFSET;
    }
    this->first = first - 1;
    this->fast_rotor = fast_rotor;
}

int Rotor::getFirst(void)
{
    return this->first + 1;
}

void Rotor::spin(void)
{
    if (fast_rotor)
    {
        first = (first + 1) % LETTERS;
        return;
    }

    for (auto notch : this->notchs)
    {
        if (((first + NOTCH_OFFSET) % LETTERS) == notch)
        {
            first = (first + 1) % LETTERS;
            return;
        }
    }
}

char Rotor::encode(char input)
{
    spin();
    return this->wiring[(input - ASCII_OFFSET + first) % LETTERS] + ASCII_OFFSET;
}

char Rotor::back_encode(char input)
{
    return this->back_wiring[(input - ASCII_OFFSET + first) % LETTERS] + ASCII_OFFSET;
}