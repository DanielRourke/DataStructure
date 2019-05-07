#include "pch.h"
#include "Board.h"


Board::Board(int r, int c) {
	row = r;
	col = c;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			grid.emplace(Move(i, j), 0);
		}
}

Board::Board(Board& cboard) 
{
	row = cboard.row;
	col = cboard.col;
	grid = cboard.grid;
}

bool Board::isValidMove(Move move) 
{
		if (isInBounds(move.x, move.y) && grid.at(move) == 0 && move.captureTotal <= 6 && (move.captureTotal == 0 || move.captureTargets.size() > 1))
		return true;
	else
		return false;
}

bool Board::isInBounds(int x,int y)
{
	return x < row  && x >= 0 && y < col && y >= 0;
}


void Board::printBoard() {
	cout << "    ";
	for (int j = 0; j < col; j++) {
		cout << j + 1 << "   ";
	}
	cout << endl;

	for (int i = 0; i < row; i++) {
		cout << "  ";
		for (int j = 0; j < col; j++) {
			cout << " ---";
		}
		cout << endl;

		cout << (i + 1) << " |";

		for (int j = 0; j < col; j++) {
			unordered_map<Move, int>::const_iterator it = grid.find(Move(i, j));
			if (it->second == 0) {
				cout << "   |";
			}
			else if (it->second > 0) {
				cout << " " << it->second << " |";
			}
			else if (it->second < 0) {
				cout << "" << it->second << " |";
			}
		}
		cout << endl;
	}
	cout << "  ";

	for (int j = 0; j < col; j++) {
		cout << " ---";
	}
	cout << endl << endl;
}

//void Board::printMoves()
//{
//	for (int i = move.size(); i > 0; i--)
//	{
//		cout << "Move : " << i << " x: " << move.top().first + 1 << " y: " << move.top().second + 1 << endl;
//		move.pop();
//	}
//}

unordered_map<string, int> Board::getNeighbours(Move move) const
{
	unordered_map<string, int> neighbours;

	if (isInBounds(move.x + 1, move.y))
	{
		neighbours.emplace("Bottom", grid.at(move));
	}

	if (isInBounds(move.x - 1, move.y))
	{
		neighbours.emplace("Top", grid.at(move));
	}

	if (isInBounds(move.x, move.y + 1))
	{
		neighbours.emplace("Right", grid.at(move));
	}

	if (isInBounds(move.x, move.y - 1))
	{
		neighbours.emplace("Left", grid.at(move));
	}

	return neighbours;

}

unordered_map<string, int> Board::getTargets(Move move)
{
	unordered_map<string, int> neighbours;

	if (isInBounds(move.x += 1, move.y) && (grid.at(move) < 6))
	{
		neighbours.emplace("Bottom", grid.at(move));
	}

	if (isInBounds(move.x -= 2, move.y) && (grid.at(move) < 6))
	{
		neighbours.emplace("Top", grid.at(move));
	}

	if (isInBounds(move.x, move.y += 1) && (grid.at(move) < 6))
	{
		neighbours.emplace("Right", grid.at(move));
	}

	if (isInBounds(move.x, move.y -= 2) && (grid.at(move) < 6))
	{
		neighbours.emplace("Left", grid.at(move));
	}

	return neighbours;

}

