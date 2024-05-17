import sympy as sp

# Определение переменной и функции
x = sp.symbols('x')
f = x * sp.sin(x)

# Вычисление точного значения интеграла
exact_value = sp.integrate(f, (x, 0, 1.6))
exact_value = exact_value.evalf()  # Получение численного значения

print("Точное значение интеграла:", exact_value)