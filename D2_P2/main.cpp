#include <iostream>
#include <fstream>
using namespace std;
ifstream INPUT("input.txt");

long long horizontal;
long long depth;
string command;
long long units;
long long aim;

int main()
{
    while(INPUT >> command >> units)
    {
        if(command == "forward")
            {
                horizontal += units;
                depth += units*aim;
            }
        if(command == "up")
            aim -= units;
        if(command == "down")
            aim += units;
    }

    cout << horizontal * depth;

return 0;
}
