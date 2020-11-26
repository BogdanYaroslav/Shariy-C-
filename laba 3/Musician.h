#pragma once
#include "Personality.h"
#include "Tools.h"


class Musician: public Personality
{
private:
	Tools tool_;
	int rating_;
	int experience_;

public:

	Musician();
	Musician(const string& name, const string& surname,  char gender, int year, const Tools& tool, int rating, int experience);
	~Musician();

	void setTool(const Tools tool);
	void setRating(const int rating);

	Tools getTool()const;
	int getRating()const;

	void serialize()const override;
	

	void Imitation();
	void Print()override;

	void visit()override;

};

