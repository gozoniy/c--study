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
	cout << "�������� ��� ������:\n"
		<< "1) ��������� ������\n"
		<< "2) AVL - ������\n";
	int tr;
	cin >> tr;
	if (tr == 1) {
		//��������� ������
		while (fl) {
			cout << "������� ����\n"
				<< "1) ���� � �������\n"
				<< "2) ���� �� �����\n"
				<< "3) ����� � �������\n"
				<< "4) ����� � ����\n"
				<< "5) ����������\n"
				<< "6) ��������\n"
				<< "7) �����\n"
				<< "8) ���������\n"
				<< "9) ������� ����� ������� �����\n"
				<< "0) <<< �����\n";
			cin >> ans;
			switch (ans){
				//���� �� �������
				case 1:{
					if (p.GetHead() != nullptr)
						p.~Tree();
					int size;
					cout << "������� ������� ������ (������ ������� ��������� ������):\n";
					cin >> p;
					break;
				}
				//���� �� �����
				case 2:{
					string filename;
					if (p.GetHead() != nullptr)
						p.~Tree();
					cout << "������� �������� ����� ����� (������ ��������� ������ ���� ������):";
					cin >> filename;
					p.scan_file(filename);
					break;
				}
				//����� � �������
				case 3:{
					cout << "\n" << p << "\n" << endl;
					break;
				}
				//����� � ����
				case 4:{
					int ans2;
					cout << "�������� ������� ������ � ����: " << endl
						<< "1) ������ ����� � ����" << endl
						<< "2) �������� ����� � ����" << endl
						<< "3) �������� ����� � ����" << endl;
					cin >> ans2;
					string filename;
					cout << "������� �������� ����� ������: ";
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
				//���������� ����
				case 5:{
					int value;
					cin >> value;
					p.add(value);
					break;
				}
				//�������� ����
				case 6:{
					int value;
					cin >> value;
					p.RemoveNode(value);
					break;
				}
				//����� ����
				case 7:{
					int value;
					cin >> value;
					if (p.search(value))
						cout << "\n������� ������.\n" << endl;
					else
						cout << "\n������� �� ������.\n" << endl;
					break;
				}
				//��������� ��������
				case 8:{
					int inp;
					cout<<"��������� �������� ������������? 0 / 1\n";
					cin>>inp;
					if (inp){
						Tree<int> p1 = p;
						if (p1 == p)
							cout<<"�������� �����������\n";
						else
							cout<<"������.\n";
					}
					bool check = false;
					cout<<"��������� ������ ������ ���������:\n";
					cin >> p1;
					if (p == p1){
						cout << "����������\n";
						check = true;
					}
					else{
						cout << "���������\n";
					}
					cout << endl;
					break;
				}
				//������� �������������� ����� ������� �����
				case 9: {
					p.Lenght(cout);
					break;
				}
				//�����
				case 0: {
					fl = false;
					break;
				}
			}
		}
	}
	else {
		//AVL - ������
		while (fl) {
			cout <<"������� ����\n"
				<< "1) ���� � �������\n"
				<< "2) ����� � �������\n"
				<< "3) ����������\n"
				<< "0) <<< �����\n";
			cin >> ans;

			switch (ans) {
				//���������� � �������
				case 1: {
					int size;
					int value;
					cout << "������� ���-�� �����: ";
					cin >> size;
					for (int i = 0; i < size; i++)
					{
						cout << "������� �������� ����: ";
						cin >> value;
						p3.Add(value);
					}
					break;
				}
				//����� � �������
				case 2: {
					p3.PrintTree();
					cout << endl;
					break;
				}
				//���������� ���� � ������ � �������������
				case 3: {
					int value;
					cout << "������� �������, ������� ������ �������� � ������: ";
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