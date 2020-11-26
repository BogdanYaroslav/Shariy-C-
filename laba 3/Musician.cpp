#include "Musician.h"
#include <iostream>
#include <fstream>


Musician::Musician() : Personality(), tool_(Tools::Strings), rating_(0), experience_(0)
{
	cout << "Музыкант " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Musician::Musician(const string& name, const string& surname, char gender, int year, const Tools& tool, int rating, int experience) :
	Personality(name,surname,gender,year),tool_(tool), rating_(rating), experience_(experience)
{
	cout << "Музыкант " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Musician::~Musician() {
	cout << "Музыкант " << name_ << " " << surname_ << " уволен" << endl << endl;
}

Tools Musician::getTool()const {
	return tool_;
}
int Musician::getRating()const {
	return rating_;
}

void Musician::setTool(const Tools tool) {
	tool_ = tool;
}
void Musician::setRating(const int rating) {
	rating_ = rating;
}

void Musician::serialize()const {

	const string path = name_ + surname_ + ".txt";

	ofstream fout(path);
	if (fout.is_open()) {

		fout << "Имя Музыканта: " << name_ << endl;
		fout << "Фамилия Музыканта: " << surname_ << endl;
		fout << "Год рождения Музыканта: " << year_ << endl;
		fout << "Пол Музыканта: " << gender_ << endl;
		fout << "Количество концертов Музыканта: " << experience_ << endl;
		fout << "Рейтинг Музыканта: " << rating_ << endl;
		switch (tool_)
		{
		case 1:
			fout << "Тип инструмента: струнные" << endl;
			break;
		case 2:
			fout << "Тип инструмента: духовые" << endl;
			break;
		case 3:
			fout << "Тип инструмента: ударные" << endl;
			break;
		case 4:
			fout << "Тип инструмента: клавишные" << endl;
			break;
		}
	}
	fout.close();
}



void Musician::Imitation() {

	for (int i = 0; i < 3; i++) {

		cout << "Концерт № " << i + 1 << "Музыканта " << name_ << endl;

		rating_ += rand() % 5 + 1;
		cout << "Рейтинг музыканта " << name_ << " " << surname_ << " : " << rating_ << endl << endl;

	}
	cout << "----------------------------------------------------------------------------" << endl;
}

void Musician::visit() {
	experience_++;
	rating_ += rand() % 5 + 1;
	cout << "Рейтинг музыканта " << name_ << " " << surname_ << " : " << rating_ << endl << endl;
}

void Musician::Print() {

	cout << "Имя Музыканта: " << name_ << endl;
	cout << "Фамилия Музыканта: " << surname_ << endl;
	cout << "Год рождения Музыканта: " << year_ << endl;
	cout << "Пол Музыканта: " << gender_ << endl;
	cout << "Количество концертов Музыканта: " << experience_ << endl;
	cout << "Рейтинг Музыканта: " << rating_ << endl;
	cout << "Тип инструмента: " << tool_ << endl<<endl;
}