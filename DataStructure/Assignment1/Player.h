#pragma once

class Player
{

protected:
	int id;
	string name;
public:
	Player() : name("Blank Player") {}
	Player ( int i , string n = "Player") :  id(id), name(n) {}
	virtual Move getMove(const Board &b, const vector<int> &rMoves) = 0;
	int getID() { return id; }
	string getName() { return name; }
	virtual ~Player() {};
};


