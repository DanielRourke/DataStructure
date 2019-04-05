#pragma once
#include "Player.h"
class MiniMaxPlayer :
	public Player
{
public:
	MiniMaxPlayer() : Player() {};
	MiniMaxPlayer(int i, string name = "MiniMax Player") : Player(i, name) {};
	~MiniMaxPlayer() {};
	Move getMove(const Board &board)
	{
		return maxMove(board);
		/*
		fun
			nested for loop
				if win return 1 if lose  return -1
				
				list  move.score  =  call fun(updated board)

				go through moves return best one

		*/
	}

	Move minMove(const Board &board)
	{

		list<Move> rMoves = board.getRemainingMoves();

		if (rMoves.size() <= 0)
		{
			int score = board.getScore();
			if ((score > 0 && id == 0) || (score < 0 && id ==1))
			{

				cout << "Min move win" << endl;
				return Move(-1, -1, 1.0);
			}
			else
			{
				return Move(-1, -1, -1.0);;
			}
		}
		priority_queue<Move, vector<Move>, greater<vector<Move>::value_type>> bestMove;
		
		for(Move move :rMoves)
		{
			Board tempBoard(board);
			list<Neighbour>targets = board.getTargets(move);
			if (targets.size() == 2)
			{
				move.captureTargets = targets;
			}
			else if (targets.size() > 2)
			{
				targets.sort(NeighbourOrderComparator(this->id));
				for (auto& target : targets)
				{
					//ensures that the random player doesnt take own square if they can avoid it
					if (targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)))
					{
						break;
					}
					if (abs(target.pipCount) + move.captureTotal() <= 6)
					{
						move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					}
				}
			}
			tempBoard.addMove(move, (id + 1) % 2);
			move.utilty += minMove(tempBoard).utilty;
			bestMove.push(move);
		}

		return bestMove.top();
	}

	Move maxMove(const Board &board)
	{
		
		list<Move> rMoves = board.getRemainingMoves();

		if (rMoves.size() <= 0)
		{
			int score = board.getScore();
			if ((score > 0 && id == 0) || (score < 0 && id == 1))
			{
				cout << "Max move win" << endl;
				return Move(-1,-1, 1.0);
			}
			else
			{
				return Move(-1, -1, -1.0);;
			}
		}
		priority_queue<Move, vector<Move>, less<vector<Move>::value_type>> bestMove;

		for (Move move : rMoves)
		{
			Board tempBoard(board);
			list<Neighbour>targets = board.getTargets(move);
			if (targets.size() == 2)
			{
				move.captureTargets = targets;
			}
			else if (targets.size() > 2)
			{
				targets.sort(NeighbourOrderComparator(this->id));
				for (auto& target : targets)
				{
					//ensures that the random player doesnt take own square if they can avoid it
					if (targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)))
					{
						break;
					}
					if (abs(target.pipCount) + move.captureTotal() <= 6)
					{
						move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					}
				}
			}
			tempBoard.addMove(move, id);
			move.utilty += minMove(tempBoard).utilty;
			bestMove.push(move);
		}

		return bestMove.top();
	}
};



