#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;

#define clr() printf("\033[2J")
int const row = 40;
int const col = 40;
char const ch = '#';
vector<vector<char>> map(row, vector<char>(col, ' '));

void generate()
{
	srand(time(0));
	for (int i = 0; i < 1000; ++i)
	{
		int x = rand() % row;
		int y = rand() % col;
		map[x][y] = ch;
	}
}

int countsurrounding(int i, int j)
{
	int count = 0;
	int it = i - 1, ib = i + 1;
	int jl = j - 1, jr = j + 1;
	if (it >= 0)
	{
		if (jl >= 0 && map[it][jl] == ch) count += 1;
		if (jr < row && map[it][jr] == ch) count += 1;
		if (map[it][j] == ch) count += 1;
	}
	if (ib < row)
	{
		if (jl >= 0 && map[ib][jl] == ch) count += 1;
		if (jr < row && map[ib][jr] == ch) count += 1;
		if (map[ib][j] == ch) count +=1;
	}
	if (jl >= 0 && map[i][jl] == ch) count += 1;
	if (jr < row && map[i][jr] == ch) count += 1;
	return count;
}

void update()
{
	vector<vector<char>> tmp(row, vector<char>(row, ' '));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			int count = countsurrounding(i, j);
			if (count == 3)
			{
				tmp[i][j] = ch;
			}
			else if (count == 2)
			{
				tmp[i][j] = map[i][j];
			}
			else tmp[i][j] = ' ';
		}
	}
	map = tmp;
}

void print()
{
	clr();
	for (const auto &v: map)
	{
		for (const auto &c: v)
		{
			cout << c;
		}
		cout << endl;
	}
}

int main()
{
	generate();
	while(true)
	{
		update();
		print();
		sleep(1);
	}
	return 0;
}
