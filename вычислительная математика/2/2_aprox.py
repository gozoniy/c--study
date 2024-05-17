# Заданные данные
x_values = [0.084, 0.447, 0.810, 1.173, 1.536, 1.898, 2.261, 2.624, 2.987]
f_values = [0.224, -2.255, -1.490, -0.082, 0.452, -0.320, -1.756, -2.125, 1.385]

# Порядок многочлена
p = 4

# Создаем матрицу коэффициентов A и вектор b
A = []
for i in range(p + 1):
    row = [sum(x ** j for x in x_values) for j in range(i, i + p + 1)]
    A.append(row)

# Создаем вектор b
b = [sum((x ** i) * f for x, f in zip(x_values, f_values)) for i in range(p + 1)]

# Решение системы уравнений методом Гаусса
def gauss_elimination(A, b):
    n = len(b)
    for i in range(n):
        max_row = i
        for j in range(i + 1, n):
            if abs(A[j][i]) > abs(A[max_row][i]):
                max_row = j
        A[i], A[max_row] = A[max_row], A[i]
        b[i], b[max_row] = b[max_row], b[i]
        for j in range(i + 1, n):
            factor = A[j][i] / A[i][i]
            for k in range(i, n):
                A[j][k] -= factor * A[i][k]
            b[j] -= factor * b[i]
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = b[i]
        for j in range(i + 1, n):
            x[i] -= A[i][j] * x[j]
        x[i] /= A[i][i]
    return x
print(A)
# Решение системы уравнений
coefficients = gauss_elimination(A, b)

# Вывод результатов
print("Коэффициенты многочлена F(x) =", coefficients)
