def isArm(n):
    digits = list(map(int, str(n)))
    l = len(digits)
    S = 0
    for i in digits:
        S += i**l
    return S == n
