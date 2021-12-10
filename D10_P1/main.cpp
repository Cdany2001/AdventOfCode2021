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
int Total;


void getNumbers(vector<string>& Numbers)
{
    while(INPUT >> strNumbers)
        Numbers.push_back(strNumbers);
}

void getPoints(string str)
{
    stack<char> Stack;
    int ok = 1;

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
                Total += 3;
                ok = 0;
            }
            else
                Stack.pop();
            break;
        case ']':
            if (Stack.top() != '[')
            {
                Total += 57;
                ok = 0;
            }
            else
                Stack.pop();
            break;
        case '}':
            if ( Stack.top() != '{')
            {
                Total += 1197;
                ok = 0;
            }
            else
                Stack.pop();
            break;
        case '>':
            if (Stack.top() != '<')
            {
                Total += 25137;
                ok = 0;
            }
            else
                Stack.pop();
            break;
        }
    }
}

int main()
{
    getNumbers(Numbers);
    for (auto& str : Numbers)
        getPoints(str);
    cout << Total;

}
