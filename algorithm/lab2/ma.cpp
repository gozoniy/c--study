#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//#include "m.cpp"

void DirectSort(string filename, int file_size) {
    int count = 0;
    for (int i = 1; i < file_size; i *= 2) {
        //делим файлы для слияния
        int temp;
        ifstream in(filename);
        ofstream out1("buffer1.txt"), out2("buffer2.txt");
        in >> temp;
        while (!in.eof()) {
            for (int I = 0; I < i && !in.eof(); I++) {
                out1 << temp << " ";
                in >> temp;
            }
            for (int J = 0; J < i && !in.eof(); J++) {
                out2 << temp << " ";
                in >> temp;
            }
        }
        if (i == 1)
            out2 << temp << " ";
        in.close();
        out1.close();
        out2.close();
        //Слияние
        ifstream Input_file1("buffer1.txt"), Input_file2("buffer2.txt");
        ofstream outFile(filename);
        int a, b, I, J;
        Input_file1 >> a;
        Input_file2 >> b;
        while (!Input_file1.eof() && !Input_file2.eof()) {
            //Сливаем пока в файлах есть элементы
            while (I < i && J < i && !Input_file1.eof() && !Input_file2.eof()) {
                //Cлияние файлов в один по порядку
                if (a < b) {
                    outFile << a << " ";
                    Input_file1 >> a;
                    I++;
                }
                else {
                    outFile << b << " ";
                    Input_file2 >> b;
                    J++;
                }
            }
            //Слияние оставшихся элементов в одном из двух файлов 
            while (I < i && !Input_file1.eof()) {
                outFile << a << " ";
                Input_file1 >> a;
                I++;
            }
            while (J < i && !Input_file2.eof()) {
                outFile << b << " ";
                Input_file2 >> b;
                J++;
            }
            I = J = 0;
        }
        while (!Input_file1.eof()) {
            outFile << a << " ";
            Input_file1 >> a;
        }
        while (!Input_file2.eof()) {
            outFile << b << " ";
            Input_file2 >> b;
        }
        Input_file1.close();
        Input_file2.close();
        outFile.close();
        count++;
        }
    cout<<"Всего слияний: "<<count<<"\n";
    remove("buffer1.txt");
    remove("buffer2.txt");
}
void getFile(string filename, int file_size, int n1, int n2){
    ofstream in(filename);
    srand(time(0));
    for (int i = 0; i < file_size; i++){
        in << n1 + rand()%(n2-n1+1)<<" ";
    }
    in.close();
}
void readFile(string filename, int file_size){
    ifstream in(filename);
    int temp;
    in>>temp;
    for (int i = 0; i < file_size; i++){
        cout<<temp<<" ";
        in>>temp;
    }
    cout<<"\n";
}
int main(void){
    system("chcp 1251");
    int f = 1;
    int in;
    while (f){
        cout<<"1) Cортировка одного файла, сформированного случайным образом\n";
        cout<<"2) Режим накопления статистических данных\n";
        cout<<"0) Выход \n";
        cin>>in;;
        switch (in){
            case 1:{
                int n,in2;
                cout<<"Задайте длину файла: ";
                cin>>n;
                cout<<"Введите диапозон генерации от n1 до n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                getFile("numbers.txt", n, n1, n2);
                cout<<"1) Сортировка прямым слиянием Merge Sort\n"
                <<"2) Многофазная сортировка Polyphase Merge Sort\n";
                cin>>in2;
                switch (in2){
                    case 1:{
                        cout<<"!\n";
                        DirectSort("numbers.txt",n);
                        break;
                    }
                    case 2:{
                        //B.polyphaseMergeSort();
                        break;
                    }
                }
                
                cout<<"Отсортированный файл: \n";
                readFile("numbers.txt",n);
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

            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}