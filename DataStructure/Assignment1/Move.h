#pragma once
#include "pch.h"
#include "Board.h"

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
	//void getNeighbours(Board &board);
	bool operator==(Move &m)
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


//inline void Move::getNeighbours(Board &board)
//{
//	captureTargets = board.getNeighbours(*this);
//}

