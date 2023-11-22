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
		cout << "Выберите пункт меню: " << endl
			<< "1) Чтение из файла" << endl
			<< "2) Вывод в файл" << endl
			<< "3) Определение мин. и макс. по длине векторов" << endl
			<< "4) Выход из программы" << endl;
		cin >> ans;
		switch (ans){
			case 1:{
				string path;
				cout << "Введите название файла: " << endl;
				cin >> path;
				ifstream fin(path + ".txt");
				p.scan(fin);
				fin.close();
				break;
			}
			case 2:{
				string path;
				cout << "Введите название файла: " << endl;
				cin >> path;
				ofstream fout(path + ".txt");
				p.print(fout);
				fout.close();
				break;
			}
			case 3:{
				std::pair<double, double> max_min = p.computeMinMaxLen();
				cout << "Минимальный вектор: " << max_min.first << "Максимальный вектор: " << max_min.second << endl;
				break;
			}
			case 4:{
				break;
			}
		}
	} while (ans != 4);
}