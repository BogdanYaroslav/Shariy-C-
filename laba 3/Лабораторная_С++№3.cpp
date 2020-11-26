#include <iostream>
#include <fstream>
#include "windows.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Subtractor.h"
#include "Multiplier.h"
#include "Personality.h"
#include "Spectator.h"
#include "Musician.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Лабораторная работа №3, Богдан Ярослав Андреевич ИВТ-7, 1(Уск)курс\выберите номер задания или \'0\' для выхода: ";
	int num = 0;
	cin >> num;
	system("cls");
	while (num != 0) {
		switch (num)
		{
		case 1:
			void Task_1();
			Task_1();
			break;
		case 2: void Task_2();
			Task_2();
		}
		cout << "Нажмите кнопку для продолжения" << endl;
		system("pause");
		system("cls");
		cout << "Выберите номер задания (1-3) или \'0\' для выхода: ";
		cin >> num;
	}
	return 0;
}

void Task_1() {
	const int count = 3;
	ExpressionEvaluator* evaluator[count];

	const int subtractor_len = 2;
	evaluator[0] = new Subtractor(subtractor_len);
	evaluator[0]->SetOperand(0, 23.65);
	evaluator[0]->SetOperand(1, -12.15);

	const int custom_expression_len = 5;
	evaluator[1] = new CustomExpressionEvaluator(custom_expression_len);
	double custom_expression_arr[custom_expression_len] = { 2.5,-5,-3,2,10 };
	evaluator[1]->SetOperands(custom_expression_arr, custom_expression_len);

	const int multiplier_len = 4;
	evaluator[2] = new Multiplier(multiplier_len);
	evaluator[2]->SetOperand(0, 2.5);
	evaluator[2]->SetOperand(1, -3);
	evaluator[2]->SetOperand(2, 4);
	evaluator[2]->SetOperand(3, -1);

	for (int i = 0; i < 3; i++) {
		evaluator[i]->LogToScreen();
		evaluator[i]->LogToFile("Log_Lab3");
		cout << "< Result: " << evaluator[i]->calculate() << " >" << endl << endl;

	}
	for (int i = 0; i < 3; i++) {
		IShuffle* shuffle = dynamic_cast<IShuffle*>(evaluator[i]);
		if (shuffle) {
			shuffle->shuffle();
			evaluator[i]->LogToScreen();
			cout << "< Equals to: " << evaluator[i]->calculate() << " >" << endl << endl;
		}
	}

	for (int i = 0; i < 3; i++) {
		delete evaluator[i];
	}
}

void Task_2() {
	
	ofstream fout("Places.txt");
	if (fout.is_open()) {
		const int row = 2;
		const int location = 3;
		
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= location; j++) {
				fout << "Ряд " << i << " Место " << j << endl;
			}

		}
	}

	const int len = 4;
	Personality* personaly[len];

	personaly[0] = new Musician("Ivan", "Ivanov", 'm', 2000, Tools::Keyboards, 0, 0);
	personaly[1] = new Spectator("Sergey", "Sethey", 'm', 2000);
	personaly[2] = new Spectator("Vlad", "Vladov", 'f', 2000);
	personaly[3] = new Spectator("Nikita", "Nikitenko", 'f', 2000);

	for (int i = 0; i < len; i++) {
		personaly[i]->serialize();
		personaly[i]->visit();
		
		Musician* mus = dynamic_cast<Musician*>(personaly[i]);
		if (mus) {
			mus->Imitation();
		}
		personaly[i]->Print();

	}


	for (int i = 0; i < len; i++) {
		delete personaly[i];
	}

}