#include <iostream>
#include <fstream>
#include "hashtab.h"

using namespace std;
int main(void){
	setlocale(LC_ALL, "Russian");
	size_t ans;
	bool f = true;
	size_t size;
	cout<<"������� ������ ������:\n";
	cin>>size;
	hashtab p(size);
	while (f){
		cout << "������� ����\n"
			<< "1) �������� �������\n"
			<< "2) �������� �� �����\n"
			<< "3) ������� ����\n"
			<< "4) ����� ����\n"
			<< "5) ����� � �������\n"
			<< "6) ����� � ����\n"
			<< "0) <<< �����\n";
		cin >> ans;
		switch (ans){
			case 1:{
				string key;
				cout << "������� �������: ";
				cin >> key;
				if(p.search(key)){
					cout << "���� ������� ��� ��������� � �������.\n";
				}
				size_t collisions = p.insert(key);
				cout<<"����� ��������: "<< collisions<<"\n";
				break;
			}
			case 2:{
				p.clear();
				string key_insert_file;
				ifstream fin("input.txt");
				if (!fin){
					cout << "������ �������� �����.\n";
				}
				else{
					while (getline(fin, key_insert_file)){
						if (!p.search(key_insert_file)){
							p.insert(key_insert_file);
						}
					}
					fin.close();
					cout << "������ ���������.\n";
				}
				break;
			}
			case 3:{
				string key_delete;
				cout << "������� �������: ";
				cin >> key_delete;
				p.remove(key_delete);
				break;
			}
			case 4:{
				string key;
				cout << "������� ����: ";
				cin >> key;
				size_t comparisons = p.search(key);
				if (comparisons){
					cout << "������� ������.\n"
					<<"����� ���������: "<<comparisons<<"\n";
					}
				else{cout << "������� �� ������.\n";}
				break;
			}
			case 5:{
				cout << p;
				break;
			}
			case 6:{
				ofstream fout("output.txt");
				if (!fout){
					cout << "������ �������� �����.\n";
				}
				else{
					p.print(fout);
					fout.close();
					cout << "������ ���������.\n";
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