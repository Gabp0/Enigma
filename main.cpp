#include "plugboard.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char input = argv[1][0];

    Plugboard plugs("AOHIMUSNVXZQ");
    cout << plugs.encode(input) << endl;

    return 0;
}
    