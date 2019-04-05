#pragma once
#include "Player.h"

class HumanPlayer :
	public Player
{
public:
	HumanPlayer() : Player() {};
	HumanPlayer(int i, string name = "Human Player ") : Player(i, name) {};
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

		} while (!board.isMoveRemaining(move) && !board.isEmptyMove(move));

		
		list<Neighbour>targets = board.getTargets(move);

		if (targets.size() == 2)
		{
				move.captureTargets = targets;
		}
		else if (targets.size() > 2)
		{
			do {
				bool inputValid = true;
				move.captureTargets.clear();
				string input;
				cin.clear();
				cin.ignore(1000, '\n');

				for (auto& target : targets)
				{
					cout << target.direction << " : " << target.pipCount << " ";
				}

				cout << "Enter two or more Directions to capture" << endl;
				getline(cin, input);
				stringstream captureTargets(input);

				while (captureTargets >> input )
				{
					if (input.compare("Top") != 0 && input.compare("Bottom") != 0 && input.compare("Right") != 0 && input.compare("Left") != 0)
					{
						inputValid = false;
					}
					else
					{
						for (auto& target : targets)
						{
							if (target.direction == input)
							{
								move.captureTargets.push_back(target);
							}
						}
					}
					
				}

			} while (!board.isTargetsValid(move.captureTargets) || move.captureTargets.size() < 2);

		}

		return move;

	}

	//	Move getMove(const Board &board)
	//	{
	//		Move move;
	//		move = getMoveInput();
	//
	//		
	//		cout << endl;
	//		
	//
	//		
	//			do
	//			{
	//	
	//
	//				
	//					for (auto& target : targets)
	//					{
	//						if (target.direction.compare(input) == 0)
	//						{
	//
	//						}
	//				}
	//
	//
	//			} while (true);
	//
	//		}
	//
	//
	//
	//		/*if (targets.size() > 1)
	//		{
	//			move.captureTargets = targets;
	//			do
	//			{
	//				targetsValid = true;
	//
	//				if (targets.size() > 2)
	//				{
	//					for (auto& target : targets)
	//					{
	//						cout << target.direction << " : " << target.pipCount << " ";
	//					}
	//					move.captureTargets.clear();
	//					cout << "Enter two or more Directions to capture" << endl;
	//					getline(cin, input);
	//					stringstream captureTargets(input);
	//
	//					while (captureTargets >> input)
	//					{
	//						try
	//						{
	//							move.captureTargets.emplace(input, targets.at(input));
	//						}
	//						catch (const out_of_range& oor)
	//						{
	//							cout << "Invalid Inputs" << endl;
	//							targetsValid = false;
	//							break;
	//						}
	//					}
	//				}
	//
	//			} while (move.captureTargets.size() < 2 || targetsValid == false || board.countTargets(move) > 6);*/
	//		}
	//
	//		//for (auto& target : move.captureTargets)
	//		//{
	//		//	cout << target.first << " : " << target.second << " ";
	//		//}
	//
	//		cout << endl;
	//
	//
	//		return move;
	//	}
	//
	
	//
	//};
	//
	//
	//
	//
};