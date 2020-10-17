#include "Vector.h"
#include <iostream>
#include <iomanip>
using namespace std;

Vector::Vector(const int len) {

	length_ = len;
	arr1D = new double[len];

	for (int i = 0; i < len; i++) {
		arr1D[i] = i + 1;
	}
}

Vector::Vector(double** mat, int rows, int cols) {

	arr1D = new double[rows * cols];

	int k = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = cols-1; j >=0 ; j--) {

			arr1D[k] = mat[i][j];
			cout << arr1D[k] << " ";
			k++; 
		}
	}
}

double& Vector::operator[](int index) {
	return arr1D[index];
}



void Vector::PrintArray() {
	for (int i = 0; i < length_; i++)
	{
		cout<<setiosflags(ios::fixed)<<setprecision(4) << arr1D[i] << " ";
	}
}

Vector& Vector::operator++()
{
	for (int i = 0; i < length_; i++)
	{
		++arr1D[i];
	}
	return *this;
}

Vector& Vector::operator--() {
	for (int i = 0; i < length_; i++) {
		--arr1D[i];
	}
	return *this;
}

Vector Vector::operator++(int) {
	Vector tmp(*this);
	++(*this);
	return tmp;
}

Vector Vector::operator--(int) {
	Vector tmp(*this);
	--(*this);
	return tmp;
}

Vector::~Vector() {
	delete[] arr1D;
}

