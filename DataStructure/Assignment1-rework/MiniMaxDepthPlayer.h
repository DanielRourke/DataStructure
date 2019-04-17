#pragma once
#include "Player.h"
class MiniMaxDepthPlayer :
	public Player
{
private:
	int depth;
public:
	MiniMaxDepthPlayer() : Player() {};
    MiniMaxDepthPlayer(int i, string name = "MiniMaxDepth Player") : Player(i, name), depth(3){};
	MiniMaxDepthPlayer(int i, int d, string name = "MiniMaxDepth Player") : Player(i, name), depth(d) {};
	~MiniMaxDepthPlayer() {};

	Move getMove(const Board &board)
	{
		Move ret = maxMove(board, depth);
		cout << " X " << ret.x << " Y " << ret.y << " Utility: " << ret.utility << endl;
		return ret;
	}

	Move minMove(const Board &board , int depth)
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

			tempBoard.addMove(move, (id + 1) % 2);

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
			else if (depth > 0)
			{
				move.utility = maxMove(tempBoard, depth - 1).utility;
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

			move.utility += move.captureTotal() * 0.001;
			//cout << "** X " << move.x << " Y " << move.y << " Utility: " << move.utility << endl;
			bestMove.push(move);
		}

		return bestMove.top();
	}

	Move maxMove(const Board &board, int depth)
	{
		

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


			tempBoard.addMove(move, id);

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
			else if (depth > 0)
			{
				move.utility = minMove(tempBoard, depth).utility;
			}
			else
			{
				//cout << "depth reached" << endl;

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
