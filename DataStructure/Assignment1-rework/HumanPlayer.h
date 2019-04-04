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
		Move move;
		move = getMoveInput();

		move.captureTargets.clear();
		list<Neighbour>targets = board.getTargets(move);
		cout << endl;
		

		if (targets.size() == 2)
		{
			move.captureTargets = targets;
		}
		else if (targets.size() > 2)
		{
			do
			{
	

				
					for (auto& target : targets)
					{
						if (target.direction.compare(input) == 0)
						{

						}
				}


			} while (true);

		}



		/*if (targets.size() > 1)
		{
			move.captureTargets = targets;
			do
			{
				targetsValid = true;

				if (targets.size() > 2)
				{
					for (auto& target : targets)
					{
						cout << target.direction << " : " << target.pipCount << " ";
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

			} while (move.captureTargets.size() < 2 || targetsValid == false || board.countTargets(move) > 6);*/
		}

		//for (auto& target : move.captureTargets)
		//{
		//	cout << target.first << " : " << target.second << " ";
		//}

		cout << endl;


		return move;
	}

	Move getMoveInput(const Board &board)
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

		return move;
	}

	Move getTargetsInput(Move move)
	{
		string input;
		cin.clear();
		cin.ignore();

		for (auto& target : targets)
		{
			cout << target.direction << " : " << target.pipCount << " ";
		}

		cout << "Enter two or more Directions to capture" << endl;
		getline(cin, input);
		stringstream captureTargets(input);
		
		
		while (captureTargets >> input)
		{
			if(!move.add()
				
		}
	}

};




