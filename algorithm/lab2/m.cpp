#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getFile(string filename, int size, int n1, int n2){
    ofstream out(filename);
    srand(time(0));
    for (int i = 0; i < size; i++){
        out << n1 + rand()%(n2-n1+1)<<" ";
    }
    out.close();
}

void mergeS(string filename,int size){
    ifstream in(filename);
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
    int size1, size2;
    size1 = size/2;
    size2 = size - size1;
    mergeS("buffer1.txt",size1);
    mergeS("buffer2.txt",size2);

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
}
int main(void){
    system("chcp 1251");
    getFile("numbers.txt",10,1,5);
    mergeS("numbers.txt",10);
    
}
