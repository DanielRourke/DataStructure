#include "pch.h"
#include "Board.h"


Board::Board(int r = 3, int c =3)
{
	row = r;
	col = c;

	grid = new int*[row];
	for (int i = 0; i < row; i++)
		grid[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			grid[i][j] = 0;
			remainingMoves.push_back(Move(i, j));
		}

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			if (x + 1 < row  && x + 1 >= 0 && y < col && y >= 0 )
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Bottom", &grid[x + 1][y]));
			}
				
			if (x - 1 < row  && x - 1 >= 0 && y < col && y >= 0 )
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Top", &grid[x - 1][ y]));
			}
				
			if (x < row  && x >= 0 && y + 1 < col && y + 1 >= 0 )
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Right", &grid[x][ y + 1]));
			}
				
			if (x < row  && x >= 0 && y - 1 < col && y - 1 >= 0)
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Left", &grid[x][ y - 1]));
			}
		}
	}
}

Board::Board(const Board& cboard)
{
	row = cboard.row;
	col = cboard.col;

	grid = new int*[row];
	for (int i = 0; i < row; i++)
		grid[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			grid[i][j] = cboard.grid[i][j];

	remainingMoves = cboard.remainingMoves;


	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			if (x + 1 < row  && x + 1 >= 0 && y < col && y >= 0)
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Bottom", &grid[x + 1][y]));
			}

			if (x - 1 < row  && x - 1 >= 0 && y < col && y >= 0)
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Top", &grid[x - 1][y]));
			}

			if (x < row  && x >= 0 && y + 1 < col && y + 1 >= 0)
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Right", &grid[x][y + 1]));
			}

			if (x < row  && x >= 0 && y - 1 < col && y - 1 >= 0)
			{
				neighbourMap[Move(x, y)].push_back(Neighbour("Left", &grid[x][y -1]));
			}
		}
	}
}


Board::~Board()
{
	for (int i = 0; i < row; i++)
		delete[] grid[i];

	delete[] grid;
}

void Board::printBoard()
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
			if (grid[i][j] == 0)
			{
				cout << (char)186 << "   ";
			}
			else if (grid[i][j] > 0)
			{
				cout << (char)186 << " " << grid[i][j] << " ";
			}
			else if (grid[i][j] < 0)
			{
				cout << (char)186 << grid[i][j] << " ";
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

bool Board::addMove(Move move, int playerIndex)
{
	int pipCount = move.getTargetTotal();

	if (pipCount == 0)
	{
		pipCount = 1;
	}
	else if (pipCount > 6)
	{
		return false;
	}
	else
	{
		for (Neighbour target : move.targets)
		{
			if (target.direction == "Top")
			{
				*target.pipCount = 0;
				remainingMoves.push_back(Move(move.x - 1, move.y));
			}
			else if (target.direction == "Bottom")
			{
				*target.pipCount = 0;
				remainingMoves.push_back(Move(move.x + 1, move.y));
			}
			else if (target.direction == "Right")
			{
				*target.pipCount = 0;
				remainingMoves.push_back(Move(move.x, move.y + 1));
			}
			else if (target.direction == "Left")
			{
				*target.pipCount = 0;
				remainingMoves.push_back(Move(move.x, move.y - 1));
			}
		}
	}

	if (playerIndex == 0)
	{
		grid[move.x][move.y] = pipCount;
	}
	else if (playerIndex == 1)
	{
		grid[move.x][move.y] = -pipCount;
	}

	remainingMoves.remove(move);

	return true;
}

//todo
bool Board::isValidMove(Move move) 
{
	return (move.x >= 0 && move.x < row && move.y >= 0 && move.y < col
		&& grid[move.x][move.y] == 0 && move.targetTotal() < 6);

	//to do 
	/* (remaingMoves.find(move) != remaingMoves.end() ?) */
}

void Board::getNeighbours(Move & move)
{
	move.targets = neighbourMap[move];
}

Move Board::getRandomMove()
{
	list<Move>::const_iterator moveIt = remainingMoves.begin();
	advance(moveIt, rand() % remainingMoves.size());
	return *moveIt;

}
