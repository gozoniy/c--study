#include <iostream>
#include <fstream>
#include "hashtab.h"

using namespace std;
int main(void){
	setlocale(LC_ALL, "Russian");
	size_t ans;
	bool f = true;
	size_t size;
	cout<<"Введите размер списка:\n";
	cin>>size;
	hashtab p(size);
	while (f){
		cout << "Главное меню\n"
			<< "1) Вставить элемент\n"
			<< "2) Вставить из файла\n"
			<< "3) Удалить ключ\n"
			<< "4) Найти ключ\n"
			<< "5) Вывод в консоль\n"
			<< "6) Вывод в файл\n"
			<< "0) <<< Выход\n";
		cin >> ans;
		switch (ans){
			case 1:{
				string key;
				cout << "Введите элемент: ";
				cin >> key;
				if(p.search(key)){
					cout << "Этот элемент уже находится в таблице.\n";
				}
				size_t collisions = p.insert(key);
				cout<<"Всего коллизий: "<< collisions<<"\n";
				break;
			}
			case 2:{
				p.clear();
				string key_insert_file;
				ifstream fin("input.txt");
				if (!fin){
					cout << "Ошибка открытия файла.\n";
				}
				else{
					while (getline(fin, key_insert_file)){
						if (!p.search(key_insert_file)){
							p.insert(key_insert_file);
						}
					}
					fin.close();
					cout << "Чтение завершено.\n";
				}
				break;
			}
			case 3:{
				string key_delete;
				cout << "Введите элемент: ";
				cin >> key_delete;
				p.remove(key_delete);
				break;
			}
			case 4:{
				string key;
				cout << "Введите ключ: ";
				cin >> key;
				size_t comparisons = p.search(key);
				if (comparisons){
					cout << "Элемент найден.\n"
					<<"Всего сравнений: "<<comparisons<<"\n";
					}
				else{cout << "элемент НЕ найден.\n";}
				break;
			}
			case 5:{
				cout << p;
				break;
			}
			case 6:{
				ofstream fout("output.txt");
				if (!fout){
					cout << "Ошибка открытия файла.\n";
				}
				else{
					p.print(fout);
					fout.close();
					cout << "Запись завершена.\n";
				}
				break;
			}
			case 0:{
				f = false;
				break;
			}
		}
	}
	p.~hashtab();
};