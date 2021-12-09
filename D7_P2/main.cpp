#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <math.h>
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

    int target = ceil(accumulate(begin(Numbers), end(Numbers), 0) / (1.0 * Numbers.size()));
    int Total = 0;
    int dif;
    for (auto it : Numbers)
    {
        dif = abs(it - target);
        Total += dif * (dif + 1) / 2;
    }
    int Total2 = 0;
    target--;
    for (auto it : Numbers)
    {
        dif = abs(it - target);
        Total2 += dif * (dif + 1) / 2;
    }
    cout << min(Total,Total2);
}
