import math

# Функция под интегралом
def f(x):
    return x*math.sin(x)

# Функция для расчета трапеций
def trapezoidal_rule(f, a, b, N):
    tau = (b - a) / N
    integral = (f(a) + f(b)) / 2  # первые и последние точки
    for i in range(1, N):
        t = a + i * tau
        integral += f(t)
    integral *= tau
    return integral

# Функция для расчета методом Симпсона
def simpsons_rule(f, a, b, N):
    if N % 2 == 1:
        N += 1  # Симпсон требует четное число сегментов
    tau = (b - a) / N
    integral = f(a) + f(b)
    for i in range(1, N, 2):
        t = a + i * tau
        integral += 4 * f(t)
    for i in range(2, N, 2):
        t = a + i * tau
        integral += 2 * f(t)
    integral *= tau / 3
    return integral

# Точное значение интеграла
import math
exact_value = 1.04629283872357

# Заданная точность
epsilon = 0.001
max_nodes = 100  # максимальное количество узлов

# Поиск значения N, при котором метод трапеций достигает точности epsilon
N_trap = 2
errors_trap = []
error_trap = float('inf')
mas = []
mas.append(exact_value)

while error_trap > epsilon and N_trap <= max_nodes:
    approx_value_trap = trapezoidal_rule(f, 0, 1.6, N_trap)
    mas.append(approx_value_trap)
    error_trap = abs(mas[N_trap-2] - approx_value_trap)
    errors_trap.append((N_trap, error_trap))
    N_trap += 1

if error_trap > epsilon:
    print("Заданная точность методом трапеций не достигнута с максималь-ным количеством узлов.")
else:
    print("Абсолютные погрешности метода трапеций:")
    for N, error in errors_trap:
        print(f"N = {N}, Ошибка = {error:.6f}")

    del(mas[0])
    for i in mas:
        print(f"Значение = {i}")
    print(f"\nN, при котором метод трапеций достиг точности {epsilon}: {N_trap-1}")

# Поиск значения N, при котором метод Симпсона достигает точности epsi-lon
N_simp = 2
errors_simp = []
error_simp = float('inf')
mas = []
mas.append(exact_value)
count = 2

while error_simp > epsilon and N_simp <= max_nodes:
    approx_value_simp = simpsons_rule(f, 0, 1.6, N_simp)
    mas.append(approx_value_simp)
    error_simp = abs(mas[count-2] - approx_value_simp)
    errors_simp.append((N_simp, error_simp))
    N_simp += 2
    count +=1

    
if error_simp > epsilon:
    print("Заданная точность методом Симпсона не достигнута с максималь-ным количеством узлов.")
else:
    print("\nАбсолютные погрешности метода Симпсона:")
    for N, error in errors_simp:
        print(f"N = {N}, Ошибка = {error:.6f}")

    del(mas[0])
    for i in mas:
        print(f"Значение = {i}")

    print(f"\nN, при котором метод Симпсона достиг точности {epsilon}: {N_simp-2}")
