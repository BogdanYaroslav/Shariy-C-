#pragma once
#include "Matrix.h"

//int arr[length];

class Vector
{
private:
	int length_;
	double* arr1D;
public:

	Vector(int len);
	Vector(double** mat,int rows,int cols);

	void PrintArray();



	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);

	double& operator[](int index);

	~Vector();
};

