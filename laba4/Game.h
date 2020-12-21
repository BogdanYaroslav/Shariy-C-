#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <exception>

class Game
{
private:
	vector<Deck*> decks_;

	int minBet_;
	int maxBet_;
	

	Dealer* dealer_;
	Player* player_;

	int select_;

	bool dable_ = false;
	bool triple_ = false;
	

public:

	Game(int count_deck,int minBer,int maxBet);
	~Game();

	void Play();
	void PrintStatus();


	void Win(int coeff1, int coeff2);
	void Lose();
	void Drawn();

	int& setSelect();

	bool TakeMore();


};

