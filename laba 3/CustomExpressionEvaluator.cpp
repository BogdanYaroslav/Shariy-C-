//¬ид выражени€ CustomExpression : result = (x1 + x2) * x3 * x4 * ...
//ѕор€док создани€ и инициализации объектов подклассов :
//Subtractor: 2 операнда, присвоить поэлементно 23.65, -12.15.
//CustomExpressionEvaluator : 5 операндов, присвоить группой 2.5, -5, -3, 2, 10.
//Multiplier : 4 операнда, присвоить поэлементно 2.5, -3, 4, -1.
//ћетод shuffle() Ц помен€ть местами первый и последний операнды, имеющие
//дробную часть.ћетод shuffle(size_t i, size_t j) Ц если хот€ бы один из i - ого и jого операндов имеет дробную часть, помен€ть их местами, иначе Ц не мен€ть.
//‘ормат вывода :
//Total: 4
//(2.5 + (-5)) * (-3) * 2 * 10
//Equals to 150






#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>

CustomExpressionEvaluator::CustomExpressionEvaluator() :ExpressionEvaluator()
{
	cout << "ќбъект класса CustomExpressionEvaluator создан" << endl;
}

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n){
	cout << "ќбъект класса CustomExpressionEvaluator создан" << endl;
}


CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
	cout << "ќбъект класса CustomExpressionEvaluator удален" << endl;
}

double CustomExpressionEvaluator::calculate()
{
	double result = (operands_[0] + operands_[1]);
	for (size_t i = 2; i < count_operand_; i++)
	{
		result *= operands_[i];
	}
	return result;
}

void CustomExpressionEvaluator::LogToScreen()
{
	
	cout << "Total:" << count_operand_ << endl;
	cout << "(" << CheckSign(operands_[0]) << " + " <<CheckSign(operands_[1])<<")"<<" * ";

	for (size_t i = 2; i < count_operand_ - 1; i++)
	{
		cout << CheckSign(operands_[i]) << " * ";;
	}
	cout << CheckSign(operands_[count_operand_ - 1]) << endl;	
}

void CustomExpressionEvaluator::LogToFile(const string& filename)
{
	fstream out(filename+".txt", ios_base::app | ios_base::out);
	if (out.is_open())
	{
		
		out << "Total:" << count_operand_ << endl;
		out << "("<< CheckSign(operands_[0]) << " + " << CheckSign(operands_[1])<<")"<<" * ";	

		for (size_t i = 2; i < count_operand_ - 1; i++)
		{
			out << CheckSign(operands_[i])<<" * ";
			
		}
		out << CheckSign(operands_[count_operand_ - 1]) << endl;
	}
	out.close();
}

void CustomExpressionEvaluator::shuffle() {

	int first = 0;
	int last = 0;

	for (int i = 0; i < count_operand_; i++) {

		if ((int)operands_[i] != operands_[i]) {
			first = i;
		}
	}
	for (int i = count_operand_ - 1; i >= 0; i--) {
		if ((int)operands_[i] != operands_[i]) {
			last = i;
		}
	}
	if (operands_[first] != operands_[last]) {
		double tmp = operands_[first];
		operands_[first] = operands_[last];
		operands_[last] = tmp;
	}
}


void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {

	if (i < count_operand_ && j < count_operand_) {
		if ((int)operands_[i] != operands_[i] || (int)operands_[j] != operands_[j]) {

			double tmp = operands_[i];
			operands_[i] = operands_[j];
			operands_[j] = tmp;
		}
	}
}