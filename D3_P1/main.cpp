#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream INPUT("input.txt");
string value;
vector<int> epsilon;
vector<int> gama;
int Nr = 1;

void updateReadings(string value,vector<int>& gama,vector<int>& epsilon)
{
    for(int it = 0; it < value.size(); it++)
    {
        gama[it]+= (value[it]-'0');
        epsilon[it]+= (value[it]-'0');
    }
}

int createNumber(vector<int> vec)
{
    int pow = 1;
    int Sum = 0;
    reverse(begin(vec), end(vec));

    for(auto&it : vec)
    {
        if(it)
            Sum += pow;
        pow *= 2;
    }

    return Sum;
}

int main()
{
    INPUT >> value;
    epsilon.resize(value.size());
    gama.resize(value.size());
    updateReadings(value,gama,epsilon);
    while( INPUT >> value)
      {
          updateReadings(value,gama,epsilon);
          Nr++;
      }

    for(auto& it: gama)
        if(it > Nr/2)
            it = 1;
        else
            it = 0;
    for(auto& it: epsilon)
        if(it < Nr/2)
            it = 1;
        else
            it = 0;

    cout << createNumber(gama) * createNumber(epsilon);
    return 0;
}
