#pragma once
#include <string>
#include "Tools.h"
using namespace std;
class Musician
{
private:

	string name_;
	string surname_;
	int year_;
	Tools tool_;
	int rating_;

public:

	Musician();
	Musician(const string& name, const string& surname, const Tools tool, int year);

	string getName()const;
	string getSurname()const;
	Tools getTool()const;
	int getYear()const;
	int getRating()const;

	void setName(const string& name);
	void setSurname(const string& surname);
	void setTool(const Tools tool);
	void setYear(const int year);
	void setRating(const int rating);

	void serialize()const;
	void serialize(const string& filename)const;
	void deserialize();
	void deserialize(const string& filename);

	void Imitation();
	void Print();
	void Sort(Musician* arr, int len);



	~Musician();
};

