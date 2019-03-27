#pragma once
class Game
{
private:
	Board* gameBoard;
	Player* players[2];
public:
	Game();
	~Game();
	stack<pair<int, int>> previousMoves;
	list<int> remainingMoves;
};

