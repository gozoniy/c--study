//21. сортировка прямыми обменами; сортировка прямыми включениями. 
#include <iostream>
using namespace std;
#include "array.cpp"

int main(void){
    system("chcp 1251");
    int f = 1;
    int in;
    while (f){
        cout<<"1) Cортировка одного массива, сформированного случайным образом\n";
        cout<<"2) Режим накопления статистических данных\n";
        cout<<"0) Выход \n";
        cin>>in;;
        switch (in){
            case 1:{
                int n;
                cout<<"Задайте размер массива: ";
                cin>>n;
                array<int> A(n);
                cout<<"Введите диапозон генерации от n1 до n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                A.fillR(n1,n2);
                A.get();
                array<int> B(A);
                B.shakerSort();
                cout<<"Отсортированный массив: \n";
                B.get();
                string name;
                cout<<"Укажите имя файла вывода: \n";
                cin>>name;
                ofstream fout(name);
                if (!fout.is_open()){
                    cout<<"Ошибка открытия!";
                }
                else{
                    A.get_file(fout);
                    B.get_file(fout);
                }
                break;
            }
            case 2:{
                int in2,in3;
                int a1,b1,l;
                cout<<"1) Заполнение случайными значениями\n"
                <<"2) Заполнение упорядоченными значениями\n"
                <<"3) Заполнение обратноупорядоченными значениями\n";
                cin>>in2;
                 cout<<"Введите диапазон (от _ до _) и шаг через пробел:\n";
                cin>>a1>>b1>>l;
                cout<<"1) Cортировка прямыми обменами\n"
                <<"2) Cортировка прямыми включениями.\n";
                cin>>in3;
                array<int> *A;
                int N = (b1-a1)/l;
                A = new array<int> [N];

                switch (in2){
                    case 1:{
                        for (int i = 0; i<N; i++){
                            A[i].setS(i*l);
                            A[i].fillR(1,20);
                            if (in3 == 1){
                                cout<<"tut\n";
                                A[i].shakerSort();
                            }
                            else{
                                A[i].insertSort();
                            }

                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i<N; i++){
                            A[i].setS(i*l);
                            A[i].fillU();
                            if (in3 == 1){
                                A[i].shakerSort();
                            }
                            else{
                                A[i].insertSort();
                            }
                        }

                        break;
                    }
                    case 3:{
                        for (int i = 0; i<N; i++){
                            A[i].setS(i*l);
                            A[i].fillUr();
                            if (in3 == 1){
                                A[i].shakerSort();
                            }
                            else{
                                A[i].insertSort();
                            }
                        }
                        
                        break;
                    }
                }
                A[3].get();
                break;
            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}