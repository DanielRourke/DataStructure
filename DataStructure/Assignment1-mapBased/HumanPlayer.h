#pragma once
#include "pch.h"
#include "Board.h"
#include "Player.h"

class HumanPlayer :
	public Player
{
public:
	HumanPlayer() : Player() {};
	HumanPlayer(int i, string name = "Human Player ") : Player(i, name) {};
	~HumanPlayer() {};
	Move getMove(Board &board)
	{
		cout << name << endl;
		Move move;
		do
		{
			cout << "Input your move with row and column numbers:" << endl;
			cin >> move.x >> move.y;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Input";
			}

			move.x--;
			move.y--;

		} while (!board.isValidMove(move));

		board.getNeighbours(move);
		move.sortTargets();

		if (move.targets.size() > 1)
		{
			bool inputValid;
			do
			{
				inputValid = true;
				list<Neighbour> temp;
				cout << "Capture Targets are : " << endl;
				move.printTargets();
				cout << endl;
				string input;
				string direction;
				getline(cin, input);
				stringstream captureTargets(input);
				list<Neighbour>::iterator it;
				while (captureTargets >> direction)
				{
						if (input != "Top" && input != "Bottom" && input !=  "Right" && input != "Left")
						{
							inputValid = false;
						}
						else
						{
								for (auto& target : move.targets)
								{
									if (target.direction == input)
									{
										temp.push_back(target);
									}
								}
						}

				}
			} while (!board.isValidMove(move) && !inputValid);
		}

		return move;
	}
};



