#pragma once
#include "Move.h"

class Board
{
private:
	int row, col;
	unordered_map<Move, int> grid;
public:
	~Board() {}
	Board(int r, int c);
	Board(const Board& cboard);
	void printBoard();
	bool isValidMove(Move move);
	bool isInBounds(int x, int y);
	unordered_map<string, int> getNeighbours(Move move);
	unordered_map<string, int> getTargets(Move move);
};

