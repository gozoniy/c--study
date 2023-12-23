#include <iostream>
#include <fstream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#include "maze.h"

int main(void){
    system("chcp 1251");
    bool f = true;
    while (f){
            cout << "������� ����\n"
                << "1) ������ � ����� ����������\n"
                << "2) ���������� �������������� ������\n"
                << "0) <<<< �����\n";
        int sw;
        bool ff = true;
        cin >> sw;
        switch (sw){
            while(ff){
            case 1:{
                bool f2 = true;
                int x, y;
                cout << "������� ������ ���������:\n";
                cin >> x >> y;
                cout << "1) ��������� �������� �� ��������� ������-���������� ��������\n"
                    << "2) ��������� �������� �� ����. ��������� ������-���������� ��������\n"
                    << "3) ��������� �������� �� ��������� Sidewinder\n";
                int sw2;
                cin >> sw2;
                maze A(x, y);
                switch (sw2){
                            case 1:{
                                A.set_Northeast_alg();
                                break;
                            }
                            case 2:{
                                A.set_Westeast_alg();
                                break;
                            }
                            case 3:{
                                A.set_Sidewinder_alg();
                                break;
                            }
                        }
                maze B(A);
                while (f2){
                    cout<< "1) ����� ���� � ���������\n"
                        << "2) ������� �������� �� �����\n"
                        << "3) �����������\n"
                        << "4) ������ ����������\n"
                        << "0) <<<\n";
                    int sw1;
                    cin >> sw1;
                    switch (sw1){

                        case 1:{
                            B = A;
                            cout << "1) ����� ���� �� ��������� A*\n"
                                << "2) ����� ���� �� ��������� DFS\n"
                                << "3) ����� ���� �� ��������� BFS\n";
                            int sw3;
                            cin >> sw3;
                            int t_1 = clock();
                            switch (sw3){
                                case 1:{
                                    B.A_star();
                                    break;
                                }
                                case 2:{
                                    B.DFS();
                                    break;
                                }
                                case 3:{                            
                                    B.BFS();
                                    cout<<"2\n";
                                    break;
                                }
                            }
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<"��������� �� "<<ans<<"ms\n";
                            break;
                        }
                        case 2:{
                            B.get(cout);
                            break;
                        }
                        case 3:{
                            f2 = false;
                            break;
                        }
                        case 4:{
                            int a,b,val;
                            cin>>a>>b;
                            cin>>val;
                            A.setCords();
                            break;
                        }
                        case 0:{
                            f2 = false;
                            ff = false;
                            break;
                        }
                    }
                }
            }
            }
            case 2:{
                cout << "1) ��������� ��������� �� ��������� ������-���������� ��������\n"
                    << "2) ��������� ��������� �� ����. ��������� ������-���������� ��������\n"
                    << "3) ��������� ��������� �� ��������� Sidewinder\n";
                int sw_1;
                int a1,b1,l;
                cin>>sw_1;
                cout<<"������� ������ ��������� (�� _ �� _) � ��� ����� ������:\n";
                cin>>a1>>b1>>l;
                maze *B;
                int N = (b1-a1)/l+1;
                B = new maze [N];
                
                switch (sw_1){
                    case 1:{
                        for (int i = 0; i < N-1; i++){
                            B[i].setS(((i)*l)+a1,((i)*l)+a1);
                            B[i].set_Northeast_alg();
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i < N-1; i++){
                            B[i].setS(((i)*l)+a1,((i)*l)+a1);
                            B[i].set_Westeast_alg();
                        }
                        break;
                    }
                    case 3:{
                        for (int i = 0; i < N-1; i++){
                            B[i].setS(((i)*l)+a1,((i)*l)+a1);
                            B[i].set_Sidewinder_alg();
                        }
                        break;
                    }
                }
                ofstream fout("results.txt");
                cout << "1) ����� ���� �� ��������� A*\n"
                    << "2) ����� ���� �� ��������� DFS\n"
                    << "3) ����� ���� �� ��������� BFS\n";
                int sw_2;
                cin>>sw_2;
                switch(sw_2){
                    case 1:{
                        for (int i = 0; i<N-1; i++){
                            int t_1 = clock();
                            B->A_star();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<"���� ������ �� "<<ans<<"ms\n";
                            //fout<<B[i].getS()<<" "<<ans<<"\n";

                        }
                    }
                }

                break;
            }
        }
    }
}