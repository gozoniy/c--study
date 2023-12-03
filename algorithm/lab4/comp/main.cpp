#include <iostream>
#include <fstream>
#include "header.h"
#include <string>

int main(){
	setlocale(LC_ALL, "Russian");
	Tree<int> p;
	Tree<int> p1;
	BalancedTree<int> p3;
	int ans;
	bool fl = true;
	cout << "Выберите тип дерева:\n"
		<< "1) Поисковое дерево\n"
		<< "2) AVL - дерево\n";
	int tr;
	cin >> tr;
	if (tr == 1) {
		//Поисковое дерево
		while (fl) {
			cout << "Главное меню\n"
				<< "1) Ввод с консоли\n"
				<< "2) Ввод из файла\n"
				<< "3) Вывод в консоль\n"
				<< "4) Вывод в файл\n"
				<< "5) Добавление\n"
				<< "6) Удаление\n"
				<< "7) Поиск\n"
				<< "8) Сравнение\n"
				<< "9) Среднее самой длинной ветки\n"
				<< "0) <<< Выход\n";
			cin >> ans;
			switch (ans){
				//Ввод из консоли
				case 1:{
					if (p.GetHead() != nullptr)
						p.~Tree();
					int size;
					cout << "Введите искомое дерево (первый элемент считается корнем):\n";
					cin >> p;
					break;
				}
				//Ввод из файла
				case 2:{
					string filename;
					if (p.GetHead() != nullptr)
						p.~Tree();
					cout << "Введите название файла ввода (первым элементом должен быть корень):";
					cin >> filename;
					p.scan_file(filename);
					break;
				}
				//Вывод в консоль
				case 3:{
					cout << "\n" << p << "\n" << endl;
					break;
				}
				//Вывод в файл
				case 4:{
					int ans2;
					cout << "Выберите вариант вывода в файл: " << endl
						<< "1) Прямой вывод в файл" << endl
						<< "2) Обратный вывод в файл" << endl
						<< "3) Концевой вывод в файл" << endl;
					cin >> ans2;
					string filename;
					cout << "Введите название файла вывода: ";
					cin >> filename;
					switch (ans2){
						case 1:{
							ofstream fout(filename);
							p.print_ordered(fout);
							fout.close();
							break;
						}
						case 2:{
							ofstream fout(filename);
							p.print_unordered(fout);
							fout.close();
							break;
						}
						case 3:{
							ofstream fout(filename);
							p.print_koncevoe(fout);
							fout.close();
							break;
						}
					}
					break;
				}
				//Добавление узла
				case 5:{
					int value;
					cin >> value;
					p.add(value);
					break;
				}
				//Удаление узла
				case 6:{
					int value;
					cin >> value;
					p.RemoveNode(value);
					break;
				}
				//Поиск узла
				case 7:{
					int value;
					cin >> value;
					if (p.search(value))
						cout << "\nЭлемент найден.\n" << endl;
					else
						cout << "\nЭлемент НЕ найден.\n" << endl;
					break;
				}
				//Сравнение деревьев
				case 8:{
					int inp;
					cout<<"Проверить оператор присваивания? 0 / 1\n";
					cin>>inp;
					if (inp){
						Tree<int> p1 = p;
						if (p1 == p)
							cout<<"Успешное копирование\n";
						else
							cout<<"Ошибка.\n";
					}
					bool check = false;
					cout<<"Заполните второе дерево сравнения:\n";
					cin >> p1;
					if (p == p1){
						cout << "Одинаковые\n";
						check = true;
					}
					else{
						cout << "Различные\n";
					}
					cout << endl;
					break;
				}
				//Среднее арифметическое самой длинной ветки
				case 9: {
					p.Lenght(cout);
					break;
				}
				//Выход
				case 0: {
					fl = false;
					break;
				}
			}
		}
	}
	else {
		//AVL - дерево
		while (fl) {
			cout <<"Главное меню\n"
				<< "1) Ввод с консоли\n"
				<< "2) Вывод в консоль\n"
				<< "3) Добавление\n"
				<< "0) <<< Выход\n";
			cin >> ans;

			switch (ans) {
				//Заполнение с консоли
				case 1: {
					int size;
					int value;
					cout << "Введите кол-во узлов: ";
					cin >> size;
					for (int i = 0; i < size; i++)
					{
						cout << "Введите значение узла: ";
						cin >> value;
						p3.Add(value);
					}
					break;
				}
				//Вывод в консоль
				case 2: {
					p3.PrintTree();
					cout << endl;
					break;
				}
				//Добавление узла в дерево с балансировкой
				case 3: {
					int value;
					cout << "Введите элемент, который хотите добавить в дерево: ";
					cin >> value;
					p3.Add(value);
					break;
				}
				case 0: {
					fl = false;
					break;
				}
			}
		}
	}
	return 0;
}