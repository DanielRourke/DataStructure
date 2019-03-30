#pragma once
#include "Player.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer() : Player() {} ;
	RandomPlayer(int i, string name = "Random Player ") : Player(i, name += to_string(i)) {};
	~RandomPlayer() {};
	Move getMove(const Board &board)
	{

		Move move = board.getRandomMove();
		move.player = this->id;
		
		map<string, int> targets = board.getTargets(move);

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
				int value = 6;
				map<string, int>::const_iterator lowest = targets.begin();
				map<string, int>::const_iterator target;
				for (target = targets.begin(); target != targets.end(); target++)
				{
					if (target->second < value && (total + (abs(target->second))) <= 6)
					{
						lowest = target;
						value = target->second;
					}
				}
				if (total + abs(lowest->second) <= 6)
				{
					total += abs(value);
					move.captureTargets.emplace(lowest->first, lowest->second);
				}
				else
				{
                   system("pause");
				}
				targets.erase(lowest);
				if (total > 6 || total < -6)
				{
					
				}
			} while (targets.size() != 0 && (move.captureTargets.size() < 2 ||
				(targets.begin()->second < 0 && (total + abs(targets.begin()->second) <= 6)) ||
				(++targets.begin()->second < 0 && (total + abs(++targets.begin()->second))) ));
		}



			else if (id == 1)
			{
				do
				{
					int value = -6;
					map<string, int>::const_iterator highest = targets.begin();
					map<string, int>::const_iterator target;
					for (target = targets.begin(); target != targets.end(); target++)
					{
						if (target->second > value && (total + (abs(target->second))) <= 6)
						{
							highest = target;
							value = target->second;
						}

					}
					if (total + abs(highest->second) <= 6)
					{
						total += abs(value);
						move.captureTargets.emplace(highest->first, highest->second);
					}
					else
					{
						system("pause");
					}

					targets.erase(highest);


				} while (targets.size() != 0 && ( move.captureTargets.size() < 2
					|| (targets.begin()->second > 0 && (total + abs(targets.begin()->second) <= 6)) ||
					(++targets.begin()->second > 0 && (total + abs(++targets.begin()->second)))));
			}


		}
		
		return move;

	}
};



