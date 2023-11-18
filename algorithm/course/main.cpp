#include <iostream>
#include <fstream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "maze.cpp"

int main(void){
    system("chcp 1251");
    bool f = true;
    while (f){
            cout << "Главное меню\n"
                << "1) Работа с одним лабиринтом\n"
                << "2) Накопление статистических данных\n"
                << "0) <<<< Выход\n";
        int sw;
        cin >> sw;
        switch (sw){
            case 1:{
                bool f2 = true;
                int x, y;
                cout << "Укажите размеры лабиринта _x _y:\n";
                cin >> x >> y;
                maze A(x, y);
                while (f2){
                    cout << "1) Построить лабиринт\n"
                        << "2) Найти путь в лабиринте\n"
                        << "3) Вывести лабиринт на экран\n"
                        << "0) <<<\n";
                    int sw1;
                    cin >> sw1;
                    switch (sw1){
                        case 1:{
                            cout << "1) Построить лабиринт по алгоритму северо-восточного смещения\n"
                                << "2) Построить лабиринт по комб. алгоритму северо-восточного смещения\n"
                                << "3) Построить лабиринт по алгоритму Sidewinder\n";
                            int sw2;
                            cin >> sw2;
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
                            break;
                        }
                        case 2:{
                            cout << "1) Поиск пути по алгоритму A*\n"
                                << "2) Поиск пути по алгоритму DFS\n"
                                << "3) Поиск пути по алгоритму BFS\n";
                            int sw3;
                            cin >> sw3;
                            switch (sw3){
                                case 1:{
                                    A.A_star();
                                    break;
                                }
                                case 2:{
                                    A.DFS();
                                    break;
                                }
                                case 3:{
                                    A.BFS();
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:{
                            A.get(cout);
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
                            break;
                        }
                    }
                }
            }
            case 2:{
                cout << "1) Построить лабиринты по алгоритму северо-восточного смещения\n"
                    << "2) Построить лабиринты по комб. алгоритму северо-восточного смещения\n"
                    << "3) Построить лабиринты по алгоритму Sidewinder\n";
                int sw_1;
                int a1,b1,l;
                cin>>sw_1;
                cout<<"Введите размер лабиринта (от _ до _) и шаг через пробел:\n";
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
                cout << "1) Поиск пути по алгоритму A*\n"
                    << "2) Поиск пути по алгоритму DFS\n"
                    << "3) Поиск пути по алгоритму BFS\n";
                int sw_2;
                cin>>sw_2;
                switch(sw_2){
                    case 1:{
                        for (int i = 0; i<N-1; i++){
                            int t_1 = clock();
                            B->A_star();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<"Путь найден за "<<ans<<"ms\n";
                            //fout<<B[i].getS()<<" "<<ans<<"\n";

                        }
                    }
                }

                break;
            }
        }
    }
}