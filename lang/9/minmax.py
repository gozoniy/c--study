def minmax(X):
    minP = 10000000000
    maxO = -10000000000
    for i in X:
        if i > 0:
            minP = min(minP,i)
        elif i < 0:
            maxO = max(maxO,i)
    return (minP,maxO)