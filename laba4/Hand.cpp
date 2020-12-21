#include "Hand.h"

Hand::Hand(){}


Hand::~Hand(){
	for (std::vector<Card*>::iterator it = cards.begin(); it < cards.end(); ++it)
		delete* it;
}


void Hand::addCard(Card* card) {
	cards.push_back(card);
}

void Hand::ResetHand() {
	for (std::vector<Card*>::iterator it = cards.begin(); it < cards.end(); ++it)
		delete* it;
	cards.clear();
}

int Hand::getCountCard(){
	return cards.size();
}

int Hand::CalculateScore() {

	int summ = 0;

	for (int i = 0; i < cards.size(); i++) {
	summ += cards[i]->getScore();	
	}

	if (summ > 21) {
		summ = 0;
		for (int i = 0; i < cards.size(); i++) {
			if (cards[i]->getName() == 'A') {
				summ += 1;
			}
			else
			{
				summ += cards[i]->getScore();
			}
		}

	}


	return summ;
}

void Hand::PrintCards() {
	for (int i = 0; i < cards.size(); i++) {
		cout << *cards[i]<<"  ";
	}
}

vector<Card*> Hand::getCards()const {
	return cards;
}

bool Hand::IsBlackDjeck() {
	if (cards.size() == 2) {
		if (cards[0]->getScore() == 10 && cards[1]->getScore() == 11) {
			return true;
		}
		if (cards[0]->getScore() == 11 && cards[1]->getScore() == 10) {
			return true;
		}
	}
	return false;
}