#include "Game.h"

Game::Game(int count_deck, int minBet, int maxBet) :minBet_(minBet), maxBet_(maxBet) {

	for (int i = 0; i < count_deck; i++) {
		decks_.push_back(new Deck());
		decks_[i]->Shuffle();
	}
	dealer_ = new Dealer();
	player_ = new Player();
}

Game::~Game() {

	for (vector<Deck*>::iterator it = decks_.begin(); it < decks_.end(); ++it)
		delete* it;

	delete dealer_;
	delete player_;
}

void Game::PrintStatus() {
	cout << "Диллер:";
	for (int i = 0; i < decks_.size(); i++)
		cout << " [" << decks_[i]->getSize() << "] ";

	cout <<endl<< "Диллер:";
	dealer_->getHand()->PrintCards();

	cout << endl << "Вы:";
	player_->getHand()->PrintCards();
	cout <<endl<< endl << "Ваш баланс: " << player_->getBalance() << endl;
	cout<<"Ваш текущий счет: "<< player_->getHand()->CalculateScore() << endl;
	cout << "Текущий счет диллера: " << dealer_->getHand()->CalculateScore() << endl<<endl;
}

void Game::Lose() { //Проигрыш игрока
	PrintStatus();
	cout <<endl<< "вы проиграли!"<<endl<<"Ваш баланс: "<<player_->getBalance()<< endl<<"Ваш счет: "<<player_->getHand()->CalculateScore()<<endl<<"Счет диллера: "<< dealer_->getHand()->CalculateScore()<<endl<<endl;
	player_->getHand()->ResetHand();
	dealer_->getHand()->ResetHand(); 
}


void Game::Win(int coef1,int coef2) { //победа игрока

	PrintStatus();

	player_->addBalance(player_->getCurrentBet());
	player_->addBalance((player_->getCurrentBet() / coef2) * coef1);

	cout <<endl<< "Вы Выиграли!" << endl << "Ваш баланс: " << player_->getBalance() << endl << "Ваш Счет: " << player_->getHand()->CalculateScore() << endl << "Счет диллера: " << dealer_->getHand()->CalculateScore() << endl;
	player_->getHand()->ResetHand();
	dealer_->getHand()->ResetHand();
}

void Game::Drawn() {

	PrintStatus();
	player_->addBalance(player_->getCurrentBet());
	cout<<endl<<"Ничья!"<<endl<< "Ваш баланс: " << player_->getBalance() << endl << "Ваш Счет: " << player_->getHand()->CalculateScore() << endl << "Счет диллера: " << dealer_->getHand()->CalculateScore() << endl;
	player_->getHand()->ResetHand();
	dealer_->getHand()->ResetHand();
}


bool Game::TakeMore() {

	try {
		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());

		if (player_->getHand()->CalculateScore() > 21) {
			throw "Перебор";
		}
		else {
			//PrintStatus();
			return true;
		}
	}
	catch (...) {
		cout << "Многовато карт" << endl;
		Lose();
		return false;
	}

}


int& Game::setSelect() {

	return select_;
}

void Game::Play() {

	int all_count_cards = 0;
	cout << "Начать игру" << endl<<endl;
	while (true) {

		dable_ = false;
		triple_ = false;

		for (int i = 0; i < decks_.size(); i++) {
			all_count_cards += decks_[i]->getSize();
		}

		if (all_count_cards < 52 * decks_.size() / 3) {

			int count_deck = decks_.size();

			for (vector<Deck*>::iterator it = decks_.begin(); it < decks_.end(); ++it)
				delete* it;
			
			for (int i = 0; i < count_deck; i++) {
				decks_.push_back(new Deck());
			}
		}


		cout << "Ваш баланс: " << player_->getBalance() << endl;
		cout << "Минимальная ставка: " << minBet_ << endl << "Максимальная ставка: " << maxBet_ << endl;
		cout << "Ставка ";


		cin >> player_->NewBet();
		if (!cin) {
			cout << "Введены неверные значения" << endl;
			break;
		}
		else
			if ((player_->getBalance() - player_->getCurrentBet()) < 0) {
				cout << "Недостаточно денег";
				break;
			}
			else
				if (player_->getCurrentBet() < minBet_ || player_->getCurrentBet() > maxBet_) {
					cout << "несоответствие граничным ставкам" << endl;
					break;
				}
				else {
					player_->SubBalance(player_->getCurrentBet());
					player_->setStartBet(player_->getCurrentBet());
				}
		cout<<endl << "Ваш баланс: " << player_->getBalance() << endl;
		cout << "Текущая ставка: " << player_->getCurrentBet() << endl << endl;


		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
		dealer_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());

		

	


		while (true) {
			
			PrintStatus();

			//если у игрока блек джек с первых двух карт, 
			if (player_->getHand()->IsBlackDjeck()) {

				if (dealer_->getHand()->getCards()[0]->getScore() == 11) {
						 cout << "1-дальше." << endl << "2. Хватит(продолжить играть)"<<endl<<"3. Дабл"<<endl<<"4. Получить деньги(ставка 1 к 1)" << endl;
						 
				}
				else {
					cout << "У вас Блек Джек" << endl;
					if (player_->getHand()->getCards()[0]->getSuit() == player_->getHand()->getCards()[1]->getSuit()) {
						Win(2, 1);
					}
					else
					{
						Win(3, 2);
					}
					break;
				}
			}
			else {
				
				if (!dable_)
					cout << "1-дальше." << endl << "2. Хватит(продолжить играть)" << endl << "3. Дабл" << endl;
				else if (dable_&&!triple_) cout << "1-Еще." << endl << "2. Хватит(продолжить играть)" << endl << "3. Трипл" << endl;
				else  cout << "1-дальше." << endl << "2. Хватит(продолжить играть)" << endl;
			}

			cin >> setSelect();
			if (!cin) {
				cout << "Нет такогог выбора" << endl;
				select_ = 0;
			}

			if (select_ == 1) {

				if (!TakeMore()) break;
			}

			if (select_ == 2) {

				int dealer_score = dealer_->getHand()->CalculateScore();
				int player_score = player_->getHand()->CalculateScore();

				while (dealer_score<=16)
				{
					dealer_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
					dealer_score = dealer_->getHand()->CalculateScore();
				}


				if (dealer_score > 21) {
					Win(1,1);
					cout << "У диллера перебор" << endl;;
					break;
				}

				if (dealer_->getHand()->IsBlackDjeck()) {

					if (!player_->getHand()->IsBlackDjeck()) {
						Lose();
						break;
					}
					else
					{
						Drawn();
						break;
					}
				}
				else //нет б.д. у дил.
				{
					if (player_->getHand()->IsBlackDjeck()) {
						if (player_->getHand()->getCards()[0]->getSuit() == player_->getHand()->getCards()[1]->getSuit()) {
							Win(2, 1);
						}
						else {
							Win(3, 2);
						}
						break;
					}
					else //игрока нет б.д
					{
						if (dealer_score < player_score) {
							Win(1, 1);
							break;
						}
						if (dealer_score > player_score) {
							Lose();
							break;
						}
						if (dealer_score == player_score) {
							Drawn();
							break;
						}
					}
				}
			}

			if (select_ == 3) {
				cout << endl;
				if (!dable_) {
					cout << "Ставка до Дабла: " << player_->getCurrentBet() << endl;
					player_->NewBet() = player_->getStartBet() * 2;
					player_->SubBalance(player_->getStartBet());
					cout << "Ставка после Дабла: "<<player_->getCurrentBet() << endl;
					dable_ = true;
					if (!TakeMore()) break;
				}else
				if (dable_&&!triple_) {
					cout << "Ставка до трипла" << player_->getCurrentBet() << endl;
					player_->NewBet() = player_->getStartBet() * 3;
					player_->SubBalance(player_->getStartBet());
					cout << "Ставка после трипла" << player_->getCurrentBet() << endl;
					triple_ = true;
					if (!TakeMore()) break;
				}
				cout << endl;
				PrintStatus();
			}

			if (select_ == 4 && player_->getHand()->IsBlackDjeck()) {
				cout << "Вы забрали деньги" << endl;
				Win(1, 1);
				break;
			}
		}


		select_ = 0;
		while (select_!=2) {

			cout << "1. сыграть еще" << endl << "2. выйти" << endl << endl;

			cin >> setSelect();
			if (!cin) {
				cout << "Нет такого выбора" << endl;
				select_ = 0;
			}

			if (select_ == 1) {
				system("cls");
				break;
			}
		}
		
		if (player_->getBalance() <= 0)
		{
			cout << "Вы протграли" << endl;
			break;
		}

		if (player_->getBalance() >= 100000)
		{
			cout << "Получено достижение:Мама я богат!" << endl;
			break;
		}

		if (select_ == 2)break;
	}
}

