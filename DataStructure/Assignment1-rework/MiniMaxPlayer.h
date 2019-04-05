#pragma once
#include "Player.h"
class MiniMaxPlayer :
	public Player
{
public:
	MiniMaxPlayer() : Player() {};
	MiniMaxPlayer(int i, string name = "MiniMax Player") : Player(i, name) {};
	~MiniMaxPlayer() {};
	Move getMove(const Board &board)
	{

		/*
		fun
			nested for loop
				if win return 1 if lose  return -1
				
				list  move.score  =  call fun(updated board)

				go through moves return best one

		*/
	}
};



