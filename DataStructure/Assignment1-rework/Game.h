#pragma once
#include "pch.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"

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
	players[0] = new RandomPlayer( 0);
	players[1] = new RandomPlayer( 1);
}


Game::~Game()
{
}

inline void Game::play()
{
	int p = 0;
	Move currentMove;
	do
	{
		gameBoard.printBoard();
		gameBoard.addMove(players[p]->getMove(gameBoard));
		p = ++p % 2;
	} while (gameBoard.isGameOver());


}
