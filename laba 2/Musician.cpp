//Класс МУЗЫКАНТ.
//Данные: имя, фамилия, пол, год рождения, инструмент, рейтинг.
//Создать трех музыкантов в стеке и одного в куче.Данные первых трех заполнить с
//помощью сеттеров, а четвертый проинициализировать с помощью конструктора с
//параметрами.В главной функции проимитировать три концерта и голосование
//зрителей по их результатам(нарастить рейтинг каждого музыканта на случайное число
//	из диапазона 1..5).Вывести список музыкантов в порядке убывания суммарного
//	рейтинга, но клавишники должны идти впереди, независимо от рейтинга.
#include "Musician.h"
#include <iostream>
#include <fstream>

using namespace std;

Musician::Musician() {

	name_ = "NoName";
	surname_ = "NoName";
	year_ = 2001;
	tool_ = Tools::Strings;
	rating_ = 0;

	cout << "Музыкант " << name_ << " " << surname_ << " занесен в базу" << endl<<endl;
}

Musician::Musician(const string& name, const string& surname, const Tools tool, int year):
	name_(name),surname_(surname),tool_(tool),year_(year),rating_(0)
{
	cout << "Музыкант " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Musician::~Musician() {
	cout << "Музыкант " << name_ << " " << surname_ << " уволен к чертям" << endl << endl;
}



string Musician::getName()const {
	return name_;
}
string Musician::getSurname()const {
	return surname_;
}
int Musician::getYear()const {
	return year_;
}
Tools Musician::getTool()const {
	return tool_;
}
int Musician::getRating()const {
	return rating_;
}


void Musician::setName(const string& name) {
	name_ = name;
}
void Musician::setSurname(const string& surname) {
	surname_ = surname;
}
void Musician::setYear(const int year) {
	year_ = year;
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

		fout << "Имя:" << name_ << endl;
		fout << "Фамилия:" << surname_ << endl;
		fout << "Год рождения:" << year_ << endl;
		fout << "Рейтинг" << rating_ << endl;
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

void Musician::deserialize() {

	const string path = name_ + surname_ + ".txt";
	string line;

	ifstream fin(path);
	if (fin.is_open()) {
		while (getline(fin,line))
		{
			cout << line << endl;
		}
	}
	fin.close();
}

void Musician::serialize(const string& filename)const {

	ofstream fout(filename, ios_base::app | ios::trunc);

	if (fout.is_open()) {

		fout << "Имя:" << name_ << endl;
		fout << "Фамилия:" << surname_ << endl;
		fout << "Год рождения:" << year_ << endl;
		fout << "Рейтинг" << rating_ << endl;
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

void Musician::deserialize(const string& filename) {

	string line;
	ifstream fin(filename, ios_base::app | ios_base::trunc);
	if (fin.is_open()) {
		while (getline(fin, line)) {
			cout << line << endl;
		}
	}
	fin.close();
}

void Musician::Imitation() {

	for (int i = 0; i < 3; i++) {

		cout << "Концерт № " << i + 1 << "Музыканта " << name_ << endl;
		 
		rating_ += rand() % 5 + 1;
		cout << "Рейтинг музыканта " << name_ << " " << surname_ << " : " << rating_<< endl << endl;
		
	}
	cout <<"----------------------------------------------------------------------------"<< endl;
}

void Musician::Print() {

	cout << "Имя: " << name_ << endl;
	cout << "Фамилия: " << surname_ << endl;
	cout << "Год рождения: " << year_ << endl;
	cout << "Тип инструмента: " << tool_ << endl;
	cout << "Рейтинг: " << rating_ << endl<<endl;
}

void Musician::Sort(Musician* arr, int len) {

	Musician tmp;
	for (size_t i = 0; i < len; i++) {
		int max = i;
		for (size_t j = i + 1; j < len; j++) {
			if (arr[j].rating_ > arr[max].rating_) {
				max = j;
			}
		}
		if (max != i) {
			tmp = arr[i];
			arr[i] = arr[max];
			arr[max] = tmp;
		}
	}
}










