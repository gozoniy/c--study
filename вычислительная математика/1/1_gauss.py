a =     [[5.401, 0.519, 0.364, 0.283],
          [0.295, 4.830, 0.421, 0.278],
          [0.524, 0.397, 4.723, 0.389],
          [0.503, 0.264, 0.248, 4.286]] 
b = [0.243, 0.231, 0.721, 0.220]

n = 4

for k in range(n-1):
    max_index = k
    max_value = a[k][k]
    for i in range(k+1, n):
        if a[i][k] > max_value:
            max_index = i
            max_value = a[i][k]
            
    a[k], a[max_index] = a[max_index], a[k]
    b[k], b[max_index] = b[max_index], b[k]

    for i in range(k+1,n):
        koef = -a[i][k]/a[k][k]
        for j in range(k,n):
            a[i][j] += koef * a[k][j]
        b[i] += koef * b[k]

x = [0] * n

for k in range(n-1, -1, -1):
    x[k] = b[k]
    for i in range(k+1, n):
        x[k] -= a[k][i] * x[i]
    x[k] /= a[k][k]

for i in range(n):
    print("x[",i,"] =",x[i])

summa = 0
for i in range(n):
    summa += x[i] * a[1][i]
print(summa, "=",b[1])
