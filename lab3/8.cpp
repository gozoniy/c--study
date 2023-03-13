/*Вариант 8
Дан текстовый файл. Переписать из исходного файла 
в другой файл все строки не длиннее n символов.*/
#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <string.h>

int main(void){
    setlocale(LC_ALL,"Rus");
    ifstream is("text.txt");
    ofstream os("output.txt");
    if (!is.is_open()||!os.is_open()){
        cout<<"Ошибка открытия файла!"<<endl;
    }
    else{
        cout<<"Файл успешно открыт!"<<endl;
        int n,l;
        string str;
        cout<<"Введите длинну строки n:";
        cin>>n;
        while(getline(is, str)){
            l=str.length();
            if (l<n){
                os<<str<<endl;
            }
        }
        cout<<"как же ахуенно когда работает интелисенс."<<endl;
        is.close();
        os.close();
    }
}
