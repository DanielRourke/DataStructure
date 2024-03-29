#pragma once
#include "pch.h"
#include "Move.h"
class Board
{
private:
	int row, col;
	unordered_map<int, int> grid;
	list<Move> remainingMoves;
public:
	Board();
	~Board();
	Board(int r, int c);
	Board(const Board& cboard);
	void printBoard();
	//bool isValidMove(int move) const;
	bool isValidMove(Move move) const;
	bool isMoveRemaining(Move move) const;
	bool isTargetsValid(list<Neighbour> targets) const;
	bool isEmptyMove(Move move) const;
	int boardMove(int, int) const;
	void addMove(Move, int);
	unordered_map<string, int> getNeighbours(Move move) const;
	list<Neighbour> getTargets(Move move) const;
	int captureTargets(Move);
	int countTargets(Move) const;
	Move getMove(int) const;
	Move getRandomMove() const;
	list<Move> getRemainingMoves() const;
	int getScore()const;
	void resetBoard(int r, int c);
	double getHuristicScore() const;


	//bool isGameOver();
};

Board::Board(int r, int c) {
	row = r;
	col = c;

	for (int i = 0; i < row * col; i++)
	{
		grid.emplace( i , 0);
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			remainingMoves.push_back(Move(i, j));
		}
}
inline void Board::resetBoard(int r, int c)
{
	row = r;
	col = c;
	grid.clear();
	remainingMoves.erase(remainingMoves.begin(), remainingMoves.end());

	for (int i = 0; i < row * col; i++)
	{
		grid.emplace(i, 0);
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			remainingMoves.push_back(Move(i, j));
		}
}



Board::Board(const Board& cboard)
{
	row = cboard.row;
	col = cboard.col;

	grid = cboard.grid;
	remainingMoves = cboard.remainingMoves;
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

inline bool Board::isTargetsValid(list<Neighbour> targets) const
{
	int pipCountTotal = 0;
	for (auto& target : targets)
	{
		if (target.direction.compare("Top") != 0 && target.direction.compare("Bottom") != 0 && target.direction.compare("Right") != 0 && target.direction.compare("Left") != 0)
		{
			return false;
		}
		pipCountTotal += abs(target.pipCount);
	}


	if (pipCountTotal > 6)
	{
		return false;
	}

	if (targets.size() == 1 || targets.size() > 4)
	{
		return false;
	}


	return true;
}

inline bool Board::isEmptyMove(Move move) const
{
	return  move.x < row  && move.x >= 0 && move.y < col && move.y >= 0 && grid.at(move.x * col + move.y) == 0;
}

inline bool Board::isMoveRemaining(Move move) const
{
	for (auto& remainingMove : remainingMoves)
	{
		if (remainingMove == move && grid.at(move.x * col + move.y) == 0)
		{
			return true;
		}
	}

	return false;
}

inline bool Board::isValidMove(Move move) const
{
	return  (isEmptyMove(move) && isMoveRemaining(move) && isTargetsValid(move.captureTargets));
}

inline int Board::boardMove(int i, int j) const
{
	return i * col + j;
}

inline Move Board::getMove(int k) const
{
	return  Move(k / col, k % col);
}

inline void Board::addMove(Move move, int playerIndex)
{
	int pipCount = 1;

	if (captureTargets(move) > 0)
	{
		pipCount = captureTargets(move);
	}
	if (playerIndex == 0)
	{
		grid[move.x * col + move.y] = pipCount;
	}
	else if (playerIndex == 1)
	{
		grid[move.x * col + move.y] = -pipCount;
	}

	remainingMoves.remove(move);
}


unordered_map<string, int> Board::getNeighbours(Move move) const
{
	unordered_map<string, int> neighbours;


	if (move.x + 1 < row  && move.x + 1 >= 0 && move.y < col && move.y >= 0 && abs(grid.at((move.x + 1) * col + move.y)) < 6 && grid.at((move.x + 1) * col + move.y) != 0)
	{
		neighbours.emplace("Bottom", grid.at((move.x + 1) * col + move.y));
	}

	if (move.x - 1 < row  && move.x - 1 >= 0 && move.y < col && move.y >= 0 && abs(grid.at((move.x - 1) * col + move.y)) < 6 && grid.at((move.x - 1) * col + move.y) != 0)
	{
		neighbours.emplace("Top", grid.at((move.x - 1) * col + move.y));
	}

	if (move.x < row  && move.x >= 0 && move.y + 1 < col && move.y + 1 >= 0 && abs(grid.at(move.x * col + (move.y + 1))) < 6 && grid.at(move.x * col + (move.y + 1)) != 0)
	{
		neighbours.emplace("Right", grid.at(move.x  * col + (move.y + 1)));
	}

	if (move.x < row  && move.x >= 0 && move.y - 1 < col && move.y - 1 >= 0 && abs(grid.at(move.x * col + (move.y - 1))) < 6 && grid.at(move.x * col + (move.y - 1)) != 0)
	{
		neighbours.emplace("Left", grid.at(move.x * col + (move.y - 1)));
	}

	int min = 7;
	int max = 0;
	do
	{
		unordered_map<string, int>::const_iterator it;
		//find min
		min = 7;
		string minDirection;
		for (auto& neighbour : neighbours)
		{
			if (abs(neighbour.second) < min)
			{
				min = abs(neighbour.second);
				minDirection = neighbour.first;
			}
		}

		//findmax
		max = 0;
		string maxDirection;
		for (auto& neighbour : neighbours)
		{
			if (abs(neighbour.second) < max)
			{
				max = abs(neighbour.second);
				maxDirection = neighbour.first;
			}
		}

		if (min + max > 6)
		{
			it = neighbours.find(maxDirection);
			if (it == neighbours.end())
			{
				cout << "something whent wrong!" << endl;
			}
			else
			{
				neighbours.erase(it);
			}
		}
	} while (neighbours.size() > 1 && min + max > 6);


	return neighbours;

}


list<Neighbour> Board::getTargets(Move move) const
{
	list<Neighbour> targets;

	if (move.x + 1 < row  && move.x + 1 >= 0 && move.y < col && move.y >= 0 && abs(grid.at((move.x + 1) * col + move.y)) < 6 && grid.at((move.x + 1) * col + move.y) != 0)
	{
		//targets.emplace("Bottom", grid.at((move.x + 1) * col + move.y));
		targets.push_back(Neighbour("Bottom", grid.at((move.x + 1) * col + move.y)));
	}

	if (move.x - 1 < row  && move.x - 1 >= 0 && move.y < col && move.y >= 0 && abs(grid.at((move.x - 1) * col + move.y)) < 6 && grid.at((move.x - 1) * col + move.y) != 0)
	{
		//targets.emplace("Top", grid.at((move.x - 1) * col + move.y));
		targets.push_back(Neighbour("Top", grid.at((move.x - 1) * col + move.y)));
	}

	if (move.x < row  && move.x >= 0 && move.y + 1 < col && move.y + 1 >= 0 && abs(grid.at(move.x * col + (move.y + 1))) < 6 && grid.at(move.x * col + (move.y + 1)) != 0)
	{
		//targets.emplace("Right", grid.at(move.x  * col + (move.y + 1)));
		targets.push_back(Neighbour("Right", grid.at(move.x  * col + (move.y + 1))));
	}

	if (move.x < row  && move.x >= 0 && move.y - 1 < col && move.y - 1 >= 0 && abs(grid.at(move.x * col + (move.y - 1))) < 6 && grid.at(move.x * col + (move.y - 1)) != 0)
	{
		//targets.emplace("Left", grid.at(move.x * col + (move.y - 1)));
		targets.push_back(Neighbour("Left", grid.at(move.x * col + (move.y - 1))));
	}


	if (targets.size() >= 2)
	{
		targets.sort(NeighbourAbsComparator());
		while (abs(targets.front().pipCount) + abs(targets.back().pipCount) > 6 && targets.size() > 1)
		{
			targets.pop_back();
		}
		targets.sort();
	}

	return targets;

}

inline int Board::captureTargets(Move move)
{
	int pipCount = countTargets(move );

	for (auto& target : move.captureTargets)
	{
		if (target.direction == "Top")
		{
			grid.at((move.x - 1) * col + move.y) = 0;
			remainingMoves.push_back(Move(move.x - 1, move.y));
		}
		else if (target.direction == "Bottom")
		{
			grid.at((move.x + 1) * col + move.y) = 0;
			remainingMoves.push_back(Move(move.x + 1, move.y));
		}
		else if (target.direction == "Right")
		{
			grid.at(move.x  * col + (move.y + 1)) = 0;
			remainingMoves.push_back(Move(move.x , move.y + 1));
		}
		else if (target.direction == "Left")
		{
			grid.at(move.x * col + (move.y - 1)) = 0;
			remainingMoves.push_back(Move(move.x , move.y - 1));
		}
	}

	return pipCount;
}

inline int Board::countTargets(Move move) const
{
	int pipCount = 0;

	for (auto& target : move.captureTargets)
	{
		pipCount += abs(target.pipCount);
	}

	return pipCount;
}

inline Move Board::getRandomMove() const
{

}

inline list<Move> Board::getRemainingMoves() const
{
	return remainingMoves;
}


inline int Board::getScore() const
{
	int total = 0;
	for (auto& cell : grid)
	{
		if (cell.second > 0)
		{
			total++;
		}
		else if (cell.second < 0)
		{
			total--;
		}
	}
	return total;
}

inline double Board::getHuristicScore() const
{
	double total = 0;
	for (auto& cell : grid)
	{
		if (cell.second == 6)
		{
			total += 1;
		}
		else if (cell.second == -6)
		{
			total -=1;
		}

		if (cell.second > 0)
		{
			total += 0.1;
		}
		else if (cell.second < 0)
		{
			total -= 0.1;
		}

	}

	return total;
}



