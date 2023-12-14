#include <iostream>
#include <fstream>
#include "hashtab.h"

using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	hashtab p;
	size_t ans, collisions = 0, comparisons = 0;
	bool f = true;
	while (f){
		cout << "	Главное меню\n"
			<< "1) Вставить идентификатор\n"
			<< "2) Заполнить из файла\n"
			<< "3) Удалить идентификатор\n"
			<< "4) Поиск идентификатора\n"
			<< "5) Вывод в консоль\n"
			<< "6) Вывод в файл\n"
			<< "7) Количество сравнений и коллизий\n"
			<< "0) <<< Выход\n ";
		cin >> ans;
		switch (ans){
			case 1:{
				string key_insert;
				cout << "Введите идентификатор для вставки: ";
				cin >> key_insert;
				while (p.search(key_insert, comparisons))
				{
					cout << "Идентификатор уже есть в таблице" << "\nВведите новый идентификатор: ";
					cin >> key_insert;
				}
				p.insert(key_insert, collisions);
				break;
			}
			case 2:{
				p.clear();
				string key_insert_file;
				ifstream fin("input.txt");
				if (!fin)
				{
					cout << "\nСканирование из файла" << "\033[31m" << " провалено\n" << "\033[0m" << endl;
					break;
				}
				while (getline(fin, key_insert_file))
				{
					if (p.search(key_insert_file, comparisons))
					{
						cout << "\nИдентификатор " << " << " << "\033[34m" << key_insert_file << "\033[0m" << " >> " << " уже есть в таблице" << "\nПропуск итерации...\n" << endl;
						continue;
					}
					p.insert(key_insert_file, collisions);
				}
				fin.close();
				cout << "\nСканирование из файла" << "\033[32m" << " завершено\n" << "\033[0m" << endl;
				break;
			}
			case 3:{
				string key_delete;
				cout << "Введите идентификатор для удаления: ";
				cin >> key_delete;
				p.remove(key_delete);
				break;
			}
			case 4:{
				string key_search;
				cout << "Введите идентификатор для поиска: ";
				cin >> key_search;
				bool search_hash = p.search(key_search, comparisons);

				if (search_hash)
				{
					cout << "\nИндентификатор найден\n" << endl;
				}
				else
				{
					cout << "\nИдентификатор не найден\n" << endl;
				}
				break;
			}
			case 5:{
				cout << p;
				break;
			}
			case 6:{
				ofstream fout("output.txt");
				if (!fout){
					cout << "\nВывод в файл" << "\033[31m" << " провален\n" << "\033[0m" << endl;
				}
				p.print(fout);
				fout.close();
				cout << "\nВывод в файл" << "\033[32m" <<  " завершен\n" << "\033[0m" << endl;
				break;
			}
			case 7:{
				cout << "\nКоличество коллизий: " << collisions << "\nКоличество сравнений: " << comparisons << "\n" << endl;
				break;
			}
			case 0:{
				f = false;
				break;
			}
		}
	}
	p.~hashtab();
	return 0;
};