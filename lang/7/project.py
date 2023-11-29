while (True):
    def yk(k):
        if k == 0:
            return 1
        else:
            Y = (yk(k-1)+1)/yk(k-1)+2
            return Y

    if __name__ == "__main__":
        E = float(input())
        flag = True
        n = 1
        while flag:
            if yk(n) - yk(n-1) < E:
                print("Неравенство выполнено для:",yk(n))
                break
            else:
                n+=1



