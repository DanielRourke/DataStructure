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
	Player(int i, string n = "Player") : id(i), name(n) {}
	//virtual int getMove(const Board &board) = 0;
	virtual Move getMove(const Board &board) = 0;
	int getID() { return id; }
	string getName() { return name; }
	virtual ~Player() {};
};

