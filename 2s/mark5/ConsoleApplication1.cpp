//20    14
#include <iostream>
#include <string>
#include <cstring>
#include "bibl.h"
using namespace std;

int main(void)
{
	system("chcp 1251");
	int exit = 1, act, test = 1, test_arr = 1, N;
	Node* pEnd = 0, * pBegin = 0;
	while (exit != 0)
	{
		cout << "1 - Ввести данные первого ученика\n"
			 << "2 - Добавить данные следующего ученика\n"
			 << "3 - Вывести список данных учеников\n"
			 << "4 - Вывести список данных учеников в обратном порядке\n"
			 << "5 - Удалить данные списка\n"
			 << "6 - Вывести адреса элементов списка по ключевому полю\n"
			 << "0 - Завершить работу программы\n";
		cin >> act;
		switch (act)
		{
		case 0: {
			exit = 0;
			break;
		}
		case 1: {
			pBegin = pEnd = first();
			break;
		}
		case 2: {
			pEnd = add(pEnd);
			break;
		}
		case 3: {
			print(pBegin);
			break;
		}
		case 4: {
			print_back(pEnd);
			break;
		}
		case 5: {
			del(pBegin);
			break; }
		case 6: {
			search(pBegin);
			break; }
		default: {cout << "Введён несуществующий вариант действия.\n"; break; }
		}
	}
}