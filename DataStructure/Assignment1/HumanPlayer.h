#pragma once
#include "pch.h"

class HumanPlayer :
	public Player
{
public:
	HumanPlayer() : Player() {};
	HumanPlayer(int id, string name = "Human : Player ") : Player(id, name + to_string(id)){};
	~HumanPlayer() {};
	Move getMove(const Board &board, const vector<int> &rMoves)
	{
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
		} while (!board.isValidMove(move));

		unordered_map<string, int> targets;
		targets = board.getTargets(move);
		unordered_map<string, int>::const_iterator it;

		if (targets.size() > 1)
		{
			do
			{
				
				move.captureTargets.clear();
				cout << "Neighbouring Cells are : " << endl;
				for (auto& neighbour : targets)
				{
					cout << neighbour.first << " : " << neighbour.second << " ";
				}
				cout << endl;
				string input;
				string direction;
				getline(cin, input);
				stringstream captureTargets(input);
				while (captureTargets >> direction)
				{
					it = targets.find(direction);
					if (it == targets.end())
					{
						break;
					}

			/*		try
					{
						move.captureTargets.emplace(direction, targets.at(direction));
					}
					catch (const out_of_range& oor)
					{
						inputValid = false;
					}*/

					/*std::unordered_map<std::string, double>::const_iterator got = mymap.find(input);

					if (got == mymap.end())
						std::cout << "not found";
					else
						std::cout << got->first << " is " << got->second;*/
				}
			} while (!board.isValidMove(move) && it == targets.end());
		}

		return move;
	}

};



