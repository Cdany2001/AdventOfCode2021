#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
ifstream INPUT("input.txt");
map<pair<int, int>, int> Point;
string strLine;

void getPoints()
{
	while (INPUT >> strLine)
	{
		int x = 0;
		int y = 0;
		int x2 = 0;
		int y2 = 0;
		strLine += ",";

		int it = 0;
		while (strLine[it] != ',')
		{
			x = x * 10 + (strLine[it] - '0');
			it++;
		}
		it++;
		while (strLine[it] != ',')
		{
			y = y * 10 + (strLine[it] - '0');
			it++;
		}

		INPUT >> strLine >> strLine;
		strLine += ",";

		it = 0;
		while (strLine[it] != ',')
		{
			x2 = x2 * 10 + (strLine[it] - '0');
			it++;
		}
		it++;
		while (strLine[it] != ',')
		{
			y2 = y2 * 10 + (strLine[it] - '0');
			it++;
		}

		if (x == x2)
			for (int it = min(y, y2); it <= max(y, y2); it++)
				Point[make_pair(x, it)]++;
		else if (y == y2)
			for (int it = min(x, x2); it <= max(x, x2); it++)
				Point[make_pair(it,y)]++;
		else
		{
			if (x > x2)
			{
				swap(x, x2);
				swap(y, y2);
			}
			if(y < y2)
			for (int it = y; it <= y2; it++)
				Point[make_pair(x++, it)]++;
			for (int it = y; it >= y2; it--)
				Point[make_pair(x++, it)]++;

		}
	}
}

int main()
{
	getPoints();
	cout << count_if(begin(Point), end(Point), [](pair<pair<int, int>, int> A)->bool {return A.second > 1; });

return 0;
}
