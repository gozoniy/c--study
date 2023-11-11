#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fillR(int *A, int size, int n1, int n2){
    srand(time(0));
    for (int i = 0; i < size; i++){
        A[i] = n1 + rand()%(n2-n1+1);
    }
}
void get(int *A, int size){
    cout<<"Массив длинной "<<size<<":\n";
    for (int i = 0; i < size; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
void copy(int *A, int *B, int size){
    for (int i = 0; i<size; i++){
        B[i] = A[i];
    }
}

void MergeS(string inp){

    ifstream in(inp);
    int t = 0;
    int size = 0;

    //Возвраты по длине
    while(in>>t){
        size++;
    }
    cout<<size;
    if (size <= 1){
        return;
    }
    if (size == 2){
        int a,b;
        in>>a;
        in>>b;
        if (a>b){
            in.close();
            ofstream out(inp);
            out<<b<<" "<<a;
            out.close();
        }
        else
            in.close();
        return;
    }
    
    //Деление файла
    ofstream out1("buffer1.txt");
    ofstream out2("buffer2.txt");
    int c = 0;
    int temp = 0;
    in>>temp;
    while(!in.eof()){
        if (c%2==0)
            out1<<temp<<" ";
        else
            out2<<temp<<" ";
        in>>temp;
        c++;
    }
    in.close();
    out1.close();
    out2.close();
    MergeS("buffer1.txt");
    MergeS("buffer2.txt");

    //Перезапуск потоков
    ifstream in1("buffer1.txt");
    ifstream in2("buffer2.txt");
    int size1, size2;
    size1 = size2 = 0;
    int t1;
    while(in1>>t1){
        size1++;
    }
    while(in2>>t1){
        size2++;
    }
    //Слияние
    ofstream os(inp);
    int o, p;
    o = p = 0;
    int temp1, temp2;
    in1>>temp1;
    in2>>temp2;
    
    for (int i = 0; i < size; i++){
        if (p>=(size2)||(o<size1 && temp1<temp2)){
            os<<temp1;
            o++;
            in1>>temp1;
        }
        else{
            os<<temp2;
            p++;
            in2>>temp2;
        }
    }
    os.close();
    remove("buffer1.txt");
    remove("buffer2.txt");

}

void getFile(string filename, int size, int n1, int n2){
    ofstream out(filename);
    srand(time(0));
    for (int i = 0; i < size; i++){
        out << n1 + rand()%(n2-n1+1)<<" ";
    }
    out.close();
}

void MergeSort(string filename){
    ifstream in(filename);
    int t = 0;
    int size = 0;
    //Возвраты по длине
    while(in>>t){
        size++;
    }
    cout<<size;
    if (size <= 1){
        return;
    }
    if (size == 2){
        int a,b;
        in>>a;
        in>>b;
        if (a>b){
            in.close();
            ofstream out(filename);
            out<<b<<" "<<a;
            out.close();
        }
        else
            in.close();
        return;
    }
    //Делим на два файла
    ofstream out1("buffer1.txt");
    ofstream out2("buffer2.txt");
    int c = 0;
    int temp = 0;
    in>>temp;
    while(!in.eof()){
        if (c%2==0)
            out1<<temp<<" ";
        else
            out2<<temp<<" ";
        in>>temp;
        c++;
    }
    in.close();
    out1.close();
    out2.close();
    MergeSort("buffer1.txt");
    MergeSort("buffer2.txt");

    //Перезапуск потока для чтения
    ifstream in1("buffer1.txt");
    ifstream in2("buffer2.txt");
    int size1, size2;
    size1 = size2 = 0;
    int t1;
    while(in1>>t1){
        size1++;
    }
    while(in2>>t1){
        size2++;
    }
    //Слияние
    ofstream os(filename);
    int o, p;
    o = p = 0;
    int temp1, temp2;
    in1>>temp1;
    in2>>temp2;
    
    for (int i = 0; i < size; i++){
        if (p>=(size2)||(o<size1 && temp1<temp2)){
            os<<temp1;
            o++;
            in1>>temp1;
        }
        else{
            os<<temp2;
            p++;
            in2>>temp2;
        }
    }
    os.close();
}

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
                int n,in2;
                cout<<"Задайте размер массива: ";
                cin>>n;
                int *A;
                A = new int [n];
                cout<<"Введите диапозон генерации от n1 до n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                fillR(A,n,n1,n2);
                getFile("numbers.txt", n, n1, n2);
                get(A, n);
                int *B = new int [n];
                copy(A,B,n);
                cout<<"1) Сортировка прямым слиянием Merge Sort\n"
                <<"2) Многофазная сортировка Polyphase Merge Sort\n";
                cin>>in2;
                switch (in2){
                    case 1:{
                        MergeSort("numbers.txt");
                        break;
                    }
                    case 2:{
                        //B.polyphaseMergeSort();
                        break;
                    }
                }
                
                cout<<"Отсортированный массив: \n";
                get(B, n);
                string name;
                /*cout<<"Укажите имя файла вывода: \n";
                cin>>name;
                ofstream fout(name);
                if (!fout.is_open()){
                    cout<<"Ошибка открытия!";
                }
                else{
                    A.get_file(fout);
                    B.get_file(fout);
                }
                fout.close();*/

                break;
            }
            /*
            case 2:{
                int in2,in3;
                int a1,b1,l;
                cout<<"1) Заполнение случайными значениями\n"
                <<"2) Заполнение упорядоченными значениями\n"
                <<"3) Заполнение обратноупорядоченными значениями\n";
                cin>>in2;
                cout<<"Введите диапазон (от _ до _) и шаг через пробел:\n";
                cin>>a1>>b1>>l;
                arr<int> *A;
                int N = (b1-a1)/l+1;
                A = new arr<int> [N];
                switch (in2){
                    case 1:{
                        for (int i = 0; i<N-1; i++){
                            A[i].setS(((i)*l)+a1);
                            A[i].fillR(1,20);
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i<N-1; i++){
                            A[i].setS(((i)*l)+a1);
                            A[i].fillU();
                        }
                        break;
                    }
                    case 3:{
                        for (int i = 0; i<N-1; i++){
                            A[i].setS(((i)*l)+a1);
                            A[i].fillUr();
                        }
                        break;
                    }
                }
                cout<<"Всего заполнено "<<N-1<<" массивов.\n";

                cout<<"1) Сортировка прямым слиянием Merge Sort\n"
                <<"2) Многофазная сортировка Polyphase Merge Sort\n";
                cin>>in2;
                ofstream fout("results.txt");
                int t1 = clock();
                switch (in2){
                    case 1:{
                        for (int i = 0; i<N-1; i++){
                            int t_1 = clock();
                            A[i].mergeSort();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<A[i].getS()<<" эл отсортированы за "<<ans<<"ms\n";
                            fout<<A[i].getS()<<" "<<ans<<"\n";
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i<N-1; i++){
                            int t_1 = clock();
                            A[i].polyphaseMergeSort();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<A[i].getS()<<" эл отсортированы за "<<ans<<"ms\n";
                            fout<<A[i].getS()<<" "<<ans<<"\n";
                        }
                        break;
                    }
                }
                int t2 = clock();
                int answ = (t2-t1);
                cout<<"Общее время: "<<answ<<"ms\n";
                break;

            }*/
            case 0:{
                f = 0;
                break;
            }
        }
    }
}