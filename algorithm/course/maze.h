#ifndef MAZE_H
#define MAZE_H

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
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
        void get(ostream& out){
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
                    else if (matrix[i][j] == -5){
                        cout<<"@ ";
                    }
                    else if (matrix[i][j] == 3){
                        cout<<". ";
                    }
                    else{
                        cout<<matrix[i][j]<<" ";
                    }
                }
                cout<<"\n";
            }
        };
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
        void set_Northeast_alg(){
            srand(time(0));
            for(int i = 1; i<sX-1; i+=2){
                for (int j = 1; j<sY-1; j+=2){
                    int a = rand()%2;
                    if ((a || matrix[i-1][j] == 2) && matrix[i][j+1] != 2){
                        matrix[i][j+1] = 0;
                    }
                    else{
                        matrix[i-1][j] = 0;
                    }
                }
            }
        };
        void set_Westeast_alg(){
            srand(time(0));
            for(int i = 1; i<sX-1; i+=2){
                for (int j = 1; j<sY-1; j+=2){
                    if (i%16 > 8){
                        int a = rand()%2;
                        if ((a || matrix[i-1][j] == 2) && matrix[i][j+1] != 2){
                            matrix[i][j+1] = 0;
                        }
                        else{
                            matrix[i-1][j] = 0;
                        }
                    }
                    else{
                        int a = rand()%2;
                        if ((a || matrix[i-1][j] == 2) && matrix[i][j-1] != 2){
                            matrix[i][j-1] = 0;
                        }
                        else{
                            matrix[i-1][j] = 0;
                        }
                    }
                }
            }
            
            matrix[sX-2][sY-2] = -1;
            matrix[0][1] = 2;
        };
        void set_Sidewinder_alg(){
            srand(time(0));
            for(int i = 1; i<sX-1; i+=2){
                if (i == 1){
                    for (int j = 1; j<sY-1; j+=2){
                        matrix[i][j+1] = 0;
                    }
                }
                else{
                    int start = 1;
                    while(start<sY){
                        
                        int c = 1 + rand()%4;
                        int _c = 1 + rand()%c;
                        if(start>1){
                            matrix[i-1][start] = 0;
                        }
                        for (int j = start; j < start + c; j+=2){
                            matrix[i][j+1] = 0;
                            if (j == start + _c){
                                matrix[i-1][j] = 0;
                                matrix[i-2][j] = 0;
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
        };

        //Решение лабиринта
        void A_star(){
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
        void DFS(){
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
        };

        void BFS() {
            cout<<"!\n";
            Point start(1,1);
            Point end(sX-2,sY-2);
            int rows = sY;
            int cols = sX;
            // Массивы для хранения посещенных вершин и расстояний
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            vector<vector<int>> distance(rows, vector<int>(cols, 0));

            // Переменные для хранения координат текущей вершины
            int currentX, currentY;

            // Очередь для выполнения BFS
            queue<Point> q;

            // Начальная вершина
            q.push(start);
            visited[start.x][start.y] = true;
            distance[start.x][start.y] = 0;

            // Массивы для определения направлений движения: вверх, вниз, влево, вправо
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            // BFS
            while (!q.empty()) {
                // Извлекаем вершину из очереди
                Point current = q.front();
                matrix[current.x][current.y] = 3;
                q.pop();
                currentX = current.x;
                currentY = current.y;

                // Проверяем соседей текущей вершины
                for (int i = 0; i < 4; i++) {
                    int newX = currentX + dx[i];
                    int newY = currentY + dy[i];

                    // Проверка на допустимость новой вершины
                    if (isValid(newX, newY) && !visited[newX][newY]) {
                        // Помечаем вершину как посещенную
                        visited[newX][newY] = true;
                        // Устанавливаем расстояние до новой вершины
                        distance[newX][newY] = distance[currentX][currentY] + 1;
                        // Добавляем новую вершину в очередь
                        q.push(Point(newX, newY));
                    }
                }
            }
            get(cout);
            // Выводим расстояние до конечной вершины
            cout << "Минимальное расстояние до конечной точки: " << distance[end.x][end.y] << endl;

            // Восстанавливаем путь
            cout << "Путь от начальной точки до конечной точки:" << endl;
            int x = end.x, y = end.y;
            while (x != start.x || y != start.y) {
                cout << "(" << x << ", " << y << ")" << endl;
                matrix[x][y] = -5;
                bool found = false;
                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    bool a = isValid(newX, newY);
                    cout<<newX<<"_"<<newY<<":"<<a<<"\n";
                    if (a && distance[newX][newY] == distance[x][y] - 1) {
                        x = newX;
                        y = newY;
                        found = true;
                        break;
                    }
                }
                // Проверка наличия подходящего направления
                if (!found) {
                    cout << "Ошибка: Нет подходящего направления!" << endl;
                    break;
                }
            }
            cout << "(" << start.x << ", " << start.y << ")" << endl;
        }


        bool isValid(int _x, int _y) {
            return (_x >= 0 && _x < sX && _y >= 0 && _y < sY && (matrix[_x][_y] !=1 && matrix[_x][_y] !=2)); //!visited[_x][_y]);
        }

};

#endif //MAZE_H