#include "pch.h"


Game::Game()
{
	int row, col;
	do
	{
		cout << "Base code for Practical 3.4" << endl;
		cout << "Input the size of board, say (3 3), (3 5) or (5 5): " << endl;

		cin >> row >> col;

	} while ((row == 3 && (col == 3 || col == 5)) || (row == 5 && col == 5));
	
	gameBoard = new Board(row, col);
	players[0] = new HumanPlayer();
}


Game::~Game()
{
}
