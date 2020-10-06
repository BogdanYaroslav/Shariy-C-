 
#include <cmath>
#include <iostream>
using namespace std;
// �������� ������ �� n=10 ����� �����, ������������������� ������.������� processArray() ������ ���������
//������ ������� �������������� ���������� � ��������� ��������� b1 � ����� q, ���������� � ������� cnt- ���������� ����
//����������� ��������� �������, � ����� ������������ �������� ������ ������� �������� ��� �������� ���������, 
//����� ���, ������� ������� �� 3 � �������� 1.������� �� ����� �������.

void printArray(int* arr, size_t len) {

	for (size_t i = 0; i < len; i++) {
		if (arr[i] != 0)
			printf("%d ", arr[i]);
	}
	printf("\n");
}




int processArray(int* arr1, int* arr2, size_t len) {

	int b1, q;

	printf("Vvedite b1");
	scanf_s("%d", &b1);
	printf("Vvedite q ");
	scanf_s("%d", &q);

	arr1[0] = b1;
	size_t cnt = 0;
	size_t count = 0;
	for (size_t i = 1; i < len; i++) {

arr1[i] = arr1[i-1] * q;

		if (arr1[i] > 99 && arr1[i] < 1000) {
			cnt++;
		}

		if (arr1[i] % 3 != 1) {

			arr2[count] = arr1[i];
			count++;
		}
	}
	return cnt;
}
int main(int argc, char* argv[])
 {

	const size_t len = 10;

	int arr1[len] = { 0 };
	int arr2[len] = { 0 };

	int cnt = processArray(arr1, arr2, len);

	printArray(arr1, len);
	printArray(arr2, len);
	printf("\nKOLICHESTVO ELEMENTOV: %d", cnt);
	system("pause");
}