//21. ���������� ������� ��������; ���������� ������� �����������. 
#include <iostream>

using namespace std;
#include "array.cpp"

int main(void){
    system("chcp 1251");
    int f = 1;
    int in;
    while (f){
        cout<<"1) C��������� ������ �������, ��������������� ��������� �������\n";
        cout<<"2) ����� ���������� �������������� ������\n";
        cout<<"0) ����� \n";
        cin>>in;;
        switch (in){
            case 1:{
                int n;
                cout<<"������� ������ �������: ";
                cin>>n;
                array<int> A(n);
                cout<<"������� �������� ��������� �� n1 �� n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                A.fillR(n1,n2);
                A.get();
                array<int> B(A);
                B.shakerSort();
                cout<<"��������������� ������: \n";
                B.get();
                string name;
                cout<<"������� ��� ����� ������: \n";
                cin>>name;
                ofstream fout(name);
                if (!fout.is_open()){
                    cout<<"������ ��������!";
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
                cout<<"1) ���������� ���������� ����������\n"
                <<"2) ���������� �������������� ����������\n"
                <<"3) ���������� ��������������������� ����������\n";
                cin>>in2;
                cout<<"������� �������� (�� _ �� _) � ��� ����� ������:\n";
                cin>>a1>>b1>>l;
                array<int> *A;
                int N = (b1-a1)/l+1;
                A = new array<int> [N];
                switch (in2){
                    case 1:{
                        for (int i = 1; i<N; i++){
                            A[i].setS(i*l);
                            A[i].fillR(1,20);
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 1; i<N; i++){
                            A[i].setS(i*l);
                            A[i].fillU();
                        }
                        break;
                    }
                    case 3:{
                        for (int i = 1; i<N; i++){
                            A[i].setS(i*l);
                            A[i].fillUr();
                        }
                        break;
                    }
                }
                cout<<"����� ��������� "<<N-1<<" ��������.\n";

                cout<<"1) C��������� ������� �������� shaker sort\n"
                <<"2) C��������� ������� ����������� insert sort\n";
                cin>>in2;
                int t1 = clock();
                switch (in2){
                    case 1:{
                        for (int i = 1; i<N; i++){
                            int t_1 = clock();
                            A[i].shakerSort();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<A[i].getS()<<" �� ������������� �� "<<ans<<"ms\n";
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 1; i<N; i++){
                            int t_1 = clock();
                            A[i].insertSort();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<A[i].getS()<<" �� ������������� �� "<<ans<<"ms\n";
                        }
                        break;
                    }
                }
                int t2 = clock();
                int answ = (t2-t1);
                cout<<"����� �����: "<<answ<<"ms\n";
                break;
            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}