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
        cout<<"Введите элемент №"<<i+1<<": \n";
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
    cout<<"Массив длинной "<<size<<":\n";
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
//Упорядоченные
template<typename T>
void arr<T>::fillU(){
    for (int i = 0; i < size; i++){
        a[i] = i+1;
    }
}
//Упорядоченные в обратном порядке
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
void arr<T>::mergeSort(){
    int n1 = size/2;
    arr<T> B(n1);
    arr<T> C(size - n1);
    int I = 0;
    for (int i = 0; i<n1; i++){
        B.a[i] = a[i*2+1];
    }
    I = 0;
    for (int i = 0; i<(size - n1); i++){
        C.a[i] = a[i*2];
    }
    int o, p;
    o = p = 0;
    for (int i = 0; i < size; i++){
        
        if (B.a[o]<C.a[p]){
            a[i] = B.a[o];
            o++;
        }
        else{
            a[i] = C.a[p];
            p++;
        }
    }
}

template<class T>
void arr<T>::polyphaseMergeSort() {
  T x;
  long i, j;
  int rmv = 0, cmp = 0;
  for ( i=0; i < size; i++) {  // цикл проходов, i - номер прохода
    x = a[i];
    // поиск места элемента в готовой последовательности 
    for ( j=i-1; j>=0 && a[j] > x; j--){
        cmp++;
        a[j+1] = a[j];  	// сдвигаем элемент направо, пока не дошли
        rmv++;
    }
    // место найдено, вставить элемент
    a[j+1] = x;
    }
    cout<<rmv<<" перестановок.\n";
    cout<<cmp<<" сравнений.\n";
}
