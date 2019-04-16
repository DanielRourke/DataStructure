#pragma once
#include "pch.h"
class Neighbour
{
public:
	string direction;
	int pipCount;
	Neighbour() {};
	Neighbour(string d, int p);
	~Neighbour() {}
	bool operator<(const Neighbour other)
	{
		return pipCount < other.pipCount;
	}
};

Neighbour::Neighbour(string d, int p)
{
	direction = d;
	pipCount = p;
}

struct NeighbourAbsComparator
{
	// Compare 2 Neigbours by absolute pipCount Value
	bool operator ()(const Neighbour & neighbour1, const Neighbour &  neighbour2)
	{
		return (abs(neighbour1.pipCount) < abs(neighbour2.pipCount));

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
			return (neighbour1.pipCount < neighbour2.pipCount);
		}
		else
		{
			return (neighbour1.pipCount > neighbour2.pipCount);
		}

	}
};
