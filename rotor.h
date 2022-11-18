#ifndef __ROTOR__
#define __ROTOR__

#include <map>
#include <string>

using namespace std;

class Rotor
{
private:
    map<char, char> wiring;
    int first;
    int notch;
    int extra_n;

    void setWiring(string wiring);
    void spin(void);

public:
    Rotor(string wiring, int first, int notch);
    Rotor(string wiring, int first, int notch, int extra_n);
    int getFirst(void);
    int getNotch(void);
    char encode(char input, bool shouldSpin);
};

#endif