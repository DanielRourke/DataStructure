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
				targets.sort(NeighbourOrderComparator(this->id));
				for (auto& target : targets)
				{
					//ensures that the player doesnt take own square if they can avoid it
					if (targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)))
					{
						break;
					}
					if (abs(target.pipCount) + move.captureTotal() <= 6)
					{
						move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					}

				//ensures that the player doesnt take own square if they can avoid it
					//if (abs(target.pipCount) + move.captureTotal() <= 6)
					//{
					//	//unless it is a 6
					//	if ((abs(target.pipCount) + move.captureTotal() == 6))
					//	{
					//		move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					//	}
					//	else if (!(targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0))))
					//	{
					//		move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					//	}
					//}

				
				} 
				
			}
		
		//	cout << "Remaining Moves " << tempBoard.getRemainingMoves().size() << endl;

			tempBoard.addMove(move, (id + 1) % 2);

			if (tempBoard.getRemainingMoves().empty())
			{
	/*			if ((id == 0 && board.getScore() > 0) || id == 1 && board.getScore() < 0)
				{
					move.utility = 1;
				}
				else
				{
					move.utility = -1;
				}*/

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
					move.utility = tempBoard.getHuristicScore() * -0.1;
				}
			}

			move.utility += move.captureTotal() * 0.0001;

			bestMove.push(move);
		}

		//cout << "The Min utility is  " << bestMove.top().utility << endl;

		return bestMove.top();


	//	cout << count << endl;
		//count++;
		//list<Move> rMoves = board.getRemainingMoves();

		//
		//if (rMoves.empty() || count > 10000)
		//{
		//	if (id == 0)
		//	{
		//		return Move(0, 0, -board.getScore() * -0.1 );
		//	}
		//	else if (id == 1)
		//	{
		//		return Move(0, 0, board.getScore() *  -0.1);
		//	}
		//}
		//	

		//priority_queue<Move, vector<Move>, greater<vector<Move>::value_type>> bestMove;
		//
		//for(Move move :rMoves)
		//{
		//	Board tempBoard(board);
		//	list<Neighbour>targets = tempBoard.getTargets(move);
		//	if (targets.size() == 2)
		//	{
		//		move.captureTargets = targets;
		//	}
		//	else if (targets.size() > 2)
		//	{
		//		targets.sort(NeighbourOrderComparator(this->id));
		//		for (auto& target : targets)
		//		{
		//			//ensures that the random player doesnt take own square if they can avoid it
		//			if (targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)))
		//			{
		//				break;
		//			}
		//			if (abs(target.pipCount) + move.captureTotal() <= 6)
		//			{
		//				move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
		//			}
		//		}
		//	}
		//	cout << "before " << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
		//	tempBoard.addMove(move, (id + 1) % 2);
		//	cout << "after" << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
		//	if (tempBoard.getRemainingMoves().size() <= 0)
		//	{
		//		int score = board.getScore();
		//		if ((score > 0 && id == 0) || (score < 0 && id == 1))
		//		{
		//		//	cout << "Win" << endl;
		//			move.utilty = 1;
		//		}
		//		else
		//		{
		//			//cout << "loss" << endl;
		//			move.utilty = -1;
		//		}
		//	}
		//	else
		//	{
		//		move.utilty = maxMove(tempBoard).utilty;
		//	}
		//	bestMove.push(move);
		//}
		////cout << "Minmove best move " << bestMove.top().utilty << endl;
		//return bestMove.top();
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
				targets.sort(NeighbourOrderComparator(this->id));
				for (auto& target : targets)
				{
					//ensures that the player doesnt take own square if they can avoid it
					//if (targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)))
					//{
					//	break;
					//}
					if (abs(target.pipCount) + move.captureTotal() <= 6)
					{
						move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					}


					//ensures that the player doesnt take own square if they can avoid it
					//if (abs(target.pipCount) + move.captureTotal() <= 6)
					//{
					//	//unless it is a 6
					//	if ((abs(target.pipCount) + move.captureTotal() == 6))
					//	{
					//		move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					//	}
					//	else if (!(targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0))))
					//	{
					//		move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
					//	}
					//}
				}
			}



			tempBoard.addMove(move, id );

		//	cout << "Remaining Moves " << tempBoard.getRemainingMoves().size() << endl;

			if (tempBoard.getRemainingMoves().empty())
			{
				//if ((id == 0 && board.getScore() > 0) || id == 1 && board.getScore() < 0)
				//{
				//	move.utility = 1;
				//}
				//else
				//{
				//	move.utility = -1;
				//}

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
	//	cout << "The Max utility is  " << bestMove.top().utility << endl;
		return bestMove.top();
	//	cout << count << endl;
		//count++;
		//list<Move> rMoves = board.getRemainingMoves();
		//if (rMoves.empty() || count > 10000)
		//{
		//	if (id == 0)
		//	{
		//		return Move(0, 0, -board.getScore() * 0.1);
		//	}
		//	else if (id == 1)
		//	{
		//		return Move(0, 0, board.getScore() *  0.1);
		//	}
		//}

		//priority_queue<Move, vector<Move>, less<vector<Move>::value_type>> bestMove;

		//for (Move move : rMoves)
		//{
		//	Board tempBoard(board);
		//	list<Neighbour>targets = tempBoard.getTargets(move);
		//	if (targets.size() == 2)
		//	{
		//		move.captureTargets = targets;
		//	}
		//	else if (targets.size() > 2)
		//	{
		//		targets.sort(NeighbourOrderComparator(this->id));
		//		for (auto& target : targets)
		//		{
		//			//ensures that the random player doesnt take own square if they can avoid it
		//			if (targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)))
		//			{
		//				break;
		//			}
		//			if (abs(target.pipCount) + move.captureTotal() <= 6)
		//			{
		//				move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
		//			}
		//		}
		//	}
		//	cout << "before " << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
		//	tempBoard.addMove(move, id);

		//	cout << "after" << rMoves.size() << " " << tempBoard.getRemainingMoves().size() << endl;
		//	if (tempBoard.getRemainingMoves().size() <= 0)
		//	{
		//		int score = board.getScore();
		//		if ((score > 0 && id == 0) || (score < 0 && id == 1))
		//		{
		//			//cout << "Win" << endl;
		//			move.utilty = 1;
		//		}
		//		else
		//		{
		//			//cout << "loss" << endl;
		//			move.utilty = -1;
		//		}
		//	}
		//	else
		//	{
		//		move.utilty = minMove(tempBoard).utilty;
		//	}
		//	
		//	bestMove.push(move);
		//}

		////cout << "Maxmove best move " << bestMove.top().utilty << endl;
		//return bestMove.top();
	}
};



