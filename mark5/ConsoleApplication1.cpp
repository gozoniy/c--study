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
		cout << "1 - ������ ������ ������� �������\n"
			 << "2 - �������� ������ ���������� �������\n"
			 << "3 - ������� ������ ������ ��������\n"
			 << "4 - ������� ������ ������ �������� � �������� �������\n"
			 << "5 - ������� ������ ������\n"
			 << "6 - ������� ������ ��������� ������ �� ��������� ����\n"
			 << "0 - ��������� ������ ���������\n";
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
		default: {cout << "����� �������������� ������� ��������.\n"; break; }
		}
	}
}