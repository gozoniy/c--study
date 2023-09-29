#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "array.h"
template<typename T>
array<T>::array(){
    size = 10;
    arr = new T[size];

}
template<typename T>
array<T>::array(int n){
    size = n;
    arr = new T[size];
}
template<typename T>
array<T>::array(const array &A){
    size = A.size;
    arr = new T[size];
    for (int i = 0; i < size; i++){
        arr[i] = A.arr[i];
    }
}

template<typename T>
void array<T>::fill(){
    for (int i = 0; i < size; i++){
        cout<<"Введите элемент №"<<i+1<<": \n";
        cin>>arr[i];
    }
}
template<typename T>
void array<T>::setS(int S){
    size = S;
}

template<typename T>
void array<T>::get(){
    cout<<"Массив длинной "<<size<<":\n";
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

template<typename T>
void array<T>::fillR(int n1, int n2){
    srand(time(0));
    for (int i = 0; i < size; i++){
        arr[i] = n1 + rand()%(n2-n1+1);
    }
}
//Упорядоченные
template<typename T>
void array<T>::fillU(){
    for (int i = 0; i < size; i++){
        arr[i] = i+1;
    }
}
//Упорядоченные в обратном порядке
template<typename T>
void array<T>::fillUr(){
    for (int i = 0; i < size; i++){
        arr[i] = size-i;
    }
}

template<typename T>
void array<T>::get_file(ofstream &fin){
    for (int i = 0; i < size; i++){
        fin<<arr[i]<<" ";
    }
    fin<<"\n";
}

template<class T>
void array<T>::shakerSort() {
  long j, k = size-1;
  long lb=1, ub = size-1; // границы неотсортированной части массива
  T x;
  do {
	// проход снизу вверх 
    for( j=ub; j>0; j-- ) {
      if ( arr[j-1] > arr[j] ) {
        x=arr[j-1]; arr[j-1]=arr[j]; arr[j]=x;
        k=j;
      }
    }

    lb = k+1;

    // проход сверху вниз 
    for (j=1; j<=ub; j++) {
      if ( arr[j-1] > arr[j] ) {
        x=arr[j-1]; arr[j-1]=arr[j]; arr[j]=x;
        k=j;
      }
    }

    ub = k-1;
  } while ( lb < ub );
}

template<class T>
void array<T>::insertSort() {
  T x;
  long i, j;

  for ( i=0; i < size; i++) {  // цикл проходов, i - номер прохода
    x = arr[i];
		
	// поиск места элемента в готовой последовательности 
    for ( j=i-1; j>=0 && arr[j] > x; j--)
      arr[j+1] = arr[j];  	// сдвигаем элемент направо, пока не дошли

	// место найдено, вставить элемент
    arr[j+1] = x;
  }
}
