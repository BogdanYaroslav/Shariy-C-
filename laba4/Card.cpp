#include "Card.h"


Card::Card(char value, char suit):value_(value),suit_(suit) {
}

Card::~Card(){}

char Card::getName()const {
	return value_;
}
void Card::setName(char value) {
	value_ = value;
}

char Card::getSuit()const {
	return suit_;
}
void Card::setSuit(char suit) {
	suit_ = suit;
}

int Card::getScore(){

	int score;
	switch (value_)
	{
	case '2': score = 2; break;
	case '3': score = 3; break;
	case '4': score = 4; break;
	case '5': score = 5; break;
	case '6': score = 6; break;
	case '7': score = 7; break;
	case '8': score = 8; break;
	case '9': score = 9; break;

	case '1': score = 10; break;
	case 'J': score = 10; break;
	case 'Q': score = 10; break;
	case 'K': score = 10; break;

	case 'A': score = 11; break;
	default:  score = 0; break;
	}
	return score;

}



std::ostream& operator<<(std::ostream& stream, Card& card)
{
	if (card.value_ == '1')
	{
		stream << "10" <<card.suit_; 
	}
	else
	{
		stream << card.value_ << card.suit_;
	}
	return stream;
}