// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

#include "Player.h"
#include "HumanPlayer.h"
#include "Board.h"
#include "Game.h"
#include "time.h"

struct Neighbour {
	string first;
	int pipCount;
};

struct Move
{
	//Move(char c, int score = 0) : x(0), y(0), s(c), score(score) {}
	//Move(int a = 0, int b = 0, char c = ' ') : x(a), y(b), s(c), score(0) {}
	//Move(const Move& move) : x(move.x), y(move.y), s(move.s), score(move.score) {}
	Move(int a = 0, int b = 0) : x(a), y(b) {}
	int x;
	int y;
	//char s;
	//int score;
};


struct Number
{
	int result;
	Number() : result(0) {}
	int getNumber(int min, int max)
	{
		do
		{
			cin >> result;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Input";
				result = 0;
			}
		} while (result < min || result > max);

		return result;
	}
};

#endif //PCH_H
