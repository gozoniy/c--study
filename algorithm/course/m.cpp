#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

//#include "maze.cpp"




const int MAX_N = 100;
vector<vector<char>> maze(MAX_N, vector<char>(MAX_N));
vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_N, false));
int N, M; // Размеры лабиринта

// Функция для проверки валидности хода в лабиринте
bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] != '#' && !visited[x][y]);
}

// Функция для выполнения DFS
void DFS(int x, int y) {
    // Массив смещений для соседних клеток
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Помечаем текущую клетку как посещённую
    visited[x][y] = true;

    // Проверяем соседние клетки
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY)) {
            DFS(newX, newY);
        }
    }
}

int main() {
    system("chcp 1251");
    // Ввод размеров лабиринта
    cin >> N >> M;

    // Ввод самого лабиринта
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> maze[i][j];
        }
    }

    // Начальная позиция
    int startX, startY;
    cin >> startX >> startY;

    // Запуск DFS с начальной позиции
    DFS(startX, startY);

    // Дополнительные действия после завершения DFS
    // Например, проверка на достижимость определённой клетки

    return 0;
}