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
int counter;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };


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

void Move(vector<vector<int>>& Numbers, vector<vector<bool>>& Visited, int l, int c, int& nr)
{
    nr++;
    Visited[l][c] = true;

    for(int it = 0 ; it <= 3; it++)
        if(Visited[l+dx[it]][c+dy[it]] == false && Numbers[l + dx[it]][c + dy[it]] < 9)
            Move(Numbers, Visited, l+dx[it], c+dy[it],nr);
}

int main()
{
    getNumbers(Numbers, N);
    vector<int>Basins;
    vector<vector<bool>> Visited;
    vector<bool>LV(N + 2, false);
    for (int it = 1; it <= Numbers.size(); it++)
        Visited.push_back(LV);

    for (int it = 1; it < Numbers.size() - 1; it++)
        for (int j = 1; j <= N; j++)
            if (Numbers[it][j] < Numbers[it + 1][j] && Numbers[it][j] < Numbers[it][j + 1]
                && Numbers[it][j] < Numbers[it - 1][j] && Numbers[it][j] < Numbers[it][j - 1])
            {
                counter = 0;
                Move(Numbers, Visited, it, j, counter);
                Basins.push_back(counter);
            }

    sort(begin(Basins), end(Basins), [](int A, int B)-> bool {return A > B; });
    cout << Basins[0] * Basins[1] * Basins[2];

}
