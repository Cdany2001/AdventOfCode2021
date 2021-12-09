#include <iostream>
#include <fstream>
using namespace std;
ifstream INPUT("input.txt");

int horizontal;
int depth;
string command;
int units;

int main()
{
    while(INPUT >> command >> units)
    {
        if(command == "forward")
            horizontal += units;
        if(command == "up")
            depth -= units;
        if(command == "down")
            depth += units;
    }

    cout << horizontal * depth;

return 0;
}
