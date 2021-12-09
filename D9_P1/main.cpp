#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <math.h>
using namespace std;
ifstream INPUT("input.txt");
string strNumbers;
vector<vector<int>> Numbers;
int N;

void getNumbers(vector<vector<int>>& Numbers, int &nr)
{
    INPUT >> strNumbers;
    nr = strNumbers.size();
    vector<int>Up(strNumbers.size() + 2, 10);
    Numbers.push_back(Up);
    Numbers.push_back({});
    Numbers[1].push_back(10);
    for (auto ch : strNumbers)
        Numbers[1].push_back(ch - '0');
    Numbers[1].push_back(10);

    int it = 2;
    while (INPUT >> strNumbers)
    {
        Numbers.push_back({});
        Numbers[it].push_back(10);
        for (auto ch : strNumbers)
            Numbers[it].push_back(ch - '0');
        Numbers[it].push_back(10);
        it++;
    }

    Numbers.push_back(Up);
}

int main()
{
    getNumbers(Numbers, N);
    int Total = 0;

    for (int it = 1; it < Numbers.size() - 1; it++)
        for (int j = 1; j <= N; j++)
            if (Numbers[it][j] < Numbers[it + 1][j] && Numbers[it][j] < Numbers[it][j + 1]
                && Numbers[it][j] < Numbers[it - 1][j] && Numbers[it][j] < Numbers[it][j - 1])
                Total += (1 + Numbers[it][j]);
    cout << Total;
}
