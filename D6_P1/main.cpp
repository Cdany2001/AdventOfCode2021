#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
ifstream INPUT("input.txt");
string strNumbers;
vector<int> Numbers;

class Lanternfish
{
private:
	int lifeTimer;
public:
	Lanternfish(int lifeTimer = 8) : lifeTimer(lifeTimer){}

	void decrement()
	{
		lifeTimer--;
		if (lifeTimer < 0)
			lifeTimer = 6;
	}

	int getLifeTimer()
	{
		return this->lifeTimer;
	}
};

void getNumbers(string randomNumbers, vector<Lanternfish*>& lanternfishVec)
{
	int number = 0;
	string aux = ",";
	randomNumbers += aux;

	for(auto ch : randomNumbers)
		if (ch != ',')
		{
			number = number * 10 + (ch - '0');
		}
		else
		{
			lanternfishVec.push_back(new Lanternfish(number));
			number = 0;
		}
}

void newDay(vector<Lanternfish*>& lanternfishVec)
{
	int initalSize = lanternfishVec.size();

	for (int it = 0; it < initalSize; it++)
	{
		if (lanternfishVec[it]->getLifeTimer() == 0)
			lanternfishVec.push_back(new Lanternfish());
		lanternfishVec[it]->decrement();
	}
}

int main()
{
	vector<Lanternfish*> lanternfishVec;

	INPUT >> strNumbers;
	getNumbers(strNumbers, lanternfishVec);

	for (int day = 1; day <= 80; day++)
		newDay(lanternfishVec);

	cout << lanternfishVec.size();

return 0;
}

