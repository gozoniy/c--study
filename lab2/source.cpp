#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include <C:\Users\User\Desktop\prog\c\lab1\printM.h>

using namespace std;


int main(){
    setlocale(LC_ALL,"Rus");

    

    string path = "test.txt";
    ifstream fin;
    fin.open(path);

    if (!fin.is_open()){
        printf("Ошибка открытия файла!");
    }
    else{
        printf("Файл успешно открыт.\n");
        int X[20];
        
        char n;
        char nM[20];
        char *Num=nM;
        int l,N;
        int fl=0;
        int S[20];
        int fm=0;
        int ans=0;

        while (fin.get(n)){
            if (n=='\n'){
                N=atof(nM);
                S[fm]=N;
                fm++;
                printf("%i ",N);
                for (int i=0;i<20;i++){
                    nM[i]='\0';
                }
                fl=0;
                
            }
            else{
                nM[fl]=n;
                fl++;

            }
        }
        for (int i=0;i<fm;i++){
            ans=ans+S[i];
        }
        printf("\nСумма всех чисел в файле: %i",ans);
    }
    
    fin.close();
    return 0;
}