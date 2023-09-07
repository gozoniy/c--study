#include <iostream>
using namespace std;
#include "matr.cpp"

int main(void){
	system("chcp 1251");

	Matr A, B(2,3);
	cin>>A;
	cout<<A;
	cout<<"Транспонированная A\n";
	cout<<A.tr();

	if (A*B==B*A)
		cout<<"Матрицы перестановочные\n";
	else
		cout<<"Не перестановочные\n";



	
}
