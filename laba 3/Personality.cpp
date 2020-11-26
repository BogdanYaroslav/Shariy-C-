#include "Personality.h"
#include <iostream>
#include <fstream>


Personality::Personality() {

	name_ = "NoName";
	surname_ = "NoName";
	year_ = 2001;
	gender_ = 'm';
	cout << "Личность " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Personality::Personality(const string& name, const string& surname,  char gender, int year) :
	name_(name), surname_(surname), gender_(gender), year_(year)
{
	cout << "Личность " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Personality::~Personality() {
	cout << "Личность " << name_ << " " << surname_ << " уволен" << endl << endl;
}

string Personality::getName()const {
	return name_;
}
string Personality::getSurname()const {
	return surname_;
}
int Personality::getYear()const {
	return year_;
}
char Personality::getGender()const {
	return gender_;
}

void Personality::setName(const string& name) {
	name_ = name;
}
void Personality::setSurname(const string& surname) {
	surname_ = surname;
}
void Personality::setYear(const int year) {
	year_ = year;
}
void Personality::setGender(const char gender) {
	gender_ = gender;
}

void Personality::deserialize() {

	const string path = name_ + surname_ + ".txt";
	string line;

	ifstream fin(path);
	if (fin.is_open()) {
		while (getline(fin, line))
		{
			cout << line << endl;
		}
	}
	fin.close();
}