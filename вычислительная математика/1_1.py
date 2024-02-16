def skal(vec1, vec2):
    return sum(x * y for x, y in zip(vec1, vec2))

def simple_iteration(A, b, x0, tol=1e-6, max_iter=1000):
    """
    Решение системы линейных уравнений Ax = b методом простой итерации (методом Якоби).
    
    Параметры:
        A (list[list]): Матрица системы уравнений.
        b (list): Вектор правой части системы уравнений.
        x0 (list): Начальное приближение.
        tol (float): Допустимая погрешность.
        max_iter (int): Максимальное количество итераций.
        
    Возвращает:
        x (list): Приближенное решение системы уравнений.
        num_iter (int): Количество выполненных итераций.
    """
    n = len(b)
    x = x0[:]
    for k in range(max_iter):
        x_new = [0] * n
        for i in range(n):
            s = skal(A[i], x) - A[i][i] * x[i]
            x_new[i] = (b[i] - s) / A[i][i]
        if max(abs(x_new[i] - x[i]) for i in range(n)) < tol:
            return x_new, k + 1
        x = x_new
    return x, max_iter

# Пример использования:
A = [[4, -1, 0], [-1, 4, -1], [0, -1, 3]]
b = [5, -4, 0]
x0 = [0, 0, 0]

x, num_iter = simple_iteration(A, b, x0)
print("Приближенное решение:", x)
print("Количество итераций:", num_iter)