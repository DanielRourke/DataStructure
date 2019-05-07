#pragma once
#include "Player.h"
class SmartPlayer :
	public Player
{
public:
	SmartPlayer() : Player() {};
	SmartPlayer(int i, string name = "Smart Player") : Player(i, name) {};
	~SmartPlayer() {};
	Move getMove(Board & board)
	{
		priority_queue<Move, vector<Move>, less<vector<Move>::value_type>> bestMove;
		list<Move> rMoves = board.getRemainingMoves();

		for (Move move : rMoves)
		{
			move.printMove();
		}


		for (Move move : rMoves)
		{


			Board tempBoard(board);
			tempBoard.getNeighbours(move);
			move.sortTargets();
			move.pickTargets(id);
			tempBoard.addMove(move, id);
			if (tempBoard.isboardFull())
			{
				if (id == 0)
				{
					move.utility = tempBoard.getHuristicScore()  * 1.0;
				}
				else if (id == 1)
				{
					move.utility = tempBoard.getHuristicScore()  * -1.0;
				}
			}
			move.utility += move.targetTotal() * 0.01;

			

			bestMove.push(move);
		}

		return bestMove.top();
	}
};