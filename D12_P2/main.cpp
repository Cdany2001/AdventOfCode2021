#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <math.h>
#include <stack>
#include<string.h>
#include<map>
using namespace std;
ifstream INPUT("input.txt");
map<string, vector<string>> Adj;
map<string, int> Visited;
int Total;

bool isLow(string str)
{
    return str[0] >= 'a' && str[0] <= 'z';
}

void BruteTraversal(string Str, map<string, vector<string>>& Adj, map<string, int>& Visited)
{
    if (isLow(Str))
        Visited[Str]++;

    bool canVisit2 = true;
    for (auto& it : Visited)
        if (it.second > 1)
            canVisit2 = false;

    if (Str != "end")
    {
        for (auto nextStr : Adj[Str])
        {
            if (nextStr != "start")
            {
                if(canVisit2)
                    BruteTraversal(nextStr, Adj, Visited);
                else
                  if (Visited[nextStr] == 0)
                    BruteTraversal(nextStr, Adj, Visited);
            }
        }
    }
    else
        Total++;

    if (isLow(Str))
        Visited[Str]--;
}


void getCaves( map<string, vector<string>>& Adj, map<string, int>& Visited)
{
    string str;
    while (INPUT >> str)
    {
        int it = str.find('-');
        string x;
        string y;

        x = str.substr(0, it );
        y = str.substr(it + 1, str.size() - it);

        Adj[x].push_back(y);
        Adj[y].push_back(x);
        Visited[x] = 0;
        Visited[y] = 0;
    }
}

int main()
{
    getCaves(Adj, Visited);
    BruteTraversal("start", Adj, Visited);
    cout << Total;
}
