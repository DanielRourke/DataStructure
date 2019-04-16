#pragma once
#include "pch.h"
#include "Board.h"

class Player
{
protected:
	int id;
	string name;
public:
	Player() : name("Blank Player") {}
	Player(int i, string n = "Player") : id(i), name(n += to_string(i + 1)) {}
	virtual Move getMove(Board &board) = 0;
	int getID() { return id; }
	string getName() { return name; }
	virtual ~Player() {};
	void pickTargets(Move & move)
	{
		list<Neighbour> targets = boa

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
	}
};