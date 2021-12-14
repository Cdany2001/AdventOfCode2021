#include <iostream>
#include <map>
#include <fstream>
#include <string.h>
using namespace std;
ifstream INPUT("input.txt");
map<string, string> Pairs;
string Str;

void getInput(map<string, string>& Pairs, string& Str)
{
    INPUT >> Str;

    string s, t;
    while (INPUT >> s >> t >> t)
        Pairs[s] = t;
}

void day(map<string, string>& Pairs, string& Str)
{
    int remain = Str.size() - 1;
    int it = 1;

    while (remain != 0)
    {
        Str = Str.substr(0, it) + Pairs[Str.substr(it - 1, 2)] + Str.substr(it, remain);
        remain--;
        it += 2;
    }
}

int difFrq(string Str)
{
    map<char, int> Fr;
    for (auto ch : Str)
        Fr[ch]++;

    int maxi = 0;
    for (auto pair : Fr)
        if (pair.second > maxi)
            maxi = pair.second;
    int mini = maxi;
    for (auto pair : Fr)
        if (pair.second < mini)
            mini = pair.second;

    return maxi - mini;
}

int main()
{
    getInput(Pairs, Str);

    for (int d = 1; d <= 10; d++)
        day(Pairs, Str);

    cout << difFrq(Str);

    return 0;
}
