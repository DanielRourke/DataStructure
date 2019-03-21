/*
 * Board.h
 *
 *  Created on: 9/3/2019
 *      Author: dongmo
 */

#ifndef BOARD_H_
#define BOARD_H_


using namespace std;

class Board {
private:
	int row, col;
	int **grid; // 1 = black; -1 = white; 0 = empty
	list<int> left;
public:
	Board(int r, int c) {
		row = r;
		col = c;
		grid = new int*[row];
		for (int i = 0; i < row; i++)
			grid[i] = new int[col];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				grid[i][j] = 0;

		for (int i = 0; i < row*col; i++) {
			left.push_back(i);
		}

	}

	~Board() {
		for (int i = 0; i < row; i++)
			delete[] grid[i];

		delete[] grid;
	}

	Board(Board& cboard) {
		row = cboard.row;
		col = cboard.col;

		grid = new int*[row];
		for (int i = 0; i < row; i++)
			grid[i] = new int[col];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				grid[i][j] = cboard.grid[i][j];
	}

	bool addMove(int player, int x, int y);
	void checkNeighbors(int, int);
	void printBoard();
	void play();
};

void Board::checkNeighbors(int x, int y) {
    /*

	check -1 1  -1, 1
	for (int i = -1; i < 2; i+=2)
	{
		for(int j = -1; j < 2; j+=2)
		{
			if()
		}
	if x< row 
	*/
	return;
}


bool Board::addMove(int player, int x, int y) {

	checkNeighbors(x, y);

	grid[x][y] = rand()%6 + 1;
	return true;
}

void Board::play() {
	int x, y;

	do {
		cout << "Game board:" << endl;
		this->printBoard();

		cout << "Input your move with row and column numbers:" << endl;
		cin >> x >> y;
		addMove(1, x-1, y-1);
	} while (true);
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
			} else if (grid[i][j] > 0) {
				cout << " " << grid[i][j] << " |";
			} else if (grid[i][j] < 0) {
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

#endif /* BOARD_H_ */
