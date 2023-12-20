def minmax(X):
    P = sum([float(x) for x in X if x>0])
    O = sum([float(x) for x in X if x<0])
    return (min(P),max(O))