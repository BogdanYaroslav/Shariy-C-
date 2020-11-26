#pragma once
#include "Personality.h"

class Spectator: public Personality
{
private:
	string place_;

public:
	Spectator();
	Spectator(const string& name, const string& surname, char gender, int year);
	virtual ~Spectator();

	void setPlace(const string& place);
	string getPlace()const;

	void serialize()const override;


	
	void Print()override;

	void visit()override;


};

