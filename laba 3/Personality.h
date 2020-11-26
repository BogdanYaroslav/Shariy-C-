#pragma once
#include "IVisitor.h"
#include <string>
using namespace std;
class Personality: public IVisitor
{
protected:
	string name_;
	string surname_;
	char gender_;
	int year_;

public:

	Personality();
	Personality(const string& name, const string& surname, char gender, int year);
	virtual ~Personality();

	string getName()const;
	string getSurname()const;
	char getGender()const;
	int getYear()const;

	void setName(const string& name);
	void setSurname(const string& surname);
	void setGender(const char gender);
	void setYear(const int year);

	virtual void serialize()const=0;
	void deserialize();



	virtual void Print()=0;

};

