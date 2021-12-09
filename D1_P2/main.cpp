#include <iostream>
#include <fstream>
using namespace std;
ifstream INPUT("input.txt");

int A, B, C, D;
int counter;

int main()
{
    INPUT >> A >> B >> C;
    while(INPUT >> D)
    {
        if(A < D)
            counter++;
       A = B;
       B = C;
       C = D;
    }

    cout << counter;
return 0;
}
