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
	cout << "������:";
	for (int i = 0; i < decks_.size(); i++)
		cout << " [" << decks_[i]->getSize() << "] ";

	cout <<endl<< "������:";
	dealer_->getHand()->PrintCards();

	cout << endl << "��:";
	player_->getHand()->PrintCards();
	cout <<endl<< endl << "��� ������: " << player_->getBalance() << endl;
	cout<<"��� ������� ����: "<< player_->getHand()->CalculateScore() << endl;
	cout << "������� ���� �������: " << dealer_->getHand()->CalculateScore() << endl<<endl;
}

void Game::Lose() { //�������� ������
	PrintStatus();
	cout <<endl<< "�� ���������!"<<endl<<"��� ������: "<<player_->getBalance()<< endl<<"��� ����: "<<player_->getHand()->CalculateScore()<<endl<<"���� �������: "<< dealer_->getHand()->CalculateScore()<<endl<<endl;
	player_->getHand()->ResetHand();
	dealer_->getHand()->ResetHand(); 
}


void Game::Win(int coef1,int coef2) { //������ ������

	PrintStatus();

	player_->addBalance(player_->getCurrentBet());
	player_->addBalance((player_->getCurrentBet() / coef2) * coef1);

	cout <<endl<< "�� ��������!" << endl << "��� ������: " << player_->getBalance() << endl << "��� ����: " << player_->getHand()->CalculateScore() << endl << "���� �������: " << dealer_->getHand()->CalculateScore() << endl;
	player_->getHand()->ResetHand();
	dealer_->getHand()->ResetHand();
}

void Game::Drawn() {

	PrintStatus();
	player_->addBalance(player_->getCurrentBet());
	cout<<endl<<"�����!"<<endl<< "��� ������: " << player_->getBalance() << endl << "��� ����: " << player_->getHand()->CalculateScore() << endl << "���� �������: " << dealer_->getHand()->CalculateScore() << endl;
	player_->getHand()->ResetHand();
	dealer_->getHand()->ResetHand();
}


bool Game::TakeMore() {

	try {
		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());

		if (player_->getHand()->CalculateScore() > 21) {
			throw "�������";
		}
		else {
			//PrintStatus();
			return true;
		}
	}
	catch (...) {
		cout << "��������� ����" << endl;
		Lose();
		return false;
	}

}


int& Game::setSelect() {

	return select_;
}

void Game::Play() {

	int all_count_cards = 0;
	cout << "������ ����" << endl<<endl;
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


		cout << "��� ������: " << player_->getBalance() << endl;
		cout << "����������� ������: " << minBet_ << endl << "������������ ������: " << maxBet_ << endl;
		cout << "������ ";


		cin >> player_->NewBet();
		if (!cin) {
			cout << "������� �������� ��������" << endl;
			break;
		}
		else
			if ((player_->getBalance() - player_->getCurrentBet()) < 0) {
				cout << "������������ �����";
				break;
			}
			else
				if (player_->getCurrentBet() < minBet_ || player_->getCurrentBet() > maxBet_) {
					cout << "�������������� ��������� �������" << endl;
					break;
				}
				else {
					player_->SubBalance(player_->getCurrentBet());
					player_->setStartBet(player_->getCurrentBet());
				}
		cout<<endl << "��� ������: " << player_->getBalance() << endl;
		cout << "������� ������: " << player_->getCurrentBet() << endl << endl;


		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
		dealer_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());

		

	


		while (true) {
			
			PrintStatus();

			//���� � ������ ���� ���� � ������ ���� ����, 
			if (player_->getHand()->IsBlackDjeck()) {

				if (dealer_->getHand()->getCards()[0]->getScore() == 11) {
						 cout << "1-������." << endl << "2. ������(���������� ������)"<<endl<<"3. ����"<<endl<<"4. �������� ������(������ 1 � 1)" << endl;
						 
				}
				else {
					cout << "� ��� ���� ����" << endl;
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
					cout << "1-������." << endl << "2. ������(���������� ������)" << endl << "3. ����" << endl;
				else if (dable_&&!triple_) cout << "1-���." << endl << "2. ������(���������� ������)" << endl << "3. �����" << endl;
				else  cout << "1-������." << endl << "2. ������(���������� ������)" << endl;
			}

			cin >> setSelect();
			if (!cin) {
				cout << "��� ������� ������" << endl;
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
					cout << "� ������� �������" << endl;;
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
				else //��� �.�. � ���.
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
					else //������ ��� �.�
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
					cout << "������ �� �����: " << player_->getCurrentBet() << endl;
					player_->NewBet() = player_->getStartBet() * 2;
					player_->SubBalance(player_->getStartBet());
					cout << "������ ����� �����: "<<player_->getCurrentBet() << endl;
					dable_ = true;
					if (!TakeMore()) break;
				}else
				if (dable_&&!triple_) {
					cout << "������ �� ������" << player_->getCurrentBet() << endl;
					player_->NewBet() = player_->getStartBet() * 3;
					player_->SubBalance(player_->getStartBet());
					cout << "������ ����� ������" << player_->getCurrentBet() << endl;
					triple_ = true;
					if (!TakeMore()) break;
				}
				cout << endl;
				PrintStatus();
			}

			if (select_ == 4 && player_->getHand()->IsBlackDjeck()) {
				cout << "�� ������� ������" << endl;
				Win(1, 1);
				break;
			}
		}


		select_ = 0;
		while (select_!=2) {

			cout << "1. ������� ���" << endl << "2. �����" << endl << endl;

			cin >> setSelect();
			if (!cin) {
				cout << "��� ������ ������" << endl;
				select_ = 0;
			}

			if (select_ == 1) {
				system("cls");
				break;
			}
		}
		
		if (player_->getBalance() <= 0)
		{
			cout << "�� ���������" << endl;
			break;
		}

		if (player_->getBalance() >= 100000)
		{
			cout << "�������� ����������:���� � �����!" << endl;
			break;
		}

		if (select_ == 2)break;
	}
}

