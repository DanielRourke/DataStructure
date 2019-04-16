// Assignment1-mapBased.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the code
has been written/produced for me by another person or copied from any
other source.
I hold a copy of this assignment that I can produce if the original is
lost or damaged.
**************************/

#include "pch.h"
#include <iostream>
#include "Board.h"

int main()
{
    std::cout << "Hello World!\n"; 
	Board board1(3 ,3);

	board1.printBoard();
	board1.addMove(Move(0, 0), 0);

	board1.printBoard();
	board1.addMove(Move(0, 2), 1);

	board1.printBoard();
	Move move(0, 1);
	board1.getNeighbours(move);
	move.printTargets();
	board1.addMove(move, 0);
	
	board1.printBoard();
	Board board2(board1);

	board1.printBoard();
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
