#include "Matrix.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

Matrix::Matrix(const int rows,const int cols):cols_(cols),rows_(rows) {

	arr2D = new double* [rows];
	for (int i = 0; i < rows; i++) {
		arr2D[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr2D[i][j] = sqrt(i + j + 1);
			//cout<<setiosflags(ios::fixed)<<setprecision(2) << arr2D[i][j] << " ";
		}
		//cout << endl;
	}
}

double Matrix::getAt(int row, int col)const {
	return arr2D[row][col];
}

void Matrix::setAt(int row, int col, double val) {
	if (row > 0 && row < rows_ && col>0 && col < cols_) {
		arr2D[row][col] = val;
	}
}

void Matrix::PrintArray() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			cout<<setiosflags(ios::fixed)<<setprecision(2) << arr2D[i][j] << " ";
		}
		cout << endl << endl;
	}
}

int Matrix::getRows()const {
	return rows_;
}
int Matrix::getCols()const {
	return cols_;
}

double** Matrix::getArray()const {
	return arr2D;
}

Matrix& Matrix::operator++() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			arr2D[i][j]++;
		}
	}
	return *this;
}

Matrix& Matrix::operator--() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			--arr2D[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix tmp(*this);
	++(*this);
	return tmp;
}

Matrix Matrix::operator--(int) {
	Matrix tmp(*this);
	--(*this);
	return tmp;
}

Matrix::~Matrix() {
	for (int i = 0; i < rows_; i++) {
		delete[] arr2D[i];
	}
	delete[] arr2D;
}