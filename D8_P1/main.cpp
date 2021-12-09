#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
ifstream INPUT("input.txt");
string combination;
int counter;

int main()
{
    while (INPUT >> combination)
    {
        for (int it = 1; it <= 10; it++)
            INPUT >> combination;
        for (int it = 1; it <= 4; it++)
        {
            INPUT >> combination;
            if (combination.size() == 2  combination.size() == 4  combination.size() == 3 || combination.size() == 7)
                counter++;
        }
    }

    cout << counter;
return 0;
}
