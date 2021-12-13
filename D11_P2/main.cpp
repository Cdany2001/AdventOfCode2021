#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <math.h>
#include <stack>
#include<string.h>
using namespace std;
ifstream INPUT("input.txt");
string strNumbers;
vector<vector<int>> Numbers;
vector<long long> Complete;
int Total;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };


void getNumbers(vector<vector<int>>& Numbers)
{
    while (INPUT >> strNumbers)
    {
        vector<int> v;
        for (auto ch : strNumbers)
            v.push_back((ch - '0'));
        Numbers.push_back(v);
    }
}

void startGlow(int x, int y, vector<vector<int>>& Numbers, vector<vector<bool>>& Glowed)
{
    int newx, newy;
    Glowed[x][y] = true;

    for (int it = 0; it < 8; it++)
    {
        newx = x + dx[it];
        newy = y + dy[it];
        if (newx >= 0 && newx <= 9 && newy >= 0 && newy <= 9)
        {
            Numbers[newx][newy]++;
            if (Numbers[newx][newy] > 9 && Glowed[newx][newy] == false)
                startGlow(newx, newy, Numbers, Glowed);
        }
    }
}

bool day(vector<vector<int>>& Numbers)
{
    vector<vector<bool>> Glowed(10, vector<bool>(10, false));
    for (int l = 0; l < 10; l++)
        for (int c = 0; c < 10; c++)
            Numbers[l][c]++;

    for (int l = 0; l < 10; l++)
        for (int c = 0; c < 10; c++)
            if (Numbers[l][c] > 9 && Glowed[l][c] == false)
                startGlow(l, c, Numbers, Glowed);

    int nrGlow = 0;
    for (int l = 0; l < 10; l++)
        for (int c = 0; c < 10; c++)
            if (Glowed[l][c] == true)
            {
                nrGlow++;
                Numbers[l][c] = 0;
            }
    if (nrGlow == 100)
        return true;
    return false;
}



int main()
{
    getNumbers(Numbers);
    Total = 1;
    while (day(Numbers) == false)
        Total++;

    cout << Total;
}
