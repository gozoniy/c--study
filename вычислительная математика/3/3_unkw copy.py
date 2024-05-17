import math
import matplotlib.pyplot as plt

# Определение функции
def f(x):
    return 3-0.5*x**0.5-math.exp(-0.5*x**2)
# Создание списка значений x
x_values = [i/100 for i in range(0, 501)]  # Генерация значений от 0 до 5 с шагом 0.01

# Вычисление значений функции
y_values = [f(x) for x in x_values]

# Построение графика
plt.figure(figsize=(8, 6))
plt.plot(x_values, y_values, label='$f(x) = 3-0,5\sqrt{x}-e^{-0,5x^2}$')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid(True)
plt.legend()
plt.title('График функции f(x)')
plt.show()


# Определение производной функции f(x)
def f_prime(x):
    return (math.exp(-(x**2)/2)*(4*x**(3/2)-math.exp((x**2)/2)))/(4*(x**0.5))

# Определение второй производной функции f(x)
def f_double_prime(x):
    return (math.exp(-(x**2)/2)*((x**0.5)*math.exp((x**2)/2)-8*x**4+8*x**2))/(8*x**2)
# Определение метода Ньютона для вычисления корня
def newton_method(f, f_prime, x_0, epsilon, max_iterations=1000):
    x_prev = x_0
    for _ in range(max_iterations):
        x_next = x_prev - f(x_prev) / f_prime(x_prev)
        if abs(x_next - x_prev) < epsilon:
            return x_next
        x_prev = x_next
    return None
# Локализация интервала и начального приближения
a = 1
b = 2
x_0 = (a + b) / 2
# Проверка условий
if f(a) * f(b) < 0 and f_double_prime(x_0) != 0 and f_prime(x_0) != 0 and f(x_0) * f_double_prime(x_0) > 0:
# Вычисление корня методом Ньютона
    root = newton_method(f, f_prime, x_0, epsilon=0.01)
    print("корень приблизительно равен", root)
    # Проверка 
    print(f(root))
else:
   print("Условия для применения метода Ньютона не выполняются.")


