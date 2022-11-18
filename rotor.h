#include <map>
#include <string>

using namespace std;

class Rotor
{
private:
    map<char, char> wiring;
    int first;
    int notch;

    void spin(void);

public:
    Rotor(string wiring, int first, int notch);
    int getFirst(void);
    int getNotch(void);
    char encode(char input, bool shouldSpin);
};
