#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
using namespace std;
ifstream INPUT("input.txt");
string strNumbers;
vector<int> Numbers;
long long Total;


void getNumbers(string randomNumbers, unordered_map<long long, long long>& Lanternfish)
{
	long long number = 0;
	string aux = ",";
	randomNumbers += aux;

	for(auto ch : randomNumbers)
		if (ch != ',')
		{
			number = number * 10 + (ch - '0');
		}
		else
		{
			Lanternfish[number]++;
			number = 0;
		}
}

void newDay(unordered_map<long long, long long>& Lanternfish)
{
	long long newBorns = Lanternfish[0];

	for (int it = 0; it <= 7; it++)
		Lanternfish[it] = Lanternfish[it + 1];
	Lanternfish[8] = newBorns;
	Lanternfish[6] += newBorns;
}

int main()
{
	unordered_map<long long, long long> Lanternfish;

	INPUT >> strNumbers;
	getNumbers(strNumbers, Lanternfish);

	for (int day = 1; day <= 256; day++)
		newDay(Lanternfish);

	for (auto& it : Lanternfish)
		Total += it.second;
	cout << Total;
return 0;
}

