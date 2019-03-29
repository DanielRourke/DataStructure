#pragma once
#include "pch.h"

struct Neighbour
{
	string direction;
	int pipCount;
	Neighbour(string d, int p) : direction(d), pipCount(p) {}
	~Neighbour() {}
};



