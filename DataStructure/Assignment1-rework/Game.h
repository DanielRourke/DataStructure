#pragma once
#include "pch.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "MiniMaxPlayer.h"

class Game
{
private:
	Board gameBoard;
	Player *players[2];
public:
	Game(int, int, int);
	~Game();
	void play();
	void setMode(int);
	void determineWinner();
};

Game::Game(int row = 3, int col = 3, int mode = 0) : gameBoard(row, col)
{
	setMode(mode);
}

Game::~Game()
{}

inline void Game::play()
{
	int playerIndex = 0;
	Move currentMove;
	do
	{
		gameBoard.printBoard();
		currentMove = players[playerIndex]->getMove(gameBoard);
		gameBoard.addMove(currentMove, playerIndex);
		playerIndex = ++playerIndex % 2;
	} while (gameBoard.getRemainingMoves().size() > 0);

	gameBoard.printBoard();
	determineWinner();
}

inline void Game::setMode(int playerCombo)
{

	switch (playerCombo)
	{
	case 1:
		players[0] = new HumanPlayer(0);
		players[1] = new HumanPlayer(1);
		break;
	case 2:
		players[0] = new HumanPlayer(0);
		players[1] = new RandomPlayer(1);
		break;
	case 3:
		players[0] = new RandomPlayer(0);
		players[1] = new RandomPlayer(1);
		cout << playerCombo << endl;
		break;
	case 4:
		players[0] = new RandomPlayer(0);
		players[1] = new MiniMaxPlayer(1);
	}
}

inline void Game::determineWinner()
{
	int score = gameBoard.getScore();
	if (score > 0)
	{
		cout << players[0]->getName() << " Wins by " << score << endl;
	}
	else if (score < 0)
	{
		cout << players[1]->getName() << " Wins by " << score << endl;
	}
}
