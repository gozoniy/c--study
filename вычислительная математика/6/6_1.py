import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp
# Задание параметров
a = 1
T = 2
u0 = 1
epsilon = 1e-3

# Функция для задачи Коши
def f(t, u):
    return (u**2 * np.log(t) - u) / t
# Точное решение
def exact_solution(t):
    sol = solve_ivp(f, [a, T], [u0], t_eval=t, method='RK45', rtol=1e-10, atol=1e-10)
    return sol.y[0]
# Метод Эйлера
def euler_method(a, T, u0, N):
    tau = (T - a) / N
    t_values = np.linspace(a, T, N + 1)
    u_values = np.zeros(N + 1)
    u_values[0] = u0
    for n in range(N):
        u_values[n + 1] = u_values[n] + tau * f(t_values[n], u_values[n])
    return t_values, u_values
# Метод Рунге-Кутты 4-го порядка
def runge_kutta_method(a, T, u0, N):
    tau = (T - a) / N
    t_values = np.linspace(a, T, N + 1)
    u_values = np.zeros(N + 1)
    u_values[0] = u0
    for n in range(N):
        k1 = tau * f(t_values[n], u_values[n])
        k2 = tau * f(t_values[n] + tau/2, u_values[n] + k1/2)
        k3 = tau * f(t_values[n] + tau/2, u_values[n] + k2/2)
        k4 = tau * f(t_values[n] + tau, u_values[n] + k3)
        u_values[n + 1] = u_values[n] + (k1 + 2*k2 + 2*k3 + k4) / 6
    return t_values, u_values
# Функция для нахождения N с заданной точностью
def find_optimal_N(method, epsilon):
    N = 2
    while True:
        t_values, u_values = method(a, T, u0, N)
        t_values_2, u_values_2 = method(a, T, u0, 2 * N)
        delta = max(abs(u_values_2[::2] - u_values))
        if delta < epsilon:
            break
        N *= 2
    return N, t_values, u_values
# Нахождение оптимального N для метода Эйлера
N_euler, t_values_euler, u_values_euler = find_optimal_N(euler_method, epsilon)
print(f"Оптимальное N для метода Эйлера: {N_euler}")
# Нахождение оптимального N для метода Рунге-Кутты
N_rk, t_values_rk, u_values_rk = find_optimal_N(runge_kutta_method, epsilon)
print(f"Оптимальное N для метода Рунге-Кутты: {N_rk}")
# Вычисление точного решения
t_exact = np.linspace(a, T, 1000)
u_exact = exact_solution(t_exact)
# Интерполяция численных решений для сравнения с точным решением
u_euler_interp = np.interp(t_exact, t_values_euler, u_values_euler)
u_rk_interp = np.interp(t_exact, t_values_rk, u_values_rk)
# Вычисление максимального расхождения
max_diff_euler = np.max(np.abs(u_exact - u_euler_interp))
max_diff_rk = np.max(np.abs(u_exact - u_rk_interp))
print(f"Максимальное расхождение для метода Эйлера: {max_diff_euler}")
print(f"Максимальное расхождение для метода Рунге-Кутты: {max_diff_rk}")
# Построение графиков
plt.figure(figsize=(12, 6))
plt.plot(t_exact, u_exact, label="Точное решение", linewidth=2)
plt.plot(t_values_euler, u_values_euler, 'o-', label="Метод Эйлера")
plt.plot(t_values_rk, u_values_rk, 's-', label="Метод Рунге-Кутты")
plt.xlabel("t")
plt.ylabel("u(t)")
plt.legend()
plt.title("Сравнение точного и численных решений задачи Коши")
plt.grid(True)
plt.show()
