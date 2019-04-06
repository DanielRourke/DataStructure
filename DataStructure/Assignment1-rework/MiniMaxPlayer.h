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
		count = 0;
		Move ret =  maxMove(board);
		cout << ret.x << " " << ret.y << " " << ret.utilty<< endl;
		return ret;
		/**
		fun
			nested for loop
				if win return 1 if lose  return -1
				
				list  move.score  =  call fun(updated board)

				go through moves return best one

		*/
	}

	Move minMove(const Board &board)
	{
	//	cout << count << endl;
		count++;
		list<Move> rMoves = board.getRemainingMoves();

		
		if (rMoves.empty() || count > 10000)
		{
			if (id == 0)
			{
				return Move(0, 0, -board.getScore() * -0.1 );
			}
			else if (id == 1)
			{
				return Move(0, 0, board.getScore() *  -0.1);
			}
		}
			

		priority_queue<Move, vector<Move>, greater<vector<Move>::value_type>> bestMove;
		
		for(Move move :rMoves)
		{
			Board tempBoard(board);
			list<Neighbour>targets = tempBoard.getTargets(move);
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
			cout << "before " << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
			tempBoard.addMove(move, (id + 1) % 2);
			cout << "after" << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
			if (tempBoard.getRemainingMoves().size() <= 0)
			{
				int score = board.getScore();
				if ((score > 0 && id == 0) || (score < 0 && id == 1))
				{
				//	cout << "Win" << endl;
					move.utilty = 1;
				}
				else
				{
					//cout << "loss" << endl;
					move.utilty = -1;
				}
			}
			else
			{
				move.utilty = maxMove(tempBoard).utilty;
			}
			bestMove.push(move);
		}
		//cout << "Minmove best move " << bestMove.top().utilty << endl;
		return bestMove.top();
	}

	Move maxMove(const Board &board)
	{
	//	cout << count << endl;
		count++;
		list<Move> rMoves = board.getRemainingMoves();
		if (rMoves.empty() || count > 10000)
		{
			if (id == 0)
			{
				return Move(0, 0, -board.getScore() * 0.1);
			}
			else if (id == 1)
			{
				return Move(0, 0, board.getScore() *  0.1);
			}
		}

		priority_queue<Move, vector<Move>, less<vector<Move>::value_type>> bestMove;

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
			cout << "before " << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
			tempBoard.addMove(move, id);

			cout << "after" << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
			if (tempBoard.getRemainingMoves().size() <= 0)
			{
				int score = board.getScore();
				if ((score > 0 && id == 0) || (score < 0 && id == 1))
				{
					//cout << "Win" << endl;
					move.utilty = 1;
				}
				else
				{
					//cout << "loss" << endl;
					move.utilty = -1;
				}
			}
			else
			{
				move.utilty = minMove(tempBoard).utilty;
			}
			
			bestMove.push(move);
		}

		//cout << "Maxmove best move " << bestMove.top().utilty << endl;
		return bestMove.top();
	}
};



