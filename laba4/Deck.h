#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include <iterator>
class Deck
{
private:

	vector<Card*> deck;
	
	
public:

	Deck();
	~Deck();
	void Shuffle();
	int getSize()const;
	void Print();
	Card* pop();
};

