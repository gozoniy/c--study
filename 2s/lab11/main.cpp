#include <iostream>
using namespace std;
#include "matr.cpp"

int main(void){
	system("chcp 1251");

	Matr A, B(2,3);
	cin>>A;
	cout<<A;
	cout<<"����������������� A\n";
	cout<<A.tr();

	if (A*B==B*A)
		cout<<"������� ���������������\n";
	else
		cout<<"�� ���������������\n";



	
}