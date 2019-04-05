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
		move.player = this->id;
		
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
				if (targets.size() >= 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)) )
				{
					break;
				}
				if (abs(target.pipCount) + move.captureTotal() <= 6 )
				{
					move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
				}
			}
		}
		return move;
	}
/*


		list<Neighbour>targets = board.getTargets(move);

		if (targets.size() == 2)
		{
			move.captureTargets = targets;
		}
		else if (targets.size() > 2)
		{
			int total = 0;


			if (id == 0)
			{
				do
				{
					map<string, int>::const_iterator lowest = targets.begin();
					map<string, int>::const_iterator target;
					for (target = targets.begin(); target != targets.end(); target++)
					{
						if (target->second <= lowest->second && (total + abs(target->second)) <= 6)
						{
							lowest = target;
						}
					}
					if (total + (abs(lowest->second)) <= 6)
					{
						total += (total + (abs(lowest->second)));
						move.captureTargets.emplace(lowest->first, lowest->second);
						cout << " total " << total << endl;
					}
					else
					{

					}
					targets.erase(lowest);

				} while (targets.size() != 0 && (move.captureTargets.size() < 2 ||
					(targets.begin()->second < 0 && (total + abs(targets.begin()->second) <= 6)) ||
					(++targets.begin()->second < 0 && (total + abs(++targets.begin()->second)))));

			}



			else if (id == 1)
			{
				do
				{
					map<string, int>::const_iterator highest = targets.begin();
					map<string, int>::const_iterator target;
					for (target = targets.begin(); target != targets.end(); target++)
					{
						if (target->second >= highest->second && (total + abs(target->second)) <= 6)
						{
							highest = target;
						}

					}
					if ((total + abs(highest->second)) <= 6)
					{
						total = total + abs(highest->second);
						move.captureTargets.emplace(highest->first, highest->second);

					}
					else
					{

					}


					targets.erase(highest);


				} while (targets.size() != 0 && (move.captureTargets.size() < 2
					|| (targets.begin()->second > 0 && (total + abs(targets.begin()->second) <= 6)) ||
					(++targets.begin()->second > 0 && (total + abs(++targets.begin()->second)))));
			}


		}*/

		//if (move.captureTotal() > 6)
		//{
		//	move.captureTargets.clear();
		//	move.captureTargets = board.getTargets(move);
		//	map<string, int>::const_iterator highest;
		//	map<string, int>::const_iterator target;

		//	while (move.captureTotal() > 6)
		//	{
		//		for (target = move.captureTargets.begin(), highest = move.captureTargets.begin(); target != targets.end(); target++)
		//		{
		//			if (target->second > highest->second)
		//			{
		//				highest = target;
		//			}

		//		}
		//		move.captureTargets.erase(highest);
		//	}
		//
		//	if (move.captureTargets.size() < 2)
		//	{
		//		move.captureTargets.clear();
		//	}
		//}
		
		//return move;

	//}
};



