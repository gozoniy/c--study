#ifndef MAZE_H
#define MAZE_H

struct Point {
    public:
    int x, y;
    Point(int _y, int _x) : x(_x), y(_y) {}
    bool operator<(const Point& other) const {
        // � ������ ������, ���������� �� x, � ����� �� y
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

class maze{
        int Col,Row;
        char **matrix;   //2 - ������� �����, 1 - ���������� �����, 0 - ������ ������
    public:
        maze() : Col(0), Row(0), matrix(nullptr){}
        maze(int X,int Y) : Col(X),Row(Y),matrix(new char * [Row]){
            for (int i = 0; i<Row; i++){
                matrix[i] = new char [Col];
            }
            //���� ���������� ����
            for(int i = 0; i<Row; i++){
                for (int j = 0; j<Col; j++){
                    matrix[i][j] = 'H'; 
                }
            }
            //�������� ���������� ����
            for(int i = 1; i<Row-1; i++){
                for (int j = 1; j<Col-1; j++){
                    if (i%2 == 0 || j%2 == 0){
                        matrix[i][j] = 'X';
                    }
                    else{
                        matrix[i][j] = ' ';
                    }
                }
            }
        }

        //�����������
        maze(const maze& B){
            copy(B);
        };
        void copy(const maze& B){
            Col = B.Col;
            Row = B.Row;
            matrix = new char * [Row];
            for (int i = 0; i<Row; i++){
                matrix[i] = new char [Col];
            }
            for(int i = 0; i<Row; i++){
                for (int j = 0; j<Col; j++){
                    matrix[i][j] = B.matrix[i][j];
                }
            }
        }
        maze& operator=(const maze& B) {
            copy(B);
            return *this;
        }
        ~maze(){Clear();}
        void Clear(){
            for (int i = 0; i<Row; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix=nullptr;
            Col = Row = 0;
        }

        void get(ostream& out){
            out<<"�������� �������� "<<Col<<" x "<<Row<<":\n";
            for(int i = 0; i<Row; i++){
                for (int j = 0; j<Col; j++){
                    if (isdigit(matrix[i][j]))
                        cout<< "\033[;90m"<<matrix[i][j]<< "\033[0m"<<" ";
                    else if ((matrix[i][j]) == '$')
                        cout<< "\033[33m"<<matrix[i][j]<< "\033[0m"<<" ";
                    else
                        cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        };
        void setS(int _x,int _y){
            Col = _x;
            Row = _y;
            matrix = new char * [Row];
            for (int i = 0; i<Row; i++){
                matrix[i] = new char [Col];
            }
            //���� ���������� ����
            for(int i = 0; i<Row; i++){
                for (int j = 0; j<Col; j++){
                    matrix[i][j] = 'H'; 
                }
            }
            //�������� ���������� ����
            for(int i = 1; i<Row-1; i++){
                for (int j = 1; j<Col-1; j++){
                    if (i%2 == 0 || j%2 == 0){
                        matrix[i][j] = 'X';
                    }
                    else{
                        matrix[i][j] = ' ';
                    }
                }
            }
        }
        void setCords(){
            for(int i = 1; i<Row-1; i++){
                for (int j = 1; j<Col-1; j++){
                    cin>>matrix[i][j];
                }
            }
        }
        //void getS(){return Col;}
        //�������� ���������
        void set_Northeast_alg(){

            srand(time(0));
            for(int i = 1; i<Row-1; i+=2){
                for (int j = 1; j<Col-1; j+=2){
                    int a = rand()%2;
                    if ((a || matrix[i-1][j] == 'H') && matrix[i][j+1] != 'H'){
                        matrix[i][j+1] = ' ';
                    }
                    else{
                        matrix[i-1][j] = ' ';
                    }
                }
            }
            for(int i = 1; i<Row; i++){
                for (int j = 1; j<Col; j++){
                    if (i == 0 || j == 0 || i == Col-1 || j == Row-1)
                        matrix[i][j] = 'H';
                }
            }
        };
        void set_Westeast_alg(){
            srand(time(0));
            for(int i = 1; i<Row-1; i+=2){
                for (int j = 1; j<Col-1; j+=2){
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
            
            //matrix[Col-2][Row-2] = -1;
            matrix[0][1] = 'H';
        };
        void set_Sidewinder_alg(){
            srand(time(0));
            for(int i = 1; i<Row-1; i+=2){
                if (i == 1){
                    for (int j = 1; j<Col-1; j+=2){
                        matrix[i][j+1] = ' ';
                    }
                }
                else{
                    int start = 1;
                    while(start<Col){
                        
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
            for(int i = 1; i<Row; i++){
                for (int j = 1; j<Col; j++){
                    if (i == 0 || j == 0 || i == Col-1 || j == Row-1)
                        matrix[i][j] = 'H';
                }
            }
        };



        //�������

        int heuristic(const Point& a, const Point& b) {
            return abs(a.x - b.x) + abs(a.y - b.y);
        }

        void A_star() {
            Point start(1, 1);
            Point end(Col - 2, Row - 2);
            int rows = Row;
            int cols = Col;
            int visitedCount = 0;
            // ������� ��� �������� ���������� ������ � ����������
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));

            // ������������ ������� ��� ���������� A* (����������� ����)
            priority_queue<pair<int, Point>, vector<pair<int, Point>>, greater<pair<int, Point>>> pq;

            // ��������� �����
            pq.push({0, start});
            visited[start.x][start.y] = true;
            distance[start.x][start.y] = 0;

            // ������� ��� ����������� ����������� ��������: �����, ����, �����, ������
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            // A* �����
            while (!pq.empty()) {
                // ��������� ������� ����� � ����������� ����������
                auto current = pq.top();
                pq.pop();
                matrix[current.second.x][current.second.y] = distance[current.second.x][current.second.y]%10 + '0';
                // ���������, �������� �� �� �������� �����
                if (current.second.x == end.x && current.second.y == end.y) {
                    // ������� ���������� �� �������� �����
                    //cout << "����������� ���������� �� �������� �����: " << distance[end.x][end.y] << endl;
                    // ��������������� ����
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

                // �������� ������� ����� ��� ����������
                visited[current.second.x][current.second.y] = true;
                visitedCount++;
                // ��������� ������� ������� �����
                for (int i = 0; i < 4; i++) {
                    int newX = current.second.x + dx[i];
                    int newY = current.second.y + dy[i];

                    // �������� �� ������������ ����� �����
                    if (isValid(newX, newY) && !visited[newX][newY]) {
                        // ��������� ����� ��������� ����
                        int newCost = distance[current.second.x][current.second.y] + 1;

                        // ���� ����� ��������� ������ �������, ��������� ���������� � ��������� ����� � �������
                        if (newCost < distance[newX][newY]) {
                            distance[newX][newY] = newCost;
                            pq.push({newCost + heuristic(Point(newX, newY), end), Point(newX, newY)});
                        }
                    }
                }
            }
            cout<<"��������: "<<visitedCount<<"\n";
        }



        void DFS(){
            Point start(1, 1);
            Point end(Col - 2, Row - 2);
            int rows = Row;
            int cols = Col;
            int visitedCount = 0;
            // ������ ��� �������� ���������� ������
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            // ������ ��� �������� ���������� �� ������ �������
            vector<vector<int>> distance(rows, vector<int>(cols, 0));

            // ���� ��� ���������� DFS
            stack<Point> stk;

            // ��������� �������
            stk.push(start);
            visited[start.x][start.y] = true;

            // ������� ��� ����������� ����������� ��������: �����, ����, �����, ������
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            // DFS
            while (!stk.empty()) {
                Point current = stk.top();
                stk.pop();
                matrix[current.x][current.y] = distance[current.x][current.y]%10 + '0';

                // ���������, �������� �� �������� �������
                if (current.x == end.x && current.y == end.y) {
                    break;
                }

                // ��������� ������� ������� �������
                for (int i = 0; i < 4; i++) {
                    int newX = current.x + dx[i];
                    int newY = current.y + dy[i];

                    // �������� �� ������������ ����� �������
                    if (isValid(newX, newY) && !visited[newX][newY]) {
                        // �������� ������� ��� ����������
                        visited[newX][newY] = true;

                        // ������������� ���������� �� ����� �������
                        distance[newX][newY] = distance[current.x][current.y] + 1;

                        // ��������� ����� ������� � ����
                        stk.push(Point(newX, newY));
                        visitedCount++;
                    }
                }
            }

            // ������� ���������� �� �������� �������
            cout << "����������� ���������� �� �������� �����: " << distance[end.x][end.y] << endl;

            // ��������������� ����
            int x = end.x, y = end.y;
            while (x != start.x || y != start.y) {
                matrix[x][y] = '$'; // ������ ����������� ����
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
                // �������� ������� ����������� �����������
                if (!found) {
                    cout << "������: ��� ����������� �����������!" << endl;
                    break;
                }
            }
            cout<<"��������: "<<visitedCount<<"\n";
        }



        int BFS() {
            Point start(1,1);
            Point end(Col-2,Row-2);
            int rows = Row;
            int cols = Col;
            int visitedCount = 0;
            // ������� ��� �������� ���������� ������ � ����������
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            vector<vector<int>> distance(rows, vector<int>(cols, 0));

            // ���������� ��� �������� ��������� ������� �������
            int currentX, currentY;

            // ������� ��� ���������� BFS
            queue<Point> q;

            // ��������� �������
            q.push(start);
            visited[start.x][start.y] = true;
            distance[start.x][start.y] = 0;

            // ������� ��� ����������� ����������� ��������: �����, ����, �����, ������
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            // BFS
            while (!q.empty()) {
                // ��������� ������� �� �������
                Point current = q.front();
                //���� �� ����� ����������� ����� � ������ �� ���
                matrix[current.y][current.x] = distance[current.y][current.x] % 10 + '0';
                q.pop();
                currentX = current.x;
                currentY = current.y;

                // ��������� ������� ������� �������
                for (int i = 0; i < 4; i++) {
                    int newY = currentY + dy[i];
                    int newX = currentX + dx[i];

                    // �������� �� ������������ ����� �������
                    if (isValid(newX, newY) && !visited[newY][newX]) {
                        // �������� ������� ��� ����������
                        visited[newY][newX] = true;
                        // ������������� ���������� �� ����� �������
                        distance[newY][newX] = distance[currentY][currentX] + 1;
                        // ��������� ����� ������� � �������
                        q.push(Point(newY, newX));
                        visitedCount++;
                    }
                }
            }
            // ������� ���������� �� �������� �������
            //cout << "����������� ���������� �� �������� �����: " << distance[end.x][end.y] << endl;
            // ��������������� ����
            //cout << "���� �� ��������� ����� �� �������� �����:" << endl;
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
                // �������� ������� ����������� �����������
                if (!found) {
                    cout << "������: ��� ����������� �����������!" << endl;
                    break;
                }
            }
            cout<<"��������: "<<visitedCount<<"\n";
            return visitedCount;
        }


        bool isValid(int _x, int _y) {
            return (_x >= 0 && _x < Col && _y >= 0 && _y < Row && (matrix[_x][_y] !='X' && matrix[_x][_y] !='H')); //!visited[_x][_y]);
        }

};

#endif //MAZE_H