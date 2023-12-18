#include <iostream>
#include <fstream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
using namespace std;
#include "List.h"
#include "maze.h"

void maze::get(ostream& out){
    out<<"Лабиринт размером "<<sX<<" x "<<sY<<":\n";
    for(int i = 0; i<sX; i++){
        for (int j = 0; j<sY; j++){
            if (matrix[i][j] == 2){
                cout<<"H ";
            }
            else if (matrix[i][j] == 1){
                cout<<"X ";
            }
            else if (matrix[i][j] == -1){
                cout<<"* ";
            }
            else if (matrix[i][j] == 0){
                cout<<"  ";
            }
            else{
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}
//СОЗДАНИЕ
//Алгоритм северо-восточного смещения
void maze::set_Northeast_alg(){
    srand(time(0));
    for(int i = 1; i<sX-1; i+=2){
        for (int j = 1; j<sY-1; j+=2){
            int a = rand()%2;
            if ((a || matrix[i-1][j] == 2) && matrix[i][j+1] != 2){
                matrix[i][j+1] = false;
            }
            else{
                matrix[i-1][j] = false;
            }
        }
    }
}
//Алгоритм западно-восточного смещения
void maze::set_Westeast_alg(){
    srand(time(0));
    for(int i = 1; i<sX-1; i+=2){
        for (int j = 1; j<sY-1; j+=2){
            if (i%16 > 8){
                int a = rand()%2;
                if ((a || matrix[i-1][j] == 2) && matrix[i][j+1] != 2){
                    matrix[i][j+1] = false;
                }
                else{
                    matrix[i-1][j] = false;
                }
            }
            else{
                int a = rand()%2;
                if ((a || matrix[i-1][j] == 2) && matrix[i][j-1] != 2){
                    matrix[i][j-1] = false;
                }
                else{
                    matrix[i-1][j] = false;
                }
            }
        }
    }
    
    matrix[sX-2][sY-2] = -1;
    matrix[0][1] = 2;
}
//Алгоритм «Sidewinder»
void maze::set_Sidewinder_alg(){
    srand(time(0));
    for(int i = 1; i<sX-1; i+=2){
        if (i == 1){
            for (int j = 1; j<sY-1; j+=2){
                matrix[i][j+1] = false;
            }
        }
        else{
            int start = 1;
            while(start<sY){
                
                int c = 1 + rand()%4;
                int _c = 1 + rand()%c;
                if(start>1){
                    matrix[i-1][start] = false;
                }
                for (int j = start; j < start + c; j+=2){
                    matrix[i][j+1] = false;
                    if (j == start + _c){
                        matrix[i-1][j] = false;
                        matrix[i-2][j] = false;
                    }
                }
                start+=c;
            }   
        }
    }
    for(int i = 1; i<sX; i++){
        for (int j = 1; j<sY; j++){
            if (i == 0 || j == 0 || i == sX-1 || j == sY-1)
                matrix[i][j] = 2;
        }
    }
}

//РЕШЕНИЕ
//A*
void maze::A_star(){

    int f = 1;
    //Начальные x y:
    int x = 1;
    int y = 1;
    int cost = 0;
    cout<<"("<<x<<","<<y<<")\n";
    while(f){
        if (matrix[y][x] == 9){
            cout<<"Путь найден.\n";
            break;
        }
        
        else {
            for (int i = 0; i<3; i++){
                for (int j = 0; j<3; j++){
                    cout<<i;
                    if (matrix[i+y][j+x] == 0){
                        matrix[i+y][j+x] = cost;
                        cost++;
                        x +=j;
                        y +=i;
                    }
                }
            }
        }
    }
}
void A_star(){};
void DFS(){};
void BFS(){};

/*
//DFS
void maze::DFS(){

    int f = 1;
    //Начальные x y:
    int x = 1;
    int y = 1;
    int cost = 0;
    
    vector <dot> Frontier; //Запланированные
    vector <dot> Explored; //Пройденные
    vector <int> A;
    Frontier.push_back(dot(x,y));
    Explored.push_back(dot(x,y));
    while(Frontier.size()){
        dot curr;
        curr = Frontier.front();
        curr.get(x,y);
        Frontier.erase(Frontier.begin());
        dot child;
        cout<<"("<<x<<","<<y<<")\n";
        if (false){//matrix[y][x] == -1){
            cout<<"Путь найден.\n";
            break;
        }
        else {
            bool Up,Do,Le,Ri;
            Up = !matrix[y-1][x];
            Do = !matrix[y+1][x];
            Ri = !matrix[y][x+1];
            Le = !matrix[y][x-1];
            if (Up){
                child.set(y-1,x);
                if (find(Frontier.begin(),Frontier.end(),child)==Frontier.end())
                    Frontier.push_back(child);
                    Explored.push_back(child);

            }
            if (Do){
                child.set(y+1,x);
                if (find(Frontier.begin(),Frontier.end(),child)==Frontier.end())
                    Frontier.push_back(child);
                    Explored.push_back(child);
            }
            if (Ri){
                child.set(y,x+1);
                if (find(Frontier.begin(),Frontier.end(),child)==Frontier.end())
                    Frontier.push_back(child);
                    Explored.push_back(child);
            }
            if (Le){
                child.set(y,x-1);
                if (find(Frontier.begin(),Frontier.end(),child)==Frontier.end())
                    Frontier.push_back(child);
                    Explored.push_back(child);
            }
            
            matrix[y][x] = 5;
        }
    }
    cout<<"Завершено.\n";
    
    
}*/