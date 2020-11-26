#include "Musician.h"
#include <iostream>
#include <fstream>


Musician::Musician() : Personality(), tool_(Tools::Strings), rating_(0), experience_(0)
{
	cout << "�������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Musician::Musician(const string& name, const string& surname, char gender, int year, const Tools& tool, int rating, int experience) :
	Personality(name,surname,gender,year),tool_(tool), rating_(rating), experience_(experience)
{
	cout << "�������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Musician::~Musician() {
	cout << "�������� " << name_ << " " << surname_ << " ������" << endl << endl;
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

		fout << "��� ���������: " << name_ << endl;
		fout << "������� ���������: " << surname_ << endl;
		fout << "��� �������� ���������: " << year_ << endl;
		fout << "��� ���������: " << gender_ << endl;
		fout << "���������� ��������� ���������: " << experience_ << endl;
		fout << "������� ���������: " << rating_ << endl;
		switch (tool_)
		{
		case 1:
			fout << "��� �����������: ��������" << endl;
			break;
		case 2:
			fout << "��� �����������: �������" << endl;
			break;
		case 3:
			fout << "��� �����������: �������" << endl;
			break;
		case 4:
			fout << "��� �����������: ���������" << endl;
			break;
		}
	}
	fout.close();
}



void Musician::Imitation() {

	for (int i = 0; i < 3; i++) {

		cout << "������� � " << i + 1 << "��������� " << name_ << endl;

		rating_ += rand() % 5 + 1;
		cout << "������� ��������� " << name_ << " " << surname_ << " : " << rating_ << endl << endl;

	}
	cout << "----------------------------------------------------------------------------" << endl;
}

void Musician::visit() {
	experience_++;
	rating_ += rand() % 5 + 1;
	cout << "������� ��������� " << name_ << " " << surname_ << " : " << rating_ << endl << endl;
}

void Musician::Print() {

	cout << "��� ���������: " << name_ << endl;
	cout << "������� ���������: " << surname_ << endl;
	cout << "��� �������� ���������: " << year_ << endl;
	cout << "��� ���������: " << gender_ << endl;
	cout << "���������� ��������� ���������: " << experience_ << endl;
	cout << "������� ���������: " << rating_ << endl;
	cout << "��� �����������: " << tool_ << endl<<endl;
}