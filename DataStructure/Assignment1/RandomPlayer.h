#pragma once
#include "pch.h"
#include "Board.h"
#include "Player.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer() : Player() {};
	RandomPlayer(int id, string name = "Random : Player " ) : Player(id, name + to_string(id)) {};
	~RandomPlayer() {} ;
	Move getMove(Board &board, const vector<int> &rMoves)
	{
		return rMoves[rand() % rMoves.size()];
	}

};


