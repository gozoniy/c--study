def gauss_elimination(A, B):
    n = len(B) #кол-во столбцов матрицы А
    for i in range(n):
        #Поиск индекса максимального элемента в столбце
        max_index = i
        for j in range(i+1, n):
            if abs(A[j][i]) > abs(A[max_index][i]):
                max_index = j
        
        #Обмен строк по максимальному индексу
        A[i], A[max_index] = A[max_index], A[i]
        B[i], B[max_index] = B[max_index], B[i]
        
        #Приведение к верхнетреугольному виду
        for j in range(i+1, n):
            #находим множитель
            ratio = A[j][i] / A[i][i]
            for k in range(i, n):
                #вычитаем 
                A[j][k] -= ratio * A[i][k]
            B[j] -= ratio * B[i]
    #Создание матрицы ответа
    X = [0] * n
    for i in range(n - 1, -1, -1):
        X[i] = B[i] / A[i][i]
        for j in range(i - 1, -1, -1):
            B[j] -= A[j][i] * X[i]
    return X

A = [[5.401,0.519,0.364,0.283],
     [0.295,4.830,0.421,0.278],
     [0.524,0.397,4.723,0.389],
     [0.503,0.264,0.248,4.286]]
B = [0.243,0.231,0.721,0.220]
B1 = [[0.243],[0.231],[0.721],[0.220]]
solution = gauss_elimination(A, B)
print("Решение:", solution)
