#pragma once
#include "pch.h"
#include "Board.h"
#include "Neighbour.h"
class Move
{
public:
	int x;
	int y;
	double utilty;
	list<Neighbour>captureTargets;
	Move(int a = 0, int b = 0, double u = 0.0) : x(a), y(b), utilty(u) {}
	~Move();
	int captureTotal();
	//void getNeighbours(const Board &board);
	bool operator==(Move m) const
	{	
		return (x == m.x && y == m.y);
	}

	bool operator<(Move m) const
	{
		return (utilty < m.utilty);
	}

	bool operator>(Move m) const
	{
		return (utilty > m.utilty);
	}



	//bool addTarget(string direction, int pipCount)
	//{
	//	if (direction.compare("Top") == 0 || direction.compare("Bottom") == 0 || direction.compare("Right") == 0 || direction.compare("Left") == 0)
	//	{
	//		captureTargets.push_back(Neighbour(direction, pipCount));
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
};


Move::~Move()
{
}


//
inline int Move::captureTotal()
{
	int count = 0;
	for (auto& neighbour : captureTargets)
	{
		count += abs(neighbour.pipCount);
	}
	return count;
}

//inline void Move::getNeighbours(const Board &board)
//{
//	captureTargets = board.getNeighbours(*this);
//}


