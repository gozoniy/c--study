import matplotlib.pyplot as plt
# Функция для вычисления значения многочлена F(x) для данного x
def F(x, coefficients):
    result = 0
    for i, coef in enumerate(coefficients):
        result += coef * x**i
    return result
coefficients = [3.99079456041993, -27.225918803629533, 40.457149547962864, -21.236275550898203, 3.599346821124913]
x_values = [0.172,0.497,0.821,1.146,1.470,1.795,2.120,2.444,2.769]
f_values = [0.400,-1.935,-1.208,0.169,0.742,0.020,-1.534,-2.489,-0.464]
# Вычисление значений F(x) для всех точек данных xi
F_values = [F(x, coefficients) for x in x_values]
# Поиск невязок
n = len(f_values)
for i in  range (n):
    print("r[",i,"] =",F_values[i]-f_values[i])
    
plt.plot(x_values, f_values, 'bo-', label='Табличная функция f(x)')
plt.plot(x_values, F_values, 'r^-', label='Многочлен F(x)')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)
plt.show()
