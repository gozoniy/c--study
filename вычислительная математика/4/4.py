import math
#Заданная функция
def f(t):
    return (3+2*t**(1/2))**(-1/2)
n = 10  # Количество узлов
h = 1 / n  # Шаг
# Значения функции в узлах
t = [i * h for i in range(n + 1)]
f_values = [f(x) for x in t]

f_values2 = []
for i in range (1,len(f_values)):
    f_values2.append((f_values[i]+f_values[i-1])/2)
print(f_values2)
print("Значения функции в узлах:", f_values)

# Вычисление разделённых разностей для всех порядков
def calculate_divided_differences(f_vals, h):
    n = len(f_vals)
    div_diffs = [f_vals]  # Нулевой порядок - исходные значения
    for order in range(1, n):
        previous_order = div_diffs[-1]
        current_order = [
            (previous_order[i + 1] - previous_order[i]) / (order * h)
            for i in range(n - order)
        ]
        div_diffs.append(current_order)
    return div_diffs
# Все разделённые разности до n-го порядка
div_diffs = calculate_divided_differences(f_values, h)

print("Разделённые разности:")
for i, diff in enumerate(div_diffs):
    print(f"Порядок {i}: {diff}")
# Интерполяционный многочлен Ньютона
def newton_polynomial(t, f_vals, div_diffs):
    n = len(f_vals) - 1
    result = f_vals[0]
    term = 1
    for i in range(1, n + 1):
        term *= (t - (i - 1) * h)
        result += div_diffs[i][0] * term
    return result

# Полуцелые узлы
half_nodes = [(j - 0.5) * h for j in range(1, n + 1)]
# Значения интерполяционного многочлена Ньютона в полуцелых узлах
N_vals = [newton_polynomial(t_half, f_values, div_diffs) for t_half in half_nodes]
print("Значения интерполяционного многочлена Ньютона в полуцелых уз-лах:", N_vals)
# Погрешность интерполирования в полуцелых узлах
errors = [abs(f(half_nodes[j]) - N_vals[j]) for j in range(n)]

print("Погрешность интерполирования в полуцелых узлах:", errors)
# Максимальная погрешность
max_error = max(errors)
# Среднеквадратичная погрешность
mse = math.sqrt(sum([err**2 for err in errors]) / n)
print("Максимальная погрешность:", max_error)
print("Среднеквадратичная погрешность:", mse)

print("\n")

f_values2 = []
for i in range (1,len(f_values)):
    f_values2.append((f_values[i]+f_values[i-1])/2)

print("Значения функции в узлах:", f_values2)

div_diffs = calculate_divided_differences(f_values2, h)
print("Разделённые разности:")
for i, diff in enumerate(div_diffs):
    print(f"Порядок {i}: {diff}")
# Полуцелые узлы
half_nodes = [(j - 0.5) * h for j in range(1, n + 1)]
# Значения интерполяционного многочлена Ньютона в полуцелых узлах
N_vals = [newton_polynomial(t_half, f_values2, div_diffs) for t_half in half_nodes]
print("Значения интерполяционного многочлена Ньютона в полуцелых уз-лах:", N_vals)
# Погрешность интерполирования в полуцелых узлах
errors = [abs(f(half_nodes[j]) - N_vals[j]) for j in range(n)]
print("Погрешность интерполирования в полуцелых узлах:", errors)
# Максимальная погрешность
max_error = max(errors)
# Среднеквадратичная погрешность
mse = math.sqrt(sum([err**2 for err in errors]) / n)
print("Максимальная погрешность:", max_error)
print("Среднеквадратичная погрешность:", mse)
