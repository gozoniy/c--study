def simple_it(A, b, initial_guess, max_iterations=100, tolerance=0.000001):
    n = len(b)
    x_prev = initial_guess.copy()
    for iteration in range(max_iterations):
        x_next = [0] * n #хранение следующего приближ
        for i in range(n):
            #вычисление следующего приближ для вектора
            sigma = 0
            for j in range(n):
                if j != i:
                    sigma += A[i][j] * x_prev[j]
            x_next[i] = (b[i] - sigma) / A[i][i]
        #проверка сходимости
        norm_diff = sum((x_next[i] - x_prev[i])**2 for i in range(n)) ** 0.5
        if norm_diff < tolerance:
            return x_next, iteration + 1
        x_prev = x_next
A =     [[5.401, 0.519, 0.364, 0.283],
          [0.295, 4.830, 0.421, 0.278],
          [0.524, 0.397, 4.723, 0.389],
          [0.503, 0.264, 0.248, 4.286]] 
b = [0.243, 0.231, 0.721, 0.220]
initial_guess = [0, 0, 0, 0]
solution, iterations = simple_it(A, b, initial_guess)
print("Решение:", solution)
print("Количество итераций:", iterations)
