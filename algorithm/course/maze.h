#ifndef MAZE_H
#define MAZE_H

class dot{
        int x,y;
    public:
        dot(){}
        dot(dot &B){x = B.x; y = B.y;}
        dot(int _x, int _y):x(_x),y(_y){}
        void get(int& _x,int& _y){
            _x = x;
            _y = y;
        }
        void set(int _x,int _y){
            x = _x;
            y = _y;
        }
        dot& operator = (dot &B){x = B.x; y = B.y; return B;}
        bool operator == (dot &B){return x == B.x && y == B.y;}
};

class maze{
        int sX,sY;
        int **matrix;   //2 - Внешняя стена, 1 - Внутренняя стена, 0 - Пустая клетка
        int **visited;
    public:
        maze() : sX(0), sY(0), matrix(nullptr),visited(nullptr){}
        maze(int X,int Y) : sX(X),sY(Y),matrix(new int * [sX]){
            for (int i = 0; i<sX; i++){
                matrix[i] = new int [sY];
            }
            //Поле внутренних стен
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    matrix[i][j] = 2; 
                }
            }
            //Создание внутренних стен
            for(int i = 1; i<sX-1; i++){
                for (int j = 1; j<sY-1; j++){
                    if (i%2 == 0 || j%2 == 0){
                        matrix[i][j] = 1;
                    }
                    else{
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        bool isValid(int _x, int _y) {
            return (_x >= 0 && _x < sX && _y >= 0 && _y < sY && (matrix[_x][_y] != 2 && matrix[_x][_y] != 1) && !visited[_x][_y]);
        }

        maze(const maze& B);
        ~maze(){Clear();}
        void Clear(){
            for (int i = 0; i<sX; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix=nullptr;
            sX = sY = 0;
        }
        void get(ostream& out);
        void setS(int _x,int _y){
            sX = _x;
            sY = _y;
            matrix = new int * [sX];
            for (int i = 0; i<sX; i++){
                matrix[i] = new int [sY];
            }
            //Поле внутренних стен
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    matrix[i][j] = 2; 
                }
            }
            //Создание внутренних стен
            for(int i = 1; i<sX-1; i++){
                for (int j = 1; j<sY-1; j++){
                    if (i%2 == 0 || j%2 == 0){
                        matrix[i][j] = 1;
                    }
                    else{
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        void setCords(){
            for(int i = 1; i<sX-1; i++){
                for (int j = 1; j<sY-1; j++){
                    cin>>matrix[i][j];
                }
            }
        }
        //void getS(){return sX;}
        //Создание лабиринта
        void set_Northeast_alg();
        void set_Westeast_alg();
        void set_Sidewinder_alg();

        //Решение лабиринта
        void A_star();
        void DFS();
        void BFS();

};

#endif //MAZE_H