#pragma once
#include "Player.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer() : Player() {};
	RandomPlayer(int i, string name = "Random Player ") : Player(i, name) {};
	~RandomPlayer() {};
	Move getMove(const Board &board)
	{
		list<Move> rMoves = board.getRemainingMoves();
		list<Move>::const_iterator moveIt = rMoves.begin();
		advance(moveIt, rand() % rMoves.size());
		Move move = *moveIt;
		
		list<Neighbour>targets = board.getTargets(move);

		if (targets.size() == 2)
		{
			move.captureTargets = targets;
		}
		else if (targets.size() > 2)
		{
			move.pickTargets(targets, id);
		}
		return move;
	}

};


