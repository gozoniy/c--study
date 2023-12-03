#include <iostream>
#include <fstream>
#include "header.h"
#include<string>

int main()
{
	setlocale(LC_ALL, "Russian");
	Tree<string> p;
	Tree<string> p1;
	BalancedTree<int> p3;
	int ans;
	do
	{
		cout << " - Ввести дерево с клавиатуры" << endl
			<< " - Считать дерево из файла" << endl
			<< " - Вывод дерева в консоль" << endl
			<< " - Вывод дерева в файл" << endl
			<< " - Добавить узел" << endl
			<< " - Удалить узел" << endl
			<< " - Поиск узла с заданным значнием ключа" << endl
			<< " - Искомое задание" << endl
			<< " - Сравнение двух деревьев" << endl
			<< " - Сбалансированное бинарное дерево" << endl
			<< " - Добавить элемент в сбалансированное дерево" << endl
			<< " - Вывести сбалансированное дерево на экран" << endl
			<< " - Выход из программы" << endl;
		cin >> ans;

		switch (ans)
		{
		case 1:
		{
			if (p.GetHead() != nullptr)
				p.~Tree();

			int size;
			string value;

			cout << "Введите искомое дерево (первый элемент считается корнем): ";
			/*перегрузка потока ввода*/
			cin >> p;
			break;
		}
		case 2:
		{
			if (p.GetHead() != nullptr)
				p.~Tree();

			p.scan_file("derevo_ordered_scan.txt");
			break;
		}
		case 3:
		{
			/*перегрузка потока вывода*/
			cout << "\n" << p << "\n" << endl;
			break;
		}
		case 4:
		{
			int ans2;
			cout << "Выберите вариант вывода в файл: " << endl
				/*ordered_print - единственный вариант вывода, при котором правильно
				сканируется из этого же файла, так как при выводе корень дерева идет первый, а
				метод scan берет первый элемент за корень*/
				<< ordered_print << " - Прямой вывод в файл" << endl
				<< unordered_print << " - Обратный вывод в файл" << endl
				<< koncevoe_print << " - Концевой вывод в файл" << endl;
			cin >> ans2;

			switch (ans2)
			{
			case ordered_print:
			{
				ofstream fout("derevo_ordered_scan.txt");
				p.print_ordered(fout);
				fout.close();
				break;
			}
			case unordered_print:
			{
				ofstream fout("derevo_unordered.txt");
				p.print_unordered(fout);
				fout.close();
				break;
			}
			case koncevoe_print:
			{
				ofstream fout("derevo_koncevoe.txt");
				p.print_koncevoe(fout);
				fout.close();
				break;
			}
			}
			break;
		}
		case 5:
		{
			string value;
			cout << "Введите ключ для добавления узла: ";
			cin >> value;
			p.add(value);
			break;
		}
		case 6:
		{
			string value;
			cout << "Введите ключ для удаления узла: ";
			cin >> value;
			p.RemoveNode(value);
			break;
		}
		case 7:
		{
			string value;
			cout << "Введите ключ для поиска узла: ";
			cin >> value;
			if (p.search(value))
				cout << "\nЭлемент найден и находится в дереве.\n" << endl;
			else
				cout << "\nЭлемент не находится в дереве.\n" << endl;
			break;
		}
		case 8:
		{
			int length;
			cout << "Введите число для задания: " << endl;
			cin >> length;
			p.keyLengthRemove(length);
			break;
		}
		case 9:
		{
			bool check = false;
			/*показываем с помощью перегрузки операции "==",
			что при присвоении одного дерева другому(p = p1)
			деревья получаются одинаковые*/
			p = p1;
			cout << "\nСравнение деревьев p и p1: ";
			if (p == p1)
			{
				cout << "Деревья одинаковые" << endl;
				check = true;
			}
			else
			{
				cout << "Деревья различные" << endl;
			}
			cout << endl;


			/*создаем дерево p3 отличное от p, чтобы показать,
			что перегрузка "==" работает верно*/
			Tree<string> p3;
			cin >> p3;

			cout << "\nСравнение деревьев p и p3: ";
			if (p1 == p3)
			{
				cout << "Деревья одинаковые" << endl;
				check = true;
			}
			else
			{
				cout << "Деревья различные" << endl;
			}
			cout << endl;
			break;
		}
		case 10:
		{
			int size;
			int value;
			cout << "Введите количество узлов в дереве: " << endl;
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout << "Введите значение узла: ";
				cin >> value;
				p3.Add(value);
			}
			break;
		}
		case 11:
		{
			int value;
			cout << "Введите элемент, который хотите добавить в дерево: ";
			cin >> value;
			p3.Add(value);
			break;
		}
		case 12:
		{
			cout << "Дерево, выведенное обратным обходом (лево-корень-право)" << endl;
			p3.PrintTree();
			cout << endl;
			break;
		}
		}
	} while (ans != 0);
	return 0;
}