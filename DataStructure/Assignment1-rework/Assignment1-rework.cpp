// Assignment1-rework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*********** Declaration*******
I Daniel Stephen Rourke, 19386993, hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the code
has been written/produced for me by another person or copied from any
other source.
I hold a copy of this assignment that I can produce if the original is
lost or damaged.
**************************/

#include "pch.h"
#include "Game.h"

int main()
{
srand((int)time(NULL));
	//Game game(3,3,4);
	////	game.play();
	//game.simPlay(10,4);
	

	int row, col;

	do
	{
		cout << "input the size of board, say (3 3), (3 5) or (5 5): " << endl;

		cin >> row >> col;

	} while ((row == 3 && (col != 3 && col != 5)) || (row == 5 && col != 5));


	int gameMode = 0;
	do
	{
		cout << "Pick Game Mode" << endl
			<< "1. Human Vs Human" << endl
			<< "2. Human Vs Random" << endl
			<< "3. Random Vs Random" << endl
		    << "4. Random Vs MiniMax" << endl
			<< "5. Random Vs MonteCarlo" << endl
			<< "6. MonteCarlo Vs MiniMax" << endl
			<< "7. Random Vs MiniMaxDepth" << endl
			<< "8. MiniMax Vs MiniMaxDepth" << endl
			<< "9. MonteCarlo Vs MiniMaxDepth" << endl;

		cin >> gameMode;

	} while (gameMode < 1 || gameMode >9);
	
	Game game(row, col, gameMode);
	game.play();
	//game.simPlay(10, gameMode);
}

