#include <iostream>
#include <map>
#include <fstream>
#include <string.h>
using namespace std;
ifstream INPUT("input.txt");
map<string, string> Pairs;
map<string, unsigned long long> FrPair;
string Str;

void getInput(map<string, string>& Pairs, map<string,unsigned long long>& FrPair)
{

    INPUT >> Str;
    for (unsigned long long it = 1; it < Str.size(); it++)
        FrPair[Str.substr(it - 1, 2)]++;

    string s, t;
    while (INPUT >> s >> t >> t)
        Pairs[s] = t;
}

void day(map<string, string>& Pairs, map<string, unsigned long long>& FrPair)
{
    map<string, unsigned long long> newFrPair;
    for (auto& p : FrPair)
    {
        string s = p.first;
        newFrPair[s.substr(0,1)+Pairs[s]] += p.second;
        newFrPair[ Pairs[s]+ s.substr(1, 1) ] += p.second;
    }
    FrPair = newFrPair;
}

unsigned long long difFrq(map<string, unsigned long long>& FrPair)
{
    map<char, unsigned long long> Fr;
    for (auto p : FrPair)
    {
        Fr[p.first[0]] += p.second;
        Fr[p.first[1]] += p.second;
    }

    Fr[Str[0]]++;
    Fr[Str[Str.size() - 1]]++;

    unsigned long long maxi = 0;
    for (auto pair : Fr)
        if (pair.second > maxi)
            maxi = pair.second;
    unsigned long long mini = maxi;
    for (auto pair : Fr)
        if (pair.second < mini)
            mini = pair.second;

    return maxi/2 - mini/2;
}

int main()
{
    getInput(Pairs, FrPair);

    for (unsigned long long d = 1; d <= 40; d++)
        day(Pairs, FrPair);

    cout << difFrq(FrPair);
    return 0;
}
