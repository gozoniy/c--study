def yk(k):
    if k == 0:
        return 1
    else:
        Y = (yk(k-1)+1)/(yk(k-1)+2)
        return Y

if __name__ == "__main__":
    while True:
        E = float(input("Введите E: "))
        n = 1
        while True:
            A = abs(yk(n) - yk(n-1))
            if  A < E:
                print("Неравенство выполнено для:",yk(n))
                break
            else:
                n+=1
