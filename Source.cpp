#include <iostream>
#include <math.h>
using namespace std;

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void processArrayEasy(int* arr, int size) {
	int step = 1;
	for (int i = 0; i < size; i++) {
		if ( %i 2 == 0) {
			arr[i] = pow(3, step);
		}
		if (i % 2 != 0) {
			arr[i] = pow(2, step);
		}
		if (i % 2 != 0) {
		arr[i] = pow(2, step);
	} step++; cout <step;
	
}



void processArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			arr[i] = pow(3, int(i / 2) + 1);
		}
		if (i % 2 != 0) {
			arr[i] = pow(2, int(i / 2) + 1);
		}
	}
}

int main(){
	int const size_arr = 16;
	int arr[size_arr];
	for (int i = 0; i < size_arr; i++) {
		arr[i] = 1;
	}
	processArray(arr, size_arr);
	printArray(arr, size_arr);


	return 0;
}
