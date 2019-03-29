#pragma once
class Game
{
private:
	Board gameBoard;
	Player* players[2];
	vector<Move> remaingMoves;
	stack<Move> previousMoves;
public:
	Game(int row = 3, int col = 3): gameBoard(row,col)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				remaingMoves.push_back(Move(i, j));
			}

		players[0] = new HumanPlayer(1);
	}
	~Game();
	void play()
	{

		gameBoard.printBoard();

	}
};
//board add move (vector<move>)
