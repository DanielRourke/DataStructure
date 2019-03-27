#pragma once
#include "pch.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer() : Player() {};
	RandomPlayer(bool position, string name = "Random Player") : Player(position, name) {};
	~RandomPlayer() {} ;
	//Move getMove(Move m, Board *b = NULL)
	//{
	//	cout << "Input your move with row and column numbers:" << endl;
	//	cin >> m.x >> m.y;
	//	return m;
	//}
	void getMove(int& x, int& y, Board *b, stack<pair<int, int>> *pMoves)
	{
		cout << "Input your move with row and column numbers:" << endl;
		cin >> x >> y;
	}
};


