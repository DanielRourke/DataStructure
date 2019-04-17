#pragma once
#include "Player.h"
class MiniMaxPlayer :
	public Player
	
{
public:
	MiniMaxPlayer() : Player() {};
	MiniMaxPlayer(int i, string name = "MiniMax Player") : Player(i, name) {};
	~MiniMaxPlayer() {};
	int count;
	Move getMove(const Board &board)
	{
		count = 5000;
		Move ret =  maxMove(board);
		cout <<" X " <<  ret.x << " Y " << ret.y << " Utility: " << ret.utility<< endl;
		return ret;

	}

	Move minMove(const Board &board)
	{
		priority_queue<Move, vector<Move>, greater<vector<Move>::value_type>> bestMove;
		list<Move> rMoves = board.getRemainingMoves();

		for (Move move : rMoves)
		{
			Board tempBoard(board);

			list<Neighbour>targets = tempBoard.getTargets(move);
			if (targets.size() == 2)
			{
				move.captureTargets = targets;
			}
			else if (targets.size() > 2)
			{
				move.pickTargets(targets, (id + 1) % 2);
			}
		
		//	cout << "Remaining Moves " << tempBoard.getRemainingMoves().size() << endl;

			tempBoard.addMove(move, (id + 1) % 2);

			if (tempBoard.getRemainingMoves().empty())
			{
				if (id == 0)
				{
					move.utility = tempBoard.getHuristicScore() * 1 ;
				}
				else if (id == 1)
				{
					move.utility = tempBoard.getHuristicScore() * -1;
				}
			}
			else if(count > 0)
			{
				move.utility = maxMove(tempBoard).utility;
			}
			else if( count <= 0)
			{
				if (id == 0)
				{
					move.utility = tempBoard.getHuristicScore() * 0.1;
				}
				else if (id == 1)
				{
					move.utility = tempBoard.getHuristicScore() * - 0.1;
				}
			}

			move.utility += (move.captureTotal() * 0.01);

			bestMove.push(move);
		}

		

		return bestMove.top();


	
	}

	Move maxMove(const Board &board)
	{
		count--;

		priority_queue<Move, vector<Move>, less<vector<Move>::value_type>> bestMove;
		list<Move> rMoves = board.getRemainingMoves();

		for (Move move : rMoves)
		{
			Board tempBoard(board);

			list<Neighbour>targets = tempBoard.getTargets(move);
			if (targets.size() == 2)
			{
				move.captureTargets = targets;
			}
			else if (targets.size() > 2)
			{
				move.pickTargets(targets, id);
			}

			tempBoard.addMove(move, id );

			if (tempBoard.getRemainingMoves().empty())
			{
				if (id == 0)
				{
					move.utility = tempBoard.getHuristicScore() * 1;
				}
				else if (id == 1)
				{
					move.utility = tempBoard.getHuristicScore() * -1;
				}
			}
			else if (count > 0)
			{
				move.utility = minMove(tempBoard).utility;
			}
			else
			{
				if (id == 0)
				{
					move.utility = tempBoard.getHuristicScore() * 0.1;
				}
				else if (id == 1)
				{
					move.utility = tempBoard.getHuristicScore() * -0.1;
				}
			}
			move.utility += move.captureTotal() * 0.0001;

			bestMove.push(move);
		}

		return bestMove.top();
	}
};



