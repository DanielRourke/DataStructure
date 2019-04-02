// Assignment1-rework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Game.h"

int main()
{
	srand((int)time(NULL));
	int row, col;

	//do
	//{
	//	cout << "Input the size of board, say (3 3), (3 5) or (5 5): " << endl;

	//	cin >> row >> col;

	//} while ((row == 3 && (col == 3 || col == 5)) || (row == 5 && col == 5));


		//cout << "Input the size of board, say (3 3), (3 5) or (5 5): " << endl;

		//cin >> row >> col;



	Game game(3, 3);
	game.play();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
