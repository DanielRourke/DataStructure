#pragma once
#include "pch.h"

class HumanPlayer :
	public Player
{
public:
	HumanPlayer() : Player() {};
	HumanPlayer(bool position, string name = "Human Player") : Player(position,name){};
	~HumanPlayer() {};
	//Move getMove(Move m, Board *b = NULL)
	//{
	//	cout << "Input your move with row and column numbers:" << endl;
	//	cin >> m.x >> m.y;
	//	return m;
	//}
	void getMove( int& x, int& y, Board *b, list<int> *rMoves = NULL)
	{
		cout << "Input your move with row and column numbers:" << endl;
		cin >> x >> y;
	}
};



