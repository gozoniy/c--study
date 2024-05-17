import math

# Определение функции f(x)
def f(x):
    return math.exp(-0.3 * x**2) - math.sqrt(x) + 1

# Производная функции f(x)
def df(x):
    return -0.6 * x * math.exp(-0.3 * x**2) - 0.5 / math.sqrt(x)

# Начальное приближение
x_prev = 1.5
# Требуемая точность
epsilon = 0.01

# Итерационный процесс метода Ньютона
while True:
    # Значение функции в текущем приближении
    f_val = f(x_prev)
    # Значение производной функции в текущем приближении
    df_val = df(x_prev)
    # Новое приближение корня
    x_next = x_prev - f_val / df_val
    
    # Проверка условия окончания итераций
    if abs(x_next - x_prev) < epsilon:
        break
    
    # Обновление текущего приближения
    x_prev = x_next
    print(x_next)
# Вывод результата
print("Приближенное значение корня:", x_next)
