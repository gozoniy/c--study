#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <string.h>

int main(void){
    setlocale(LC_ALL,"Rus");
    ifstream is("text.txt");
    if (!is.is_open()){
        cout<<"Ошибка открытия!"<<endl;
        return -1;
    }
    else{
        cout<<"Файл успешно открыт."<<endl;

        char str[20],ans[20];

        int max=0,l=0;
        while(is>>str){
            l=strlen(str);
            if (max<l){
                max=l;
                strcpy(ans,str);
            }
        
        }
        cout<<"Макс слово: "<<ans<<endl;


    }
}