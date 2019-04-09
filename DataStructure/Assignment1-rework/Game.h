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
	pair < Player*, int> determineWinner();
	void simPlay(int,int,int,int);
};

Game::Game(int row = 3, int col = 3, int mode = 0) : gameBoard(row, col)
{
	setMode(mode);
}

Game::~Game()
{
	delete[] *players;
}

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
	pair<Player*,int> winner = determineWinner();

	cout << winner.first->getName() << " Wins by " << winner.second << endl;
}

inline void Game::simPlay(int games,int gameMode, int row = 3, int col = 3)
{

	setMode(gameMode);
	vector<pair<Player*, int>> gameResults;

	for (int i = 0; i < games; i++)
	{
		int playerIndex = 0;
		Move currentMove;
		do
		{
			currentMove = players[playerIndex]->getMove(gameBoard);
			gameBoard.addMove(currentMove, playerIndex);
			gameBoard.printBoard();
			playerIndex = ++playerIndex % 2;

		} while (gameBoard.getRemainingMoves().size() > 0);

		gameBoard.printBoard();
		gameResults.push_back(determineWinner());
		gameBoard.resetBoard(row,col);
	}

	int player0 = 0;
	int player1 = 0;

	for (pair <Player*, int> winner : gameResults)
	{
		if (winner.first->getName().compare(players[0]->getName()))
		{
			player1++;
		}
		else
		{
			player0++;
		}
	}

	cout << players[0]->getName() << "Games Won : " << player0 << endl;
	cout << players[1]->getName() << "Games Won : " << player1 << endl;

}

inline void Game::setMode(int playerCombo)
{
	//for (Player *player : players)
	//{
	//	delete player;
	//}

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

inline pair<Player*,int> Game::determineWinner()
{
	int score = gameBoard.getScore();
	if (score > 0)
	{
		return make_pair(players[0], score);
	}
	else if (score < 0)
	{
		return make_pair(players[1], score);
	}
}
