#pragma once

class Player
{

protected:
	bool firstPlayer;
	string name;
public:
	Player() : name("Blank Player"), firstPlayer(true) {}
	Player ( bool p , string n = "Player") :  firstPlayer(p), name(n) {}
	//virtual Move getMove(Move m, Board *b) = 0;
	virtual void getMove(int& x, int& y, Board *b, list<int> rMoves) = 0;
	bool isFirstPlayer() { return firstPlayer; }
	string getName() { return name; }
	virtual ~Player() {};
};


