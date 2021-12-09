#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
ifstream INPUT("input.txt");
string randomNumbers;
vector<int> Numbers;
int Value[5][5];
int x;

class Board
{
private:
	bool Marked[5][5];
	int  Value[5][5];
	int onLine[5] = {};
	int onColumn[5] = {};
public:
	Board(int Value[5][5])
	{
		for(int line = 0; line <= 4; line++)
			for (int column = 0; column <= 4; column++)
			{
				this->Marked[line][column] = false;
				this->Value[line][column] = Value[line][column];
			}
	}

	bool hasBingo()
	{
		for (auto it : onLine)
			if (it == 5)
				return true;
		for (auto it : onColumn)
			if (it == 5)
				return true;
		return false;
	}

	void mark(int value)
	{
		for (int line = 0; line <= 4; line++)
			for (int column = 0; column <= 4; column++)
				if (Value[line][column] == value)
				{
					Marked[line][column] = true;
					onLine[line]++;
					onColumn[column]++;
				}
	}

	int getSum()
	{
		int Sum = 0;
		for (int line = 0; line <= 4; line++)
			for (int column = 0; column <= 4; column++)
				if (Marked[line][column] == false)
					Sum += Value[line][column];
		return Sum;
	}
};

void getNumbers(string randomNumbers, vector<int>& Numbers)
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
			Numbers.push_back(number);
			number = 0;
		}
}

int main()
{
	INPUT >> randomNumbers;
	getNumbers(randomNumbers, Numbers);

	vector<Board*> boards;
	while (INPUT >> x)
	{
		Value[0][0] = x;
		for (int column = 1; column <= 4; column++)
			INPUT >> Value[0][column];
		for (int line = 1; line <= 4; line++)
			for (int column = 0; column <= 4; column++)
				INPUT >> Value[line][column];

		boards.push_back(new Board(Value));
	}

	int pos = 0;
	bool found = false;
	while (!found)
	{
		for (auto& board : boards)
			board->mark(Numbers[pos]);
		for(auto& board: boards)
			if (board->hasBingo())
			{
				found = true;
				cout << board->getSum() * Numbers[pos];
				break;
			}

		pos++;
	}

return 0;
}

