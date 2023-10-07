#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "arr.h"
template<typename T>
arr<T>::arr(){
    size = 10;
    a = new T[size];

}
template<typename T>
arr<T>::arr(int n){
    size = n;
    a = new T[size];
}
template<typename T>
arr<T>::arr(const arr &A){
    size = A.size;
    a = new T[size];
    for (int i = 0; i < size; i++){
        a[i] = A.a[i];
    }
}

template<typename T>
void arr<T>::fill(){
    for (int i = 0; i < size; i++){
        cout<<"������� ������� �"<<i+1<<": \n";
        cin>>a[i];
    }
}
template<typename T>
void arr<T>::setS(int S){
    size = S;
    a = new T[size];
}
template<typename T>
int arr<T>::getS(){
    return size;
}

template<typename T>
void arr<T>::get(){
    cout<<"������ ������� "<<size<<":\n";
    for (int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

template<typename T>
void arr<T>::fillR(int n1, int n2){
    srand(time(0));
    for (int i = 0; i < size; i++){
        a[i] = n1 + rand()%(n2-n1+1);
    }
}
//�������������
template<typename T>
void arr<T>::fillU(){
    for (int i = 0; i < size; i++){
        a[i] = i+1;
    }
}
//������������� � �������� �������
template<typename T>
void arr<T>::fillUr(){
    for (int i = 0; i < size; i++){
        a[i] = size-i;
    }
}

template<typename T>
void arr<T>::get_file(ofstream &fin){
    for (int i = 0; i < size; i++){
        fin<<a[i]<<" ";
    }
    fin<<"\n";
}

template<class T>
void arr<T>::shakerSort() {
  long j, k = size-1;
  long lb=1, ub = size-1; // ������� ����������������� ����� �������
  T x;
  int rmv = 0, cmp = 0;
  do {
	// ������ ����� ����� 
    for( j=ub; j>0; j-- ) {
        cmp++;
        if ( a[j-1] > a[j] ) {
            x=a[j-1]; a[j-1]=a[j]; a[j]=x;
            k=j;
            rmv++;
      }
    }
    lb = k+1;
    // ������ ������ ���� 
    for (j=1; j<=ub; j++) {
        cmp++;
        if ( a[j-1] > a[j] ) {
            x=a[j-1]; a[j-1]=a[j]; a[j]=x;
            k=j;
            rmv++;
        }
    }
    ub = k-1;
  } while ( lb < ub );
    cout<<rmv<<" ������������.\n";
    cout<<cmp<<" ���������.\n";

}

template<class T>
void arr<T>::insertSort() {
  T x;
  long i, j;
  int rmv = 0, cmp = 0;
  for ( i=0; i < size; i++) {  // ���� ��������, i - ����� �������
    x = a[i];
    // ����� ����� �������� � ������� ������������������ 
    for ( j=i-1; j>=0 && a[j] > x; j--){
        cmp++;
        a[j+1] = a[j];  	// �������� ������� �������, ���� �� �����
        rmv++;
    }
    // ����� �������, �������� �������
    a[j+1] = x;
    }
    cout<<rmv<<" ������������.\n";
    cout<<cmp<<" ���������.\n";
}
