#include <iostream>
#include <fstream>
using namespace std;
ifstream INPUT("input.txt");

int before;
int after;
int counter;

int main()
{
    INPUT >> before;
    while(INPUT >> after)
    {
        if(before < after)
            counter++;
        before = after;
    }

    cout << counter;
return 0;
}
