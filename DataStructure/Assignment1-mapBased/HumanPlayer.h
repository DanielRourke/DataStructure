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

		if (move.targets.size() < 2)
		{
			move.targets.clear();
		}
		else if (move.targets.size() > 2)
		{
			Move tempMove(move.x, move.y);
			bool inputValid;
			do
			{
				inputValid = true;
				tempMove.targets.clear();
				cin.ignore(1000, '\n');
				cout << "Capture Targets are : " << endl;
				move.printTargets();
				cout << endl;
				string input;
				string direction;
				getline(cin, input);
				stringstream captureTargets(input);

				while (captureTargets >> direction)
				{
					if (direction != "Top" && direction != "Bottom" && direction !=  "Right" && direction != "Left" && cin)
					{
							inputValid = false;
							break;
					}
					else
					{
							for (auto& target : move.targets)
							{
								if (target.direction == direction)
								{
									tempMove.targets.push_back(target);
								}
							}
					}
				}
			} while (!board.isValidMove(tempMove) || !inputValid);
			
			move.targets = tempMove.targets;

		}

		return move;
	}
};



