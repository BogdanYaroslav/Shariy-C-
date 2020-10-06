
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;


//Написать программу, которая преобразует одномерный массив(1D) в двумерный(2D)
//(или наоборот), в соответствии с вариантом.Необходимо оформить в отдельных
//функциях код следующих действий : 1) инициализация массива; 2) вывод массива; 3)
//преобразование массива(создание нового массива с другой структурой).Память под
//массивы выделять динамически и для доступа к элементам использовать указатели.
//Ввод - вывод данных организовать средствами iostream и iomanip

//Преобразование: 2D → 1D.Двумерный массив 4х4 вещественных чисел необходимо
//	выложить в один ряд по элементам слева направо и свверху вниз.
//	Инициализация : заполнить массив числами x[i][j] = √(i + j + 1).
//	Вывод на экран : каждый элемент одномерного массива вывести с точностью четыре
//	знака после запятой; каждый элемент двумерного массива – с точностью два знака.

void freeArray2D(double** arr2D, size_t rows) {
	for (size_t i = 0; i < rows; i++) {

		delete[] * (arr2D + i);
	}
	delete[] arr2D;
}
void freeArray1D(double* arr1D) {
	delete[]arr1D;
}

void IninitializeArray(double** arr2D, size_t rows, size_t cols) {



	for (size_t i = 0; i < rows; i++) {

		for (size_t j = 0; j < cols; j++) {

			*(*(arr2D + i) + j) = sqrt(i + j + 1);

			
		}
	}
}

void printArray2D(double** arr2D, size_t rows, size_t cols) {

	for (int i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {

			cout << setiosflags(ios::fixed) << setprecision(2) << *(*(arr2D + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printArray1D(double* arr1D, size_t len) {
	for (size_t i = 0; i < len; i++) {
		cout << setiosflags(ios::fixed) << setprecision(4) << *(arr1D + i) << " ";
	}
	cout << endl;
}

double* makeArray1D(double** arr2D, size_t rows, size_t cols) {

	double* arr1D = new double[rows * cols];

	for (int i = 0; i< rows; i++) {

		for (size_t j = 0; j < cols; j++) {

			arr1D[i*cols+j] = arr2D[i][j];
		}

	}
	return arr1D;
}



int main()
{
	const size_t ROWS = 4;
	const size_t COLS = 4;

	double** arr2D = new double* [ROWS];

	for (size_t i = 0; i < ROWS; i++) {

		*(arr2D + i) = new double[COLS];
	}

	IninitializeArray(arr2D, ROWS, COLS);

	printArray2D(arr2D, ROWS, COLS);

	double* arr1D = makeArray1D(arr2D, ROWS, COLS);

	printArray1D(arr1D, ROWS * COLS);

	freeArray2D(arr2D, ROWS);
	freeArray1D(arr1D);
}