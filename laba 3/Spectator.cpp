#include "Spectator.h"
#include <iostream>
#include <fstream>
#include <vector>

Spectator::Spectator():Personality(),place_("�� �������������"){

	
	cout << "������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Spectator::Spectator(const string& name, const string& surname, char gender, int year) :
	Personality(name, surname, gender, year), place_("�� �������������")
{
	cout << "������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Spectator::~Spectator() {
	cout << "������� " << name_ << " " << surname_ << " ������ " << endl << endl;
}

void Spectator::setPlace(const string& place) {
	place_ = place;
}
string Spectator::getPlace()const {
	return place_;
}

void Spectator::serialize()const {

	const string path = name_ + surname_ + ".txt";

	ofstream fout(path);
	if (fout.is_open()) {

		fout << "��� �������: " << name_ << endl;
		fout << "������� �������: " << surname_ << endl;
		fout << "��� �������� �������: " << year_ << endl;
		fout << "��� �������: " << gender_ << endl;
		fout << "����� ������� � ���� : " << year_ << endl;
	}
	fout.close();
}

void Spectator::visit() {
	string res = "";
	vector<string> buff;

	ifstream fin("Places.txt");
	if (fin.is_open()) {
		getline(fin, place_);
		while (getline(fin, res))
		{
			buff.push_back(res);
			
		}
	}
	fin.close();

	ofstream fout("Places.txt", ios_base::trunc|ios_base::out);
	if (fout.is_open()) {
		
		for (size_t i = 0; i < buff.size(); i++)
		{
			fout << buff[i] << endl;
		}
	}
	fout.close();
	buff.clear();
	cout << "������� " << name_ << " " << surname_ << " ����� �����: " << place_ << endl << endl;
}


void Spectator::Print() {

	cout << "��� �������: " << name_ << endl;
	cout << "������� �������: " << surname_ << endl;
	cout << "��� �������� �������: " << year_ << endl;
	cout << "��� �������: " << gender_ << endl;
	cout << "����� ������� � ���� : " << place_ << endl<<endl;
}