#pragma once
class Matrix
{
private:
	int rows_;
	int cols_;
	double** arr2D;


public:

	Matrix(int rows, int cols);

	double getAt(int row, int col)const;
	void setAt(int row, int col, double val);

	void PrintArray();

	int getRows()const;
	int getCols()const;
	double** getArray()const;

	Matrix& operator++();
	Matrix  operator++(int);
	Matrix& operator--();
	Matrix  operator--(int);

	~Matrix();
};

