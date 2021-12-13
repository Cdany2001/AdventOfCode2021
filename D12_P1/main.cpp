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
map<string, bool> Visited;
int Total;

bool isLow(string str)
{
    return str[0] >= 'a' && str[0] <= 'z';
}

void BruteTraversal(string Str, map<string, vector<string>>& Adj, map<string, bool>& Visited)
{
    if (isLow(Str))
        Visited[Str] = true;

    if (Str != "end")
    {
        for (auto nextStr : Adj[Str])
            if (Visited[nextStr] == false)
                BruteTraversal(nextStr, Adj, Visited);
    }
    else
        Total++;

    if (isLow(Str))
        Visited[Str] = false;
}


void getCaves( map<string, vector<string>>& Adj, map<string, bool>& Visited)
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
        Visited[x] = false;
        Visited[y] = false;
    }
}

int main()
{
    getCaves(Adj, Visited);
    BruteTraversal("start", Adj, Visited);
    cout << Total;
}
