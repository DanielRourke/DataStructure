#pragma once
#include "Player.h"
class HumanPlayer :
	public Player
{
public:
	HumanPlayer() : Player() {};
	HumanPlayer(int i, string name = "Human Player ") : Player(i, name += to_string(i)) {};
	~HumanPlayer() {};

	Move getMove(const Board &board)
	{
		cout << name << endl;
		Move move;
		move.player = this->id;
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


		map<string, int> targets = board.getTargets(move);



		cout << endl;
		

		string input;
		bool targetsValid;
		cin.clear();
		cin.ignore();
		if (targets.size() > 1)
		{
			move.captureTargets = targets;
			do
			{
				targetsValid = true;

				if (targets.size() > 2)
				{
					for (auto& target : targets)
					{
						cout << target.first << " : " << target.second << " ";
					}
					move.captureTargets.clear();
					cout << "Enter two or more Directions to capture" << endl;
					getline(cin, input);
					stringstream captureTargets(input);

					while (captureTargets >> input)
					{
						try
						{
							move.captureTargets.emplace(input, targets.at(input));
						}
						catch (const out_of_range& oor)
						{
							cout << "Invalid Inputs" << endl;
							targetsValid = false;
							break;
						}
					}
				}

			} while (move.captureTargets.size() < 2 || targetsValid == false || board.countTargets(move) > 6);
		}

		//for (auto& target : move.captureTargets)
		//{
		//	cout << target.first << " : " << target.second << " ";
		//}

		cout << endl;


		return move;
	}

};




