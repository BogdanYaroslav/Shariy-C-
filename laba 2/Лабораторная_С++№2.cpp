#include <iostream>
#include <windows.h>
#include "Musician.h"
#include "Fraction.h"
#include "Matrix.h"
#include "Vector.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Лабораторня Работа №2, Выполнил студент 1 курса, ИВТ-7(уск), Богдан Ярослав" << endl;
	cout << "Введите номер задания или \'0\' для выхода" << endl;

	int select = 0;
	cin >> select;

	while (select != 0) {

		switch (select)
		{
		case 1:
			void Task_1();
			Task_1();
			break;
		case 2:
			void Task_2();
			Task_2();
			break;
		case 3:
			void Task_3();
			Task_3();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
		cout << "Выберите номер задания или \'0\' для выхода: " << endl;
		cin >> select;
	}

	//system("pause");
	return 0;
}

void Task_1() {
	system("cls");

	Matrix* mat = new Matrix(4, 4);
	mat->PrintArray();
	//(*mat)++;
	//mat->PrintArray();
	//++(*mat);
	//mat->PrintArray();
	//--(*mat);
	//mat->PrintArray();
	//(*mat)--
	//mat->PrintArray();

	Vector* vec = new Vector(mat->getArray(), mat->getRows(), mat->getCols());
	vec->PrintArray();
	//(*vec)++;
	//vec->PrintArray();
	//++(*vec);
	//vec->PrintArray();
	//--(*vec);
	//vec->PrintArray();
	//(*vex)--;
	//vec->PrintArray();

	delete mat;
	delete vec;
}

void Task_2() {
	system("cls");
	Fraction num1(1, 2);
	Fraction num2(2, 6);

	Fraction res1 = num1 + num2;
	Fraction res2 = num1 - num2;
	Fraction res3 = num1 * num2;
	Fraction res4 = num1 / num2;

	Fraction::printAsFraction(0.25);
	Fraction::printAsFraction(0.43);

	char str[] = "0.43";
	Fraction::printAsFraction(str);
	char str2[] = "0.25";
	Fraction::printAsFraction(str2);

	

	cout << endl << Fraction::counter << endl;
}

void Task_3() {

	Musician mus1;
	mus1.setName("Yaroslav");
	mus1.setSurname("Bogdan");
	mus1.setYear(2001);
	mus1.setTool(Tools::Strings);
	
	Musician mus2;
	mus2.setName("Sergey");
	mus2.setSurname("Sergeev");
	mus2.setYear(2001);
	mus2.setTool(Tools::Wind);

	Musician mus3;
	mus3.setName("Nikita");
	mus3.setSurname("Nikitin");
	mus3.setYear(2001);
	mus3.setTool(Tools::Percussion);

	Musician* mus4 = new Musician("Ivan", "Ivanov", Tools::Keyboards, 2001);

	const int len = 4;
	Musician arr[len] = { mus1,mus2,mus3,*mus4 };

	for (int i = 0; i < len; i++) {

		arr[i].Imitation();
	}

	arr->Sort(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		
			arr[i].Print();
		
	}
	

	delete mus4;
}











