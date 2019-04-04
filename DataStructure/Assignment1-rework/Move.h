#pragma once
#include "pch.h"
#include "Board.h"
#include "Neighbour.h"
class Move
{
public:
	int x;
	int y;
	int player;
	list<Neighbour>captureTargets;
	Move(int a = 0, int b = 0, int p = 0) : x(a), y(b), player(p) {}
	~Move();
	int captureTotal();
	//void getNeighbours(const Board &board);
	bool operator==(Move m)
	{	
		return (x == m.x) && (y == m.y);
	}

	bool addTarget(string direction, int pipCount)
	{
		if (direction.compare("Top") == 0 || direction.compare("Bottom") == 0 || direction.compare("Right") == 0 || direction.compare("Left") == 0)
		{
			captureTargets.push_back(Neighbour(direction, pipCount));
			return true;
		}
		else
		{
			return false;
		}
	}
};


Move::~Move()
{
}



inline int Move::captureTotal()
{
	int count = 0;
	for (auto& neighbour : captureTargets)
	{
		count += abs(neighbour.second);
	}
	return count;
}

//inline void Move::getNeighbours(const Board &board)
//{
//	captureTargets = board.getNeighbours(*this);
//}
