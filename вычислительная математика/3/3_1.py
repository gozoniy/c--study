import numpy as np
import matplotlib.pyplot as plt
import math

# Определение функции f(x)
def f(x):
    return 3 - 0.5 * x**0.5 - math.exp(-0.5 * x**2)

# Создание массива значений x
x_values = np.linspace(0, 3, 400)
# Вычисление значений функции f(x)
y_values = [f(x) for x in x_values]

# Построение графика функции f(x)
plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values, label='f(x)')
#plt.axhline(0, color='black', linewidth=0.5)  # Ось x
#plt.axvline(0, color='black', linewidth=0.5)  # Ось y
plt.title('График функции f(x)')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid(True)
plt.legend()
plt.show()
