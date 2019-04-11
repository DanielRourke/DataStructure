#pragma once
#include "Player.h"


const int simulation_times = 100;

class MonteCarloPlayer :
	public Player
{
public:
	MonteCarloPlayer() : Player() {};
	MonteCarloPlayer(int i, string name = "MonteCarlo Player") : Player(i, name) {};
	~MonteCarloPlayer() {};
	Move getMove(const Board &board)
	{
		list<Move> rMoves = board.getRemainingMoves();
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
					//ensures that the player doesnt take own square if they can avoid it
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
			cout << "X : " << move.x << "Y : " << move.y << endl;
			move.utility = simulation(tempBoard);

			bestMove.push(move);
			
		}
		return bestMove.top();
	}

	int simulation(Board board)
	{
		int gamesWon = 0;

		for (int i = 0; i < simulation_times; i++)
		{
			Board tempBoard(board);
			gamesWon += expansion(tempBoard, id);
		}
		cout << "Games Won " << gamesWon << endl;
		return gamesWon;
	}

	int expansion(Board board, int playerId)
	{

		Board tempBoard(board);
		list<Move> rMoves = tempBoard.getRemainingMoves();

		if (rMoves.empty())
		{
			if ((id == 0 && tempBoard.getScore() > 0) || id == 1 && tempBoard.getScore() < 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
			
			list<Move>::const_iterator moveIt = rMoves.begin();
			advance(moveIt, rand() % rMoves.size());
			Move move = *moveIt;



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
				}
			}



			tempBoard.addMove(move, playerId);
			return expansion(tempBoard, (playerId + 1) % 2);
		
	}
};

