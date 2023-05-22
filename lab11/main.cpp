#include <iostream>
using namespace std;
#include "matr.cpp"



int main(void){
	system("chcp 1251");

	const int N = 2;
	Matr A(N,N), B(N,N);
	cin>>A>>B;
	if (A==B){
		cout<<"Yes"<<endl;
	}
	
	if (A*B==B*A)		//Является ли умножение матрицы перестановочным 
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	
}
