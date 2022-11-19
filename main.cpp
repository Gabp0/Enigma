#include "plugboard.h"
#include "rotor.h"
#include "enigma.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string input;

    Enigma m4("BWCTEFGPHJIXKZLONQSU", "ESOVPZJAYQUIRHXLNFTGKDCMWB:A:16:J", "ENKQAUYWJICOPBLMDXZVFTHRGS");
    m4.addRotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ:A:22:Q");
    m4.addRotor("BDFHJLCPRTXVZNYEIWGAKMUSQO:A:11:V");
    m4.printRotors();

    cin >> input;

    for (char i : input)
    {
        cout << m4.encode(i);
    }
    cout << endl;

    return 0;
}
