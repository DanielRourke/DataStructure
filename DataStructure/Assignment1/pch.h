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
#include <unordered_map>
#include <sstream>

using namespace std;

#include "Neighbour.h"
#include "Move.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Board.h"
#include "Game.h"
#include "time.h"

class Move
{
public:
	Move(int a = 0, int b = 0) : x(a), y(b) {}
	~Move() {};

	int x;
	int y;
	int score;
	unordered_map<string, int> captureTargets;


	int captureTotal();
	void getNeighbours(const Board &board);
	bool operator==(const Move &m)
	{
		return captureTargets == m.captureTargets;
	}
};


int Move::captureTotal()
{
	int count = 0;
	for (auto& neighbour : captureTargets)
	{
		count += neighbour.second;
	}
	return count;
}

void Move::getNeighbours(const Board &board)
{
	captureTargets = board.getNeighbours(*this);
}





#endif //PCH_H
