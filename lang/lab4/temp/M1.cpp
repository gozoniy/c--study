#include <vector>
#include <fstream>
#include <iostream>
#include "Header.h"

using namespace std;

void main()
{
	system("chcp 1251");
	int ans;
	Vector p;
	do{
		cout << "�������� ����� ����: " << endl
			<< "1) ������ �� �����" << endl
			<< "2) ����� � ����" << endl
			<< "3) ����������� ���. � ����. �� ����� ��������" << endl
			<< "4) ����� �� ���������" << endl;
		cin >> ans;
		switch (ans){
			case 1:{
				string path;
				cout << "������� �������� �����: " << endl;
				cin >> path;
				ifstream fin(path + ".txt");
				p.scan(fin);
				fin.close();
				break;
			}
			case 2:{
				string path;
				cout << "������� �������� �����: " << endl;
				cin >> path;
				ofstream fout(path + ".txt");
				p.print(fout);
				fout.close();
				break;
			}
			case 3:{
				std::pair<double, double> max_min = p.computeMinMaxLen();
				cout << "����������� ������: " << max_min.first << "������������ ������: " << max_min.second << endl;
				break;
			}
			case 4:{
				break;
			}
		}
	} while (ans != 4);
}