#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <list>
using namespace std;
ifstream INPUT("input.txt");
string combination;
list<string> comb(10);
int Total;

bool code(set<char>Set, string A)
{
    bool ok = true;
    for (auto ch : A)
        if (Set.find(ch) == end(Set))
            ok = false;
    if (A.size() != Set.size())
        ok = false;
    return ok;
}

void decode(list<string>& comb)
{
    map<int, set<char>> Seg;
    for (auto it : comb)
        if (it.size() == 2)
            for (auto ch : it)
                Seg[1].insert(ch);
    comb.remove_if([&](string A)->bool {return code(Seg[1], A); });
    for (auto it : comb)
        if (it.size() == 3)
            for (auto ch : it)
                Seg[7].insert(ch);
    comb.remove_if([&](string A)->bool {return code(Seg[7], A); });
    for (auto it : comb)
        if (it.size() == 4)
            for (auto ch : it)
                Seg[4].insert(ch);
    comb.remove_if([&](string A)->bool {return code(Seg[4], A); });
    for (auto it : comb)
        if (it.size() == 7)
            for (auto ch : it)
                Seg[8].insert(ch);
    comb.remove_if([&](string A)->bool {return code(Seg[8], A); });

    for (auto it : comb)
        if (it.size() == 6)
        {
            bool is6 = true;
            for (auto ch : Seg[1])
                if (it.find(ch) == string::npos)
                    is6 = false;
            if(!is6)
                for (auto ch : it)
                    Seg[6].insert(ch);
        }
    comb.remove_if([&](string A)->bool {return code(Seg[6], A); });

    for (auto it : comb)
        if (it.size() == 5)
        {
            bool is3 = true;
            for (auto ch : Seg[1])
                if (it.find(ch) == string::npos)
                    is3 = false;
            if (is3)
                for (auto ch : it)
                    Seg[3].insert(ch);
        }
    comb.remove_if([&](string A)->bool {return code(Seg[3], A); });

    for (auto it : comb)
        if (it.size() == 5)
        {
            bool is5 = true;
            for(auto ch : it)
                if(Seg[6].find(ch) == end(Seg[6]))
                    is5 = false;
            if (is5)
                for (auto ch : it)
                    Seg[5].insert(ch);
        }
    comb.remove_if([&](string A)->bool {return code(Seg[5], A); });

    for (auto it : comb)
        if (it.size() == 6)
        {
            bool is9 = true;
            for (auto ch : Seg[5])
                if (it.find(ch) == string::npos)
                    is9 = false;
            if (is9)
                for (auto ch : it)
                    Seg[9].insert(ch);
        }
    comb.remove_if([&](string A)->bool {return code(Seg[9], A); });

    for (auto it : comb)
        if (it.size() == 5)
            for (auto ch : it)
                Seg[2].insert(ch);
    for (auto it : comb)
        if (it.size() == 6)
            for (auto ch : it)
                Seg[0].insert(ch);

    int nr = 0;
    for (int a = 1; a <= 4; a++)
    {
        INPUT >> combination;
        for (auto it : Seg)
        {
            bool ok = true;
            for (auto ch : combination)
                if (it.second.find(ch) == end(it.second))
                    ok = false;
            if (it.second.size() != combination.size())
                ok = false;
            if (ok)
                nr = nr * 10 + it.first;
        }
    }
    Total += nr;
}

int main()
{
    while (INPUT >> combination)
    {
        comb.clear();
        comb.push_back(combination);
        for (int it = 1; it <= 9; it++)
        {
            INPUT >> combination;
            comb.push_back(combination);
        }
        INPUT >> combination;

        decode(comb);
    }
    cout << Total;
return 0;
}
