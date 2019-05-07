#pragma once
#include "Player.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer() : Player() {};
	RandomPlayer(int i, string name = "Random Player ") : Player(i, name) {};
	~RandomPlayer() {};
	Move getMove(Board &board)
	{
		Move move = board.getRandomMove();
		board.getNeighbours(move);
		move.sortTargets();
		move.pickTargets(id);
		return move;

	}
};



