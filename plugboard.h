#ifndef __PLUGS__
#define __PLUGS__

#include <string>
#include <map>

using namespace std;

#define SETTINGS_SIZE 17

class Plugboard
{
private:
    map<char, char> keymap;

public:
    const string delimiter = " ";
    Plugboard(string setting);
    char encode(char input);
    //~Plugboard();
};

#endif
