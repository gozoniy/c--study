#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void getFile(string filename, int size, int n1, int n2){
    ofstream out(filename);
    srand(time(0));
    for (int i = 0; i < size; i++){
        out << n1 + rand()%(n2-n1+1)<<" ";
    }
    out.close();
}

//Сортировка прямым слиянием
void mergeS(string filename,int size){
    //Выполняем операцию log2(size) раз
    for (int i = 1; i<size; i*= 2){
        ifstream in(filename);
        ofstream out1("buffer1.txt");
        ofstream out2("buffer2.txt");
        //Деление в два временных файла через один элемент
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
        /*
        while(!in.eof()){
            if (c>size/2)
                out1<<temp<<" ";
            else
                out2<<temp<<" ";
            in>>temp;
            c++;
        }*/
        in.close();
        out1.close();
        out2.close();
        int size1, size2;
        size1 = size/2;
        size2 = size - size1;
        //Слияние
        ofstream os(filename);
        ifstream in1("buffer1.txt");
        ifstream in2("buffer2.txt");
        int t1;
        int o, p;
        o = p = 0;
        int temp1, temp2;
        in1>>temp1;
        in2>>temp2;
        for (int i = 0; i < size; i++){
            if (p>=(size2)||(o<size1 && temp1<temp2)){
                os<<temp1<<" ";
                o++;
                in1>>temp1;
            }
            else{
                os<<temp2<<" ";
                p++;
                in2>>temp2;
            }
        }
        os.close();
        in1.close();
        in2.close();
    }
    cout<<"Сортировка завершена.\n";
    //remove("buffer1.txt");
    //remove("buffer2.txt");
}

//Трёхпутевая сортировка многопутевым слиянием
void balanceMergeSort(string filename,int size){
    //Выполняем операцию log2(size) раз
    for (int i = 1; i<size; i*= 2){
        ifstream in(filename);
        //Деление исходного файла на три временных поровну
        int c = 0;
        int temp = 0;
        in>>temp;
        int tapes = 3;
        for (int i = 0; i<tapes; i++){
            ofstream out;
            out.open("buffer"+to_string(i+1)+".txt");
            int start = (size / tapes) *i;
            int end = (size / tapes) * (i + 1);
            while (start <= c && c<end){
                out<<temp<<" ";
                c++;
                in>>temp;
            }
            out.close();
        }
        
        in.close();

    
        
        int size1, size2, size3;
        size1 = size/3;
        size2 = (size/3)*2;
        size3 = (size/3)*3;
        //Слияние
        ofstream os(filename);
        ifstream in1("buffer1.txt");
        ifstream in2("buffer2.txt");
        ifstream in3("buffer3.txt");
        int t1;
        int o, p, m;
        o = p = m = 0;
        int temp1, temp2, temp3;
        in1>>temp1;
        in2>>temp2;
        in3>>temp3;
        for (int i = 0; i < size; i++){
            if (o<size1 && temp1<temp2 && temp1<temp3){
                os<<temp1<<" ";
                o++;
                in1>>temp1;
            }
            else if (p<size2 && temp2<temp1 && temp2<<temp3){
                os<<temp2<<" ";
                p++;
                in2>>temp2;
            }
            else if (m<size3 && temp3<temp2 && temp3<<temp1){
                os<<temp3<<" ";
                m++;
                in3>>temp3;
            }
        }
        os.close();
        in1.close();
        in2.close();
    }
    cout<<"Сортировка завершена.\n";
    //remove("buffer1.txt");
    //remove("buffer2.txt");
}

int main(void){
    system("chcp 1251");
    getFile("numbers.txt",100000,1,5);
    int t_1 = clock();
    mergeS("numbers.txt",100000);
    int t_2 = clock();
    int ans = t_2 - t_1;
    cout<<" эл отсортированы за "<<ans<<"ms\n";
    
}
