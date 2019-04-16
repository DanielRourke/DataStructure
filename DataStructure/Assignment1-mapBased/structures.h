#pragma once
#include "pch.h"


struct Neighbour {
	string direction;
	int * pipCount;
	Neighbour(string d, int * p)
	{
		direction = d;
		pipCount = p;
	}
	Neighbour() {};



	bool operator<(const Neighbour other)
	{
		return *pipCount < *other.pipCount;
	}
};

struct NeighbourOrderComparator
{
	int order;
	NeighbourOrderComparator(int o = 0) { order = o; };
	// Compare 2 Neigbours by pipCount Value Accending if order = 0 and decending if order =1
	bool operator ()(const Neighbour & neighbour1, const Neighbour &  neighbour2)
	{
		if (order == 0)
		{
			return (*neighbour1.pipCount < *neighbour2.pipCount);
		}
		else
		{
			return (*neighbour1.pipCount > *neighbour2.pipCount);
		}

	}
};


struct NeighbourAbsComparator
{
	// Compare 2 Neigbours by absolute pipCount Value
	bool operator ()(const Neighbour & neighbour1, const Neighbour &  neighbour2)
	{
		return (abs(*neighbour1.pipCount) < abs(*neighbour2.pipCount));
	}
};



struct Move
{
	int x;
	int y;
	double utility;
	list<Neighbour> targets;
	Move() {};
	Move(int xx, int yy)
	{
		x = xx;
		y = yy;
		utility = 0;
	}

	void printTargets()
	{
		int index = 0;
		for (Neighbour target : targets)
		{
			cout << index << ". " << target.direction << ": " << *target.pipCount << endl;
		}
		cout << "Total PipCount: " << targetTotal() << endl;
	}

	void sortTargets()
	{
		targets.sort(NeighbourAbsComparator());
		while (targets.size() > 1 && abs(*targets.front().pipCount) + abs(*targets.back().pipCount) > 6)
		{
			targets.pop_back();
			targets.sort(NeighbourAbsComparator());
		}
		targets.sort();
	}

	void pickTargets(int id)
	{
		if (targets.size() == 2 && targetTotal() == 6)
		{
			return;
		}
		else if (targets.size() > 2)
		{
			targets.sort(NeighbourOrderComparator(id));
			for (auto& target : targets)
			{
				//ensures that the random player doesnt take own square if they can avoid it
				if (targets.size() > 2 && ((id == 0 && target.pipCount > 0) || (id == 1 && target.pipCount < 0)))
				{
					targets.remove(target);
				}
				if (abs(target.pipCount) + move.captureTotal() <= 6)
				{
					move.captureTargets.push_back(Neighbour(target.direction, -target.pipCount));
				}
			}
		}

		/* while ( targetTotal() > 6 && targets.size() >2)
		{
			for (Neighbour target: targets)
			{
				if ((targetTotal() - *abs(target.pipCount)) <=6)
				{
					remove

				}

			}


		}
		 check if removing 1 == 6

		 else
		 remove your own from top




			
		*/
	}


	bool operator==(Move m) const
	{
		return (x == m.x && y == m.y);
	}

	bool operator<(Move m) const
	{
		return (utility < m.utility);
	}

	bool operator>(Move m) const
	{
		return (utility > m.utility);
	}

	int targetTotal()
	{
		int count = 0;
		for (auto& neighbour : targets)
		{
			count += abs(*neighbour.pipCount);
		}
		return count;
	}
};

struct MyHash {
	std::size_t operator()(Move m) const {
		std::hash<int> hashVal;
		return hashVal((m.x * 10 )+ m.y );
	}
};






