#pragma once
#include "pch.h"
#include "Board.h"
class Move
{
public:
	int x;
	int y;
	int player;
	map<string, int> captureTargets;
	Move(int a = 0, int b = 0, int p = 0) : x(a), y(b), player(p) {}
	~Move();
	//int captureTotal();
	//void getNeighbours(const Board &board);
	bool operator==(Move m)
	{	
		return (x == m.x) && (y == m.y);
	}
};


Move::~Move()
{
}



//inline int Move::captureTotal()
//{
//	int count = 0;
//	for (auto& neighbour : captureTargets)
//	{
//		count += neighbour.second;
//	}
//	return count;
//}

//inline void Move::getNeighbours(const Board &board)
//{
//	captureTargets = board.getNeighbours(*this);
//}
