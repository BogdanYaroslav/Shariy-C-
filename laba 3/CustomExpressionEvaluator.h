#pragma once
#include"ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator:public ExpressionEvaluator, public IShuffle
{
public:
	CustomExpressionEvaluator();
	CustomExpressionEvaluator(int n);
	~CustomExpressionEvaluator();

	double calculate() override;

	void LogToScreen() override;
	void LogToFile(const string& filename) override;
	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
	
};

