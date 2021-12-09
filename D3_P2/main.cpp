#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
ifstream INPUT("input.txt");
string reading;
vector<string> Readings;
string oxygen;
string CO2;

int convertToDecimal(string vec)
{
    int pow = 1;
    int Sum = 0;
    reverse(begin(vec), end(vec));

    for (auto& it : vec)
    {
        if (it-'0')
            Sum += pow;
        pow *= 2;
    }

    return Sum;
}

char mostCommon(int nr1, int total)
{
    if (nr1 >= (total - nr1))
        return '1';
    else
        return '0';
}

char lessCommon(int nr1, int total)
{
    if (nr1 >= (total - nr1))
        return '0';
    else
        return '1';
}

string level(vector<string>& Readings, char (*func)(int, int))
{
    int pos = 0;
    set<int>Answer;
    for (int it = 0; it < Readings.size(); it++)
        Answer.insert(it);
    while (pos < Readings[0].size() && Answer.size() > 1)
    {
        char ch;
        int nr1 = 0;

        for (auto it : Answer)
            if (Readings[it][pos] == '1')
                nr1++;
        ch = func(nr1, Answer.size());

        set<int> Remove;
        for (auto it : Answer)
            if (Readings[it][pos] != ch)
                Remove.insert(it);
        for (auto it : Remove)
            Answer.erase(it);
        pos++;
    }

    return Readings[(*begin(Answer))];
}

int main()
{
    while (INPUT >> reading)
        Readings.push_back(reading);

    oxygen = level(Readings, &mostCommon);
    CO2 = level(Readings, &lessCommon);
    cout << convertToDecimal(oxygen) * convertToDecimal(CO2);
    return 0;
}

