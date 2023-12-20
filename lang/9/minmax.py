def minmax(X):
    P = min([float(x) for x in X if x>0])
    O = max([float(x) for x in X if x<0])
    return (P,O)