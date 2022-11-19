#include "plugboard.h"
#include "rotor.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Plugboard plugs("AOHIMUSNVXZQ");
    char input = ' ';
    Rotor r("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", true);

    do
    {
        cin >> input;
        cout << "encode: " << r.encode(toupper(input)) << endl;
    } while (input != EOF);

    return 0;
}
