X = [0.172,0.497,0.821,1.146,1.470,1.795,2.120,2.444,2.769]
F = [0.400,-1.935,-1.208,0.169,0.742,0.020,-1.534,-2.489,-0.464]
#порядок
p = 4
#матрица коэффициентов A и вектор b
A = []
for i in range(p + 1):
    row = [sum(x ** j for x in X) for j in range(i, i + p + 1)]
    A.append(row)
#вектор b
b = [sum((x ** i) * f for x, f in zip(X, F)) for i in range(p + 1)]
#метод Гаусса
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
coefficients = gauss_elimination(A, b)
print("F(x) =", coefficients)

coefficients = [3.99079456041993, -27.225918803629533, 40.457149547962864, -21.236275550898203, 3.599346821124913]  

# Значения xi и f(xi)
X = [0.172,0.497,0.821,1.146,1.470,1.795,2.120,2.444,2.769]
F = [0.400,-1.935,-1.208,0.169,0.742,0.020,-1.534,-2.489,-0.464]