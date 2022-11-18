#include "plugboard.h"

Plugboard::Plugboard(string settings)
{
    string keys = "";
    while (settings.size()) // split the settings string
    {
        keys = settings.substr(0, 2);
        settings.erase(0, 2);
        this->keymap[keys[0]] = keys[1];
        this->keymap[keys[1]] = keys[0];
    }
}

char Plugboard::encode(char input)
{
    if (this->keymap.find(input) != this->keymap.end())
        return this->keymap[input];
    return input;
}
