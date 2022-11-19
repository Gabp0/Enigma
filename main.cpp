#include "plugboard.h"
#include "rotor.h"
#include "enigma.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string input;

    Enigma m4("AOHIMUSNVXZQ", "ESOVPZJAYQUIRHXLNFTGKDCMWB:1:R", "ENKQAUYWJICOPBLMDXZVFTHRGS");
    m4.addRotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ:5:Y");
    m4.addRotor("BDFHJLCPRTXVZNYEIWGAKMUSQO:7:D");

    cin >> input;

    for (char i : input)
    {
        cout << m4.encode(i);
    }
    cout << endl;

    return 0;
}
