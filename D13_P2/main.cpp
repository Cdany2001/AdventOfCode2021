#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<deque>
using namespace std;
ifstream INPUT("input.txt");
map<pair<int, int>, int> Paper;
vector<pair<char, int>>Commands;
int Total;

void getNumbers(string s, pair<int, int>& p)
{
    p = make_pair(0, 0);
    s += ",";

    int it = 0;
    while (s[it] != ',')
    {
        p.first = p.first * 10 + (s[it] - '0');
        it++;
    }
    it++;
    while (s[it] != ',')
    {
        p.second = p.second * 10 + (s[it] - '0');
        it++;
    }
    it++;
}

void getInput(map<pair<int, int>, int>& Paper, vector<pair<char, int>>& Commands)
{
    string line;
    int l = 0;
    int c = 0;
    pair<int, int> p;
    while (getline(INPUT, line))
    {
        if (line == "")
            break;

        getNumbers(line, p);
        Paper[p]++;
    }

    while (getline(INPUT, line))
    {
        line += ",";
        int it = line.find('=');
        char ch = line[it - 1];
        int nr = 0;
        it++;
        while (line[it] != ',')
        {
            nr = nr * 10 + (line[it] - '0');
            it++;
        }

        Commands.emplace_back(ch, nr);
    }
}

void executeCommand(map<pair<int, int>, int>& Paper, pair<char, int> command)
{
    set<pair<int, int>> ToErase;

    if (command.first == 'x')
    {
        for (auto it : Paper)
            if (it.first.first >= command.second)
                ToErase.insert(it.first);

        for (auto& it : ToErase)
        {
            pair<int, int> p = it;
            if (it.first != command.second)
            {
                p.first = command.second + (command.second - p.first);
                Paper[p]++;
            }
            Paper.erase(it);
        }
    }

    if (command.first == 'y')
    {
        for (auto it : Paper)
            if (it.first.second >= command.second)
                ToErase.insert(it.first);

        for (auto& it : ToErase)
        {
            pair<int, int> p = it;
            if (it.second != command.second)
            {
                p.second = command.second + (command.second - p.second);
                Paper[p]++;
            }
            Paper.erase(it);
        }
    }
}

void print(map<pair<int, int>, int> Paper)
{
    for (int l = 0; l < 60; l++)
    {
        for (int c = 0; c < 40; c++)
            if (Paper[make_pair(l, c)] != 0)
                cout << '#';
            else
                cout << '.';
        cout << endl;
    }
    cout << endl << endl;
}

int main()
{
    getInput(Paper, Commands);
    for(auto it : Commands)
      executeCommand(Paper, it);
    print(Paper);
}
