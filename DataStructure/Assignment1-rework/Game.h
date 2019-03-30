#pragma once
#include "pch.h"
#include "Board.h"
#include "HumanPlayer.h"
class Game
{
private:
	Board gameBoard;
	Player *players[2];
public:
	Game(int, int);
	~Game();
	void play();
};



Game::Game(int row = 3, int col = 3) : gameBoard(row, col)
{
	//for (int i = 0; i < row; i++)
	//	for (int j = 0; j < col; j++)
	//	{
	//		remaingMoves.push_back(Move(i, j));
	//	}

	players[0] = new HumanPlayer( 0);
	players[1] = new HumanPlayer( 1);
}


Game::~Game()
{
}

inline void Game::play()
{
	int p = 0;
	do
	{
		gameBoard.printBoard();
		//int move = players[p]->getMove(gameBoard);
		//gameBoard.addMove(move, p);
		gameBoard.addMove(players[p]->getMove(gameBoard));
		p = ++p % 2;
	} while (true);


}
