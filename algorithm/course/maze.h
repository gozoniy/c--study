#ifndef MAZE_H
#define MAZE_H
//Класс точка
struct Point {
    public:
    int x, y;
    Point(): x(0),y(0){}
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const Point& other) const {
        // В данном случае, сравниваем по x, а затем по y
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    void set(int _x,int _y){
        x = _x;
        y = _y;
    }
    Point& operator=(const Point& B) {
            x = B.x;
            y = B.y;
            return *this;
        }
};
//Класс лабиринт
class maze{
        int sX,sY;
        char **matrix;   //H - Внешняя стена, X - Внутренняя стена
        Point start, end;
    public:
        maze() : sX(0), sY(0), matrix(nullptr){}
        maze(int X,int Y){
            if (X%2!=1){
                sX = X+1;
                sY = X+1;
            }
            else{
                sX = X;
                sY = Y;
            }
            matrix = new char * [sX];
            start.set(1,1);
            end.set(sX-2,sY-2);
            for (int i = 0; i<sX; i++){
                matrix[i] = new char [sY];
            }
            //Поле внутренних стен
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    matrix[i][j] = 'H'; 
                }
            }
            //Создание внутренних стен
            for(int i = 1; i<sX-1; i++){
                for (int j = 1; j<sY-1; j++){
                    if (i%2 == 0 || j%2 == 0){
                        matrix[i][j] = 'X';
                    }
                    else{
                        matrix[i][j] = ' ';
                    }
                }
            }
        }
        //Копирование
        maze(const maze& B){
            copy(B);
        };
        void copy(const maze& B){
            sX = B.sX;
            sY = B.sY;
            start = B.start;
            end = B.end;
            matrix = new char * [sX];
            for (int i = 0; i<sX; i++){
                matrix[i] = new char [sY];
            }
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    matrix[i][j] = B.matrix[i][j];
                }
            }
        }
        maze& operator=(const maze& B) {
            copy(B);
            return *this;
        }
        //Деструктор
        ~maze(){Clear();}
        void Clear(){
            for (int i = 0; i<sX; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix=nullptr;
            sX = sY = 0;
        }
        //Вывод в поток с форматированием
        void get(ostream& out){
            out<<"Лабиринт размером "<<sX<<" x "<<sY<<":\n";
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    if (Point(i,j) == start)
                        cout<<"\033[1;32m"<<'S'<<"\033[0m ";
                    else if (Point(i,j) == end)
                        cout<<"\033[1;32m"<<'E'<<"\033[0m ";
                    else if (isdigit(matrix[i][j]))
                        cout<< "\033[;90m"<<matrix[i][j]<< "\033[0m"<<" ";
                    else if ((matrix[i][j]) == '$')
                        cout<< "\033[33m"<<matrix[i][j]<< "\033[0m"<<" ";
                    
                    else
                        cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        };
        //Начало и конец лабиринта
        void dest(int x1,int y1,int x2, int y2){
            start.set(y1,x1);
            end.set(y2,x2);
        }
        //Задать размер
        void setS(int _x,int _y){
            if (_x%2!=1){
                sX = _x+1;
                sY = _y+1;
            }
            else{
                sX = _x;
                sY = _y;
            }
            start.set(1,1);
            end.set(sX-2,sY-2);
            matrix = new char * [sX];
            for (int i = 0; i<sX; i++){
                matrix[i] = new char [sY];
            }
            //Поле внутренних стен
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    matrix[i][j] = 'H'; 
                }
            }
            //Создание внутренних стен
            for(int i = 1; i<sX-1; i++){
                for (int j = 1; j<sY-1; j++){
                    if (i%2 == 0 || j%2 == 0){
                        matrix[i][j] = 'X';
                    }
                    else{
                        matrix[i][j] = ' ';
                    }
                }
            }
        }
        int getS(){
            return sX;
        }
        //Задать значение координаты
        void setCords(int a, int b, char val){
            matrix[a][b] = val;
            cout<<"|"<<matrix[a][b]<<"|\n";
        }
        //Создание лабиринта
        //Метод северо-восточного смещения
        void set_Northeast_alg(){
            srand(time(0));
            for(int i = 1; i<sX; i+=2){
                for (int j = 1; j<sY; j+=2){
                    int a = rand()%2;
                    if ((a || matrix[i-1][j] == 'H') && matrix[i][j+1] != 'H'){
                        matrix[i][j+1] = ' ';
                    }
                    else{
                        matrix[i-1][j] = ' ';
                    }
                }
            }
            //Восстановление рамки
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    if (i == 0 || j == 0 || i == sX-1 || j == sY-1)
                        matrix[i][j] = 'H';
                }
            }
        };
        //Метод комбинированного северо-восточного смещения
        void set_Westeast_alg(){
            srand(time(0));
            for(int i = 1; i<sX; i+=2){
                for (int j = 1; j<sY; j+=2){
                    if (i%16 > 8){
                        int a = rand()%2;
                        if ((a || matrix[i-1][j] == 'H') && matrix[i][j+1] != 'H'){
                            matrix[i][j+1] = ' ';
                        }
                        else{
                            matrix[i-1][j] = ' ';
                        }
                    }
                    else{
                        int a = rand()%2;
                        if ((a || matrix[i-1][j] == 'H') && matrix[i][j-1] != 'H'){
                            matrix[i][j-1] = ' ';
                        }
                        else{
                            matrix[i-1][j] = ' ';
                        }
                    }
                }
            }
            //Восстановление рамки
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    if (i == 0 || j == 0 || i == sX-1 || j == sY-1)
                        matrix[i][j] = 'H';
                }
            }
        };
        //Метод Sidewinder
        void set_Sidewinder_alg(){
            srand(time(0));
            for(int i = 1; i<sX-1; i+=2){
                if (i == 1){
                    for (int j = 1; j<sY-1; j+=2){
                        matrix[i][j+1] = ' ';
                    }
                }
                else{
                    int start = 1;
                    while(start<sY){
                        
                        int c = 1 + rand()%4;
                        int _c = 1 + rand()%c;
                        if(start>1){
                            matrix[i-1][start] = ' ';
                        }
                        for (int j = start; j < start + c; j+=2){
                            matrix[i][j+1] = ' ';
                            if (j == start + _c){
                                matrix[i-1][j] = ' ';
                                matrix[i-2][j] = ' ';
                            }
                        }
                        start+=c;
                    }   
                }
            }
            //Восстановление рамки
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    if (i == 0 || j == 0 || i == sX-1 || j == sY-1)
                        matrix[i][j] = 'H';
                }
            }
        };
        //РЕШЕНИЯ
        //Эвристика A star
        int heuristic(const Point& a, const Point& b) {
            //Manhattan distance
            return abs(a.x - b.x) + abs(a.y - b.y);
        }
        //Решение A star
        int A_star() {
            int rows = sY;
            int cols = sX;
            int visitedCount = 0;
            // Массивы для хранения посещенных вершин и расстояний
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
            // Приоритетная очередь для выполнения A* (минимальная куча)
            priority_queue<pair<int, Point>, vector<pair<int, Point>>, greater<pair<int, Point>>> pq;
            // Начальная точка
            pq.push({0, start});
            visited[start.x][start.y] = true;
            distance[start.x][start.y] = 0;
            // Массивы для определения направлений движения: вверх, вниз, влево, вправо
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            // A* поиск
            while (!pq.empty()) {
                // Извлекаем текущую точку с минимальной стоимостью
                auto current = pq.top();
                pq.pop();
                matrix[current.second.x][current.second.y] = distance[current.second.x][current.second.y]%10 + '0';
                // Проверяем, достигли ли мы конечной точки
                if (current.second.x == end.x && current.second.y == end.y) {
                    // Выводим расстояние до конечной точки
                    //cout << "Минимальное расстояние до конечной точки: " << distance[end.x][end.y] << endl;
                    // Восстанавливаем путь
                    Point pathPoint = end;
                    while (pathPoint.x != start.x || pathPoint.y != start.y) {
                        matrix[pathPoint.x][pathPoint.y] = '$';
                        for (int i = 0; i < 4; i++) {
                            int newX = pathPoint.x + dx[i];
                            int newY = pathPoint.y + dy[i];
                            if (isValid(newX, newY) && distance[newX][newY] == distance[pathPoint.x][pathPoint.y] - 1) {
                                pathPoint = Point(newX, newY);
                                break;
                            }
                        }
                    }
                    break;
                }
                // Помечаем текущую точку как посещенную
                visited[current.second.x][current.second.y] = true;
                visitedCount++;
                // Проверяем соседей текущей точки
                for (int i = 0; i < 4; i++) {
                    int newX = current.second.x + dx[i];
                    int newY = current.second.y + dy[i];
                    // Проверка на допустимость новой точки
                    if (isValid(newX, newY) && !visited[newX][newY]) {
                        // Вычисляем новую стоимость пути
                        int newCost = distance[current.second.x][current.second.y] + 1;
                        // Если новая стоимость меньше текущей, обновляем информацию и добавляем точку в очередь
                        if (newCost < distance[newX][newY]) {
                            distance[newX][newY] = newCost;
                            pq.push({newCost + heuristic(Point(newX, newY), end), Point(newX, newY)});
                        }
                    }
                }
            }
            cout<<"Посещено: "<<visitedCount<<"\n";
            return visitedCount;
        }
        //Решение DFS
        int DFS(){
            int rows = sY;
            int cols = sX;
            int visitedCount = 0;
            // Массив для хранения посещенных вершин
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            // Массив для хранения расстояний до каждой вершины
            vector<vector<int>> distance(rows, vector<int>(cols, 0));
            // Стек для выполнения DFS
            stack<Point> stk;
            // Начальная вершина
            stk.push(start);
            visited[start.x][start.y] = true;
            // Массивы для определения направлений движения: вверх, вниз, влево, вправо
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            // DFS
            while (!stk.empty()) {
                Point current = stk.top();
                stk.pop();
                matrix[current.x][current.y] = distance[current.x][current.y]%10 + '0';
                // Проверяем, достигли ли конечной вершины
                if (current.x == end.x && current.y == end.y) {
                    break;
                }
                // Проверяем соседей текущей вершины
                for (int i = 0; i < 4; i++) {
                    int newX = current.x + dx[i];
                    int newY = current.y + dy[i];
                    // Проверка на допустимость новой вершины
                    if (isValid(newX, newY) && !visited[newX][newY]) {
                        // Помечаем вершину как посещенную
                        visited[newX][newY] = true;
                        // Устанавливаем расстояние до новой вершины
                        distance[newX][newY] = distance[current.x][current.y] + 1;
                        // Добавляем новую вершину в стек
                        stk.push(Point(newX, newY));
                        visitedCount++;
                    }
                }
            }
            // Выводим расстояние до конечной вершины
            cout << "Минимальное расстояние до конечной точки: " << distance[end.x][end.y] << endl;
            // Восстанавливаем путь
            int x = end.x, y = end.y;
            while (x != start.x || y != start.y) {
                matrix[x][y] = '$'; // Пример обозначения пути
                bool found = false;
                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if (isValid(newX, newY) && distance[newX][newY] == distance[x][y] - 1) {
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
            cout<<"Посещено: "<<visitedCount<<"\n";
            return visitedCount;
        }
        //Решение BFS
        int BFS() {
            int rows = sY;
            int cols = sX;
            int visitedCount = 0;
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
                //пока не будут просмотрены новые в старые не идём
                matrix[current.x][current.y] = distance[current.x][current.y]%10 + '0';
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
                        visitedCount++;
                    }
                }
            }
            // Восстанавливаем путь
            int x = end.x, y = end.y;
            while (x != start.x || y != start.y) {
                matrix[x][y] = '$';
                bool found = false;
                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    bool a = isValid(newX, newY);
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
            cout<<"Посещено: "<<visitedCount<<"\n";
            return visitedCount;
        }
        //Проверка точки на возможность в ней находиться
        bool isValid(int _x, int _y) {
            return (_x >= 0 && _x < sX && _y >= 0 && _y < sY && ((matrix[_x][_y] !='X' && matrix[_x][_y] !='H')||(Point(_x,_y) == start || Point(_x,_y) == end))); //!visited[_x][_y]);
        }
};
#endif //MAZE_H