#pragma once
#include "pch.h"
#include "Move.h"
class Board
{
private:
	int row, col;
	unordered_map<int, int> grid;
public:
	Board();
	~Board();
	Board(int r, int c);
	Board(const Board& cboard);
	void printBoard();
	//bool isValidMove(int move) const;
	bool isValidMove(Move move) const;
	int boardMove(int, int) const;
	void addMove(int, int);
	void addMove(Move);
	unordered_map<string, int> getNeighbours(Move move);
	unordered_map<string, int> getTargets(Move move) const;
	bool isInBounds(int x, int y) const;
};


Board::Board(int r, int c) {
	row = r;
	col = c;

	for (int i = 0; i < row * col; i++)
	{
		grid.emplace( i , 0);
	}
}


Board::Board()
{
}


Board::~Board()
{
}

inline void Board::printBoard()
{
	//top numbers
	cout << " ";
	for (int i = 0; i < col; i++)
	{
		cout << "  ";
		if (i < 10)
		{
			cout << " ";
		}
		cout << i + 1;
	}
	
	cout << endl;

	//start next line 
	 //draw top line
    cout << "  " << (char)201;

	for (int i = 0; i < col; i++)
	{
		cout << (char)205 << (char)205 << (char)205;
		if (i < col - 1)
		{
			cout << (char)203;
		}
	}

	cout << (char)187;

	//draw line with board values

	for (int i = 0; i < row; i++)
	{
		cout << endl;
		if (i < 9)
		{
			cout << " ";
		}

		cout << i + 1;

		for (int j = 0; j < col; j++)
		{
			if (grid[i * col + j] == 0)
			{
				cout << (char)186 << "   ";
			}
			else if (grid[i * col + j] > 0)
			{
				cout << (char)186 << " " << grid[i * col + j] << " ";
			}
			else if (grid[i * col + j] < 0)
			{
				cout << (char)186 << grid[i * col + j] << " ";
			}
			
		}

		cout << (char)186;


		//
		//draw line in the middle

		if (i < row - 1)
		{

			cout << endl << "  " << (char)204;

			for (int i = 0; i < col; i++)
			{
				cout << (char)205 << (char)205 << (char)205;
				if (i < col - 1)
				{
					cout << (char)206;
				}
				else
				{
					cout << (char)185;
				}
			}

		}

	}

	//draw last line
	cout << endl << "  " << (char)200;

	for (int i = 0; i < col; i++)
	{
		cout << (char)205 << (char)205 << (char)205;
		if (i < col - 1)
		{
			cout << (char)202;
		}
	}
	cout << (char)188 << endl;
}

//inline bool Board::isValidMove(int k) const
//{
//	return k / col < row  && k / col >= 0 && k % col < col && k % col >= 0 && grid.at(k) == 0;
//}

inline bool Board::isValidMove(Move move) const
{
	return  move.x < row  && move.x >= 0 && move.y < col && move.y >= 0 && grid.at(move.x * col + move.y) == 0;
}


inline int Board::boardMove(int i, int j) const
{
	return i * col + j;
}

//inline void Board::addMove(int k, int p)
//{
//	if (p == 0)
//	{
//		grid[k] += 1;
//	}
//	else if (p == 1)
//	{
//		grid[k] -= 1;
//	}
//	
//}

inline void Board::addMove(Move move)
{
	if (move.player == 0)
	{
		grid[move.x * col + move.y] += 1;
	}
	else if (move.player == 1)
	{
		grid[move.x * col + move.y] -= 1;
	}

}




unordered_map<string, int> Board::getTargets(Move move) const
{
	unordered_map<string, int> targets;

	if (move.x + 1 < row  && move.x + 1 >= 0 && move.y < col && move.y >= 0 && grid.at((move.x + 1) * col + move.y) < 6 && grid.at((move.x + 1) * col + move.y) != 0)
	{
		targets.emplace("Bottom", grid.at((move.x + 1) * col + move.y));
	}

	if (move.x - 1 < row  && move.x - 1 >= 0 && move.y < col && move.y >= 0 && grid.at((move.x - 1) * col + move.y) < 6 && grid.at((move.x - 1) * col + move.y) != 0)
	{
		targets.emplace("Top", grid.at((move.x - 1) * col + move.y));
	}

	if (move.x < row  && move.x >= 0 && move.y + 1 < col && move.y + 1 >= 0 && grid.at(move.x * col + (move.y + 1)) < 6 && grid.at(move.x * col + (move.y + 1)) != 0)
	{
		targets.emplace("Right", grid.at(move.x  * col + (move.y + 1)));
	}

	if (move.x < row  && move.x >= 0 && move.y - 1 < col && move.y - 1 >= 0 && grid.at(move.x * col + (move.y - 1)) < 6 && grid.at(move.x * col + (move.y - 1)) != 0)
	{
		targets.emplace("Left", grid.at(move.x * col + (move.y - 1)));
	}

	return targets;

}
