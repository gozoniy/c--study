#ifndef MAZE_H
#define MAZE_H

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

class maze{
        int sX,sY;
        int **matrix;   //2 - ������� �����, 1 - ���������� �����, 0 - ������ ������
        int **visited;
    public:
        maze() : sX(0), sY(0), matrix(nullptr),visited(nullptr){}
        maze(int X,int Y) : sX(X),sY(Y),matrix(new int * [sX]){
            for (int i = 0; i<sX; i++){
                matrix[i] = new int [sY];
            }
            //���� ���������� ����
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    matrix[i][j] = 2; 
                }
            }
            //�������� ���������� ����
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
            out<<"�������� �������� "<<sX<<" x "<<sY<<":\n";
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
            //���� ���������� ����
            for(int i = 0; i<sX; i++){
                for (int j = 0; j<sY; j++){
                    matrix[i][j] = 2; 
                }
            }
            //�������� ���������� ����
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
        //�������� ���������
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

        //������� ���������
        void A_star(){
            int f = 1;
            //��������� x y:
            int x = 1;
            int y = 1;
            int cost = 0;
            cout<<"("<<x<<","<<y<<")\n";
            while(f){
                if (matrix[y][x] == 9){
                    cout<<"���� ������.\n";
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
            //��������� x y:
            int x = 1;
            int y = 1;
            int cost = 0;
            cout<<"("<<x<<","<<y<<")\n";
            while(f){
                if (matrix[y][x] == 9){
                    cout<<"���� ������.\n";
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
                matrix[current.x][current.y] = 3;
                q.pop();
                currentX = current.x;
                currentY = current.y;

                // ��������� ������� ������� �������
                for (int i = 0; i < 4; i++) {
                    int newX = currentX + dx[i];
                    int newY = currentY + dy[i];

                    // �������� �� ������������ ����� �������
                    if (isValid(newX, newY) && !visited[newX][newY]) {
                        // �������� ������� ��� ����������
                        visited[newX][newY] = true;
                        // ������������� ���������� �� ����� �������
                        distance[newX][newY] = distance[currentX][currentY] + 1;
                        // ��������� ����� ������� � �������
                        q.push(Point(newX, newY));
                    }
                }
            }
            get(cout);
            // ������� ���������� �� �������� �������
            cout << "����������� ���������� �� �������� �����: " << distance[end.x][end.y] << endl;

            // ��������������� ����
            cout << "���� �� ��������� ����� �� �������� �����:" << endl;
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
                // �������� ������� ����������� �����������
                if (!found) {
                    cout << "������: ��� ����������� �����������!" << endl;
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