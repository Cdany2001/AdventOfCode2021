#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
ifstream INPUT("input.txt");
string strNumbers;
vector<int>Numbers;

void getNumbers(string strNumbers, vector<int>& Numbers)
{
    int x = 0;
    strNumbers += ",";
    for (auto ch : strNumbers)
        if (ch == ',')
        {
            Numbers.push_back(x);
            x = 0;
        }
        else
            x = x * 10 + (ch - '0');
}

int main()
{
    INPUT >> strNumbers;
    getNumbers(strNumbers, Numbers);

    sort(begin(Numbers), end(Numbers));

    int target = Numbers[Numbers.size() / 2];
    int Total = 0;
    for (auto it : Numbers)
        Total += (abs(target - it));

    cout << Total;
}
