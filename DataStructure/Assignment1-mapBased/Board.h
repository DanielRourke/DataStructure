#pragma once
#include "pch.h"
#include "structures.h"


class Board
{
private:
	unordered_map <Move, list<Neighbour>, MyHash> neighbourMap;
	list<Move> remainingMoves;
	int **grid;
	int row;
	int col;
public:
	Board(int , int);
	Board(const Board& cboard);
	~Board();
	void printBoard();
	bool addMove(Move, int);
	bool isValidMove(Move);
	void getNeighbours(Move &);
	Move getRandomMove();
	list<Move> getRemainingMoves();
	double getHuristicScore();
	bool isboardFull();
	int getScore();
};

