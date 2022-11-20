#include "plugboard.h"
#include "rotor.h"
#include "enigma.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string input;

    Enigma m4("AA", "BDFHJLCPRTXVZNYEIWGAKMUSQO:A:01:V", "YRUHQSLDPXNGOKMIEBFZCWVJAT");
    m4.addRotor("AJDKSIRUXBLHWTMCQGZNPYFVOE:A:01:E");
    m4.addRotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ:A:01:Q");

    // m4.printRotors();

    cin >> input;

    for (char i : input)
    {
        cout << m4.encode(i) << endl;
    }
    cout << endl;

    return 0;
}
