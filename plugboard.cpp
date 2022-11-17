#include "plugboard.h"
#include <exception>
#include <iostream>
#include <bits/stdc++.h>

Plugboard::Plugboard(string settings)
{
    transform(settings.begin(), settings.end(), settings.begin(), ::tolower); // settings to lowercase
    string keys = "";
    size_t deli_pos = 0;
    while (settings.size() > 2) // split the settings string
    {
        deli_pos = settings.find(delimiter);
        keys = settings.substr(0, deli_pos);
        settings.erase(0, deli_pos + 1);
        this->keymap[keys[0]] = keys[1];
        this->keymap[keys[1]] = keys[0];
    }
    keys = settings.substr(0, 2);
    this->keymap[keys[0]] = keys[1];
    this->keymap[keys[1]] = keys[0];
}

char Plugboard::encode(char input)
{
    if (this->keymap.find(tolower(input)) != this->keymap.end())
        return this->keymap[tolower(input)];
    return tolower(input);
}
