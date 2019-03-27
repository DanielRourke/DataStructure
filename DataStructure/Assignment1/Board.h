#pragma once
class Board
{
private:
	int row, col;
	int **grid; // 1 = black; -1 = white; 0 = empty
	list<int> left;
	stack<pair<int, int>> move;
	vector<Neighbour> neighbours;
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
	void printMoves();
	void randomPlay();
	bool isValidMove(int x, int y);
	bool isInBounds(int x, int y);
	bool isEmpty(int x, int y);
};

