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
            cout << "Главное меню\n"
                << "1) Работа с одним лабиринтом\n"
                << "2) Накопление статистических данных\n"
                << "0) <<<< Выход\n";
        int sw;
        bool ff = true;
        cin >> sw;
        switch (sw){
            while(ff){
            case 1:{
                bool f2 = true;
                int size;
                cout << "Укажите размер лабиринта:\n";
                cin >> size;
                cout << "1) Построить лабиринт по алгоритму северо-восточного смещения\n"
                    << "2) Построить лабиринт по комб. алгоритму северо-восточного смещения\n"
                    << "3) Построить лабиринт по алгоритму Sidewinder\n";
                int sw2;
                cin >> sw2;
                maze B;
                maze A(size, size);
                Point start(1,1);
                Point end(size-2, size-2);
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
                //Решение будет записываться в копию
                B = A;
                while (f2){
                    cout<< "1) Найти путь в лабиринте\n"
                        << "2) Вывести лабиринт на экран\n"
                        << "3) Пересоздать\n"
                        << "4) Задать старт и финиш\n"
                        << "0) <<<\n";
                    int sw1;
                    cin >> sw1;
                    switch (sw1){
                        case 1:{
                            B = A;
                            cout << "1) Поиск пути по алгоритму A*\n"
                                << "2) Поиск пути по алгоритму DFS\n"
                                << "3) Поиск пути по алгоритму BFS\n";
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
                                    break;
                                }
                                default:{
                                    cout<<"Неверный ввод.\n";
                                    break;
                                }
                            }
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<"Завершено за "<<ans<<"ms\n";
                            B.get(cout);
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
                            int x1,y1,x2,y2;
                            cout<<"Введите координаты начала и конца через пробелы _ _ _ _\n";
                            cin>>x1>>y1>>x2>>y2;
                            B.dest(x1,y1,x2,y2);
                            A.dest(x1,y1,x2,y2);
                            break;
                        }
                        case 0:{
                            f2 = false;
                            ff = false;
                            break;
                        }
                        default:{
                            cout<<"Неверный ввод.\n";
                            break;
                        }
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
                            //B[i].dest(1,1,1,((i)*l)+a1-2);
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i < N-1; i++){
                            B[i].setS(((i)*l)+a1,((i)*l)+a1);
                            B[i].set_Westeast_alg();
                            //B[i].dest(1,1,1,((i)*l)+a1-2);
                        }
                        break;
                    }
                    case 3:{
                        for (int i = 0; i < N-1; i++){
                            B[i].setS(((i)*l)+a1,((i)*l)+a1);
                            B[i].set_Sidewinder_alg();
                            //B[i].dest(1,1,1,((i)*l)+a1-2);
                        }
                        break;
                    }
                }

                bool ff2 = true;
                while (ff2){
                    maze *C = new maze[N];
                    for (int i = 0; i < N; i++){
                        C[i] = B[i];
                    }
                    cout << "1) Поиск пути по алгоритму A*\n"
                        << "2) Поиск пути по алгоритму DFS\n"
                        << "3) Поиск пути по алгоритму BFS\n"
                        << "0) <<<\n";
                    int sw_2;
                    cin>>sw_2;
                    ofstream fout("results.txt");
                    int c = 0;
                    switch(sw_2){
                        case 1:{
                            for (int i = 0; i<N-1; i++){
                                int t_1 = clock();
                                c = B[i].A_star();
                                int t_2 = clock();
                                int ans = t_2 - t_1;
                                cout<<"Путь найден за "<<ans<<"ms\n";
                                fout<<B[i].getS()<<" "<<c<<" "<<ans<<"\n";
                                //B[i].get(cout);
                            }
                            break;
                        }
                        case 2:{
                            for (int i = 0; i<N-1; i++){
                                int t_1 = clock();
                                c = B[i].DFS();
                                int t_2 = clock();
                                int ans = t_2 - t_1;
                                cout<<"Путь найден за "<<ans<<"ms\n";
                                fout<<B[i].getS()<<" "<<c<<" "<<ans<<"\n";
                                //B[i].get(cout);
                            }
                            break;
                        }
                        case 3:{
                            for (int i = 0; i<N-1; i++){
                                int t_1 = clock();
                                c = B[i].BFS();
                                int t_2 = clock();
                                int ans = t_2 - t_1;
                                cout<<"Путь найден за "<<ans<<"ms\n";
                                fout<<B[i].getS()<<" "<<c<<" "<<ans<<"\n";
                                //B[i].get(cout);
                            }
                            break;
                        }
                        case 0:{
                            ff2 = false;
                            break;
                        }
                    }
                    fout.close();
                }
                break;
            }
        }
    }
}