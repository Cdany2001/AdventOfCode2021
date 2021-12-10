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
vector<string> Numbers;
vector<long long> Complete;
int Total;


void getNumbers(vector<string>& Numbers)
{
    while(INPUT >> strNumbers)
        Numbers.push_back(strNumbers);
}

void getPoints(string str,vector<long long>&Complete)
{
    stack<char> Stack;
    int ok = 1;
    long long nr = 0;

    for (int it = 0; it < str.size() && ok; it++)
    {
        switch (str[it])
        {
        case '(':
            Stack.push('(');
            break;
        case '[':
            Stack.push('[');
            break;
        case '{':
            Stack.push('{');
            break;
        case '<':
            Stack.push('<');
            break;
        case ')':
            if ( Stack.top() != '(')
            {
                ok = 0;
            }
            else
                Stack.pop();
            break;
        case ']':
            if (Stack.top() != '[')
            {
                ok = 0;
            }
            else
                Stack.pop();
            break;
        case '}':
            if ( Stack.top() != '{')
            {
                ok = 0;
            }
            else
                Stack.pop();
            break;
        case '>':
            if (Stack.top() != '<')
            {
                ok = 0;
            }
            else
                Stack.pop();
            break;
        }


    }
    if (ok == 1 && !Stack.empty())
    {
        while (!Stack.empty())
        {
            nr = nr * 5;
            if (Stack.top() == '(')
            {
                nr += 1;
            }
            if (Stack.top() == '[')
            {
                nr += 2;
            }
            if (Stack.top() == '{')
            {
                nr += 3;
            }
            if (Stack.top() == '<')
            {
                nr += 4;
            }
            Stack.pop();
        }
    }
    if(nr)
     Complete.push_back(nr);
}

int main()
{
    getNumbers(Numbers);
    for (auto& str : Numbers)
    {
        getPoints(str, Complete);
    }

    sort(begin(Complete), end(Complete));
    cout << Complete[Complete.size() / 2];

}
