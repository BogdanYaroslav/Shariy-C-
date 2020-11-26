#include "Spectator.h"
#include <iostream>
#include <fstream>
#include <vector>

Spectator::Spectator():Personality(),place_("не забронировано"){

	
	cout << "Зритель " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Spectator::Spectator(const string& name, const string& surname, char gender, int year) :
	Personality(name, surname, gender, year), place_("не забронировано")
{
	cout << "Зритель " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Spectator::~Spectator() {
	cout << "Зритель " << name_ << " " << surname_ << " уволен " << endl << endl;
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

		fout << "Имя зрителя: " << name_ << endl;
		fout << "Фамилия зрителя: " << surname_ << endl;
		fout << "Год рождения зрителя: " << year_ << endl;
		fout << "Пол зрителя: " << gender_ << endl;
		fout << "Место зрителя в зале : " << year_ << endl;
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
	cout << "Зритель " << name_ << " " << surname_ << " Занял место: " << place_ << endl << endl;
}


void Spectator::Print() {

	cout << "Имя зрителя: " << name_ << endl;
	cout << "Фамилия зрителя: " << surname_ << endl;
	cout << "Год рождения зрителя: " << year_ << endl;
	cout << "Пол зрителя: " << gender_ << endl;
	cout << "Место зрителя в зале : " << place_ << endl<<endl;
}