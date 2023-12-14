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
		cout << "	������� ����\n"
			<< "1) �������� �������������\n"
			<< "2) ��������� �� �����\n"
			<< "3) ������� �������������\n"
			<< "4) ����� ��������������\n"
			<< "5) ����� � �������\n"
			<< "6) ����� � ����\n"
			<< "7) ���������� ��������� � ��������\n"
			<< "0) <<< �����\n ";
		cin >> ans;
		switch (ans){
			case 1:{
				string key_insert;
				cout << "������� ������������� ��� �������: ";
				cin >> key_insert;
				while (p.search(key_insert, comparisons))
				{
					cout << "������������� ��� ���� � �������" << "\n������� ����� �������������: ";
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
					cout << "\n������������ �� �����" << "\033[31m" << " ���������\n" << "\033[0m" << endl;
					break;
				}
				while (getline(fin, key_insert_file))
				{
					if (p.search(key_insert_file, comparisons))
					{
						cout << "\n������������� " << " << " << "\033[34m" << key_insert_file << "\033[0m" << " >> " << " ��� ���� � �������" << "\n������� ��������...\n" << endl;
						continue;
					}
					p.insert(key_insert_file, collisions);
				}
				fin.close();
				cout << "\n������������ �� �����" << "\033[32m" << " ���������\n" << "\033[0m" << endl;
				break;
			}
			case 3:{
				string key_delete;
				cout << "������� ������������� ��� ��������: ";
				cin >> key_delete;
				p.remove(key_delete);
				break;
			}
			case 4:{
				string key_search;
				cout << "������� ������������� ��� ������: ";
				cin >> key_search;
				bool search_hash = p.search(key_search, comparisons);

				if (search_hash)
				{
					cout << "\n�������������� ������\n" << endl;
				}
				else
				{
					cout << "\n������������� �� ������\n" << endl;
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
					cout << "\n����� � ����" << "\033[31m" << " ��������\n" << "\033[0m" << endl;
				}
				p.print(fout);
				fout.close();
				cout << "\n����� � ����" << "\033[32m" <<  " ��������\n" << "\033[0m" << endl;
				break;
			}
			case 7:{
				cout << "\n���������� ��������: " << collisions << "\n���������� ���������: " << comparisons << "\n" << endl;
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