#include "Player.h"


Player::Player() {
	hand_ = new Hand();
	balance_ = 10000;
	Currentbet_ = 0;
}

Player::~Player() {
	delete hand_;
}

int Player::getCurrentBet()const{
	return Currentbet_;
}
int& Player::NewBet() {
	return Currentbet_;
}


Hand* Player::getHand()const {
	return hand_;
}

int Player::getBalance()const {
	return balance_;
}



void Player::addBalance(int money) {
	balance_ += money;
}

void Player::SubBalance(int money) {
	balance_ -= money;
}


int Player::getStartBet()const {
	return startBet_;
}

void Player::setStartBet(int bet) {
	startBet_ = bet;
}


