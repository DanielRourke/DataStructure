// Practical3.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* Main.cpp
*
*  Created on : 10 / 08 / 2014
* Author: dongmo
*/
#include "pch.h"
#include "time.h"
#include "Neighbour.h"
#include "Board.h"

int main()
{
	srand(time(NULL));
	cout << "Base code for Practical 3.4" << endl;
	cout << "Input the size of board, say (3 3), (3 5) or (5 5): " << endl;

	int row, col;
	cin >> row >> col;

	Board board(row, col);
	//board.play();
	board.randomPlay();
	board.printMoves();

	return 0;
}

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n"; 
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file