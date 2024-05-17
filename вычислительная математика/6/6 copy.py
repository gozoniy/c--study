import matplotlib.pyplot as plt
import math
# Определим функцию f(t, u)
def f(t, u):
    return 0.5 * (t + 1) * (2.718281828459045**(-1)) * u**2 - t * u
    return (u**(2))*math.log(t)

# Точное решение (для сравнения)
def exact_solution(t):
    from scipy.integrate import solve_ivp
    sol = solve_ivp(lambda t, u: f(t, u), [0, 2], [2], t_eval=t)
    return sol.y[0]

# Метод Эйлера
def euler_method(a, T, u0, f, epsilon):
    N = 2
    while True:
        tau = (T - a) / N
        t_values = [a + i * tau for i in range(N + 1)]
        u_values = [u0]
        for n in range(N):
            u_next = u_values[-1] + tau * f(t_values[n], u_values[-1])
            u_values.append(u_next)
        t_half_values = [a + i * 2 * tau for i in range(N // 2 + 1)]
        u_half_values = [u0]
        for n in range(N // 2):
            u_next = u_half_values[-1] + 2 * tau * f(t_half_values[n], u_half_values[-1])
            u_half_values.append(u_next)
        delta = max(abs(u_values[2 * n] - u_half_values[n]) for n in range(N // 2 + 1)) / 3
        if delta < epsilon:
            return t_values, u_values, N
        N *= 2

# Метод Рунге-Кутты 4-го порядка
def runge_kutta_method(a, T, u0, f, epsilon):
    N = 2
    while True:
        tau = (T - a) / N
        t_values = [a + i * tau for i in range(N + 1)]
        u_values = [u0]
        for n in range(N):
            t = t_values[n]
            u = u_values[-1]
            k1 = tau * f(t, u)
            k2 = tau * f(t + 0.5 * tau, u + 0.5 * k1)
            k3 = tau * f(t + 0.5 * tau, u + 0.5 * k2)
            k4 = tau * f(t + tau, u + k3)
            u_next = u + (1/6) * (k1 + 2 * k2 + 2 * k3 + k4)
            u_values.append(u_next)
        t_half_values = [a + i * 2 * tau for i in range(N // 2 + 1)]
        u_half_values = [u0]
        for n in range(N // 2):
            t = t_half_values[n]
            u = u_half_values[-1]
            k1 = 2 * tau * f(t, u)
            k2 = 2 * tau * f(t + 0.5 * 2 * tau, u + 0.5 * k1)
            k3 = 2 * tau * f(t + 0.5 * 2 * tau, u + 0.5 * k2)
            k4 = 2 * tau * f(t + 2 * tau, u + k3)
            u_next = u + (1/6) * (k1 + 2 * k2 + 2 * k3 + k4)
            u_half_values.append(u_next)
        delta = max(abs(u_values[2 * n] - u_half_values[n]) for n in range(N // 2 + 1)) / 15
        if delta < epsilon:
            return t_values, u_values, N
        N *= 2

# Параметры задачи
a, T, u0, epsilon = 1, 5, 0.5, 1e-3

# Решение методом Эйлера
t_values_euler, u_values_euler, N_euler = euler_method(a, T, u0, f, epsilon)
print(f"Метод Эйлера: N = {N_euler}")

# Решение методом Рунге-Кутты 4-го порядка
t_values_rk, u_values_rk, N_rk = runge_kutta_method(a, T, u0, f, epsilon)
print(f"Метод Рунге-Кутты: N = {N_rk}")

# Точное решение для сравнения
t_exact = t_values_euler  # Используем сетку из метода Эйлера
u_exact = exact_solution(t_exact)

# Построение графиков
plt.figure(figsize=(10, 6))
plt.plot(t_exact, u_exact, label="Точное решение")
plt.plot(t_values_euler, u_values_euler, label="Метод Эйлера", linestyle="--")
plt.plot(t_values_rk, u_values_rk, label="Метод Рунге-Кутты", linestyle=":")
plt.xlabel("t")
plt.ylabel("u(t)")
plt.title("Сравнение точного и численных решений")
plt.legend()
plt.grid()
plt.show()

# Оценка ошибок
error_euler = max(abs(u - u_exact[i]) for i, u in enumerate(u_values_euler))
error_rk = max(abs(u - u_exact[i]) for i, u in enumerate(u_values_rk))
print(f"Максимальное расхождение у Эйлера: {error_euler}")
print(f"Максимальное расхождение у Рунге-Кутты: {error_rk}")
