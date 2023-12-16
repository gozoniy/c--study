def yk(k):
    if k == 0:
        return 1
    else:
        A = yk(k-1)
        B = yk(k-1)
        Y = (A+1)/(B+2)
        return Y

if __name__ == "__main__":
    E = float(input("Введите E: "))
    n = 1
    while True:
        A = abs(yk(n) - yk(n-1))
        if  A < E:
            print("Неравенство выполнено для:",yk(n))
            break
        else:
            n+=1
