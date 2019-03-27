#include "pch.h"

void Board::checkNeighbors(int x, int y) {

	neighbours.clear();
	Neighbour temp;

	if (isInBounds(x + 1, y) && !isEmpty(x + 1, y))
	{
		temp.first = "Bottom : ";
		temp.pipCount = grid[x + 1][y];
		neighbours.push_back(temp);
	}

	if (isInBounds(x - 1, y) && !isEmpty(x - 1, y))
	{
		temp.first = "Top : ";
		temp.pipCount = grid[x - 1][y];
		neighbours.push_back(temp);
	}

	if (isInBounds(x, y + 1) && !isEmpty(x, y + 1))
	{
		temp.first = "Right : ";
		temp.pipCount = grid[x][y + 1];
		neighbours.push_back(temp);
	}

	if (isInBounds(x, y - 1) && !isEmpty(x, y - 1))
	{
		temp.first = "Left : ";
		temp.pipCount = grid[x][y - 1];
		neighbours.push_back(temp);
	}
	int count = 0;

	for (Neighbour neighboor : neighbours)
	{
		cout << neighboor.first << neighboor.pipCount << endl;
		count += neighboor.pipCount;
	}

	cout << "Total : " << count << endl;

	return;
}


bool Board::addMove(int player, int x, int y)
{
	cout << x << " : " << y << endl;
	checkNeighbors(x, y);
	//left.remove(x * row + y);
	move.push(make_pair(x, y));
	grid[x][y] = rand() % 6 + 1;
	return true;
}

void Board::play() {
	int x, y;

	do {
		cout << "Game board:" << endl;
		this->printBoard();


		addMove(1, x - 1, y - 1);
	} while (left.size() > 0);
}

void Board::randomPlay()
{


	do {
		cout << "Game board:" << endl;
		this->printBoard();
		list<int>::iterator itr = left.begin();
		advance(itr, rand() % left.size());
		int k = *itr;
		left.remove(k);
		//int k = remaining[rand() % (int)remaining.size()];


		addMove(1, k % row, k / col);
	} while (left.size() > 0);

}

inline bool Board::isValidMove(int x, int y)
{
	if (isInBounds(x, y) && isEmpty(x, y))
		return true;
	else
		return false;
}

inline bool Board::isInBounds(int x, int y)
{
	return x < row  && x >= 0 && y < col && y >= 0;
}

inline bool Board::isEmpty(int x, int y)
{
	return grid[x][y] == 0;
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
			if (grid[i][j] == 0) {
				cout << "   |";
			}
			else if (grid[i][j] > 0) {
				cout << " " << grid[i][j] << " |";
			}
			else if (grid[i][j] < 0) {
				cout << "" << grid[i][j] << " |";
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

void Board::printMoves()
{
	for (int i = move.size(); i > 0; i--)
	{
		cout << "Move : " << i << " x: " << move.top().first + 1 << " y: " << move.top().second + 1 << endl;
		move.pop();
	}
}