from minmax import *
if __name__ == "__main__":
    X = list(map(float,input().split()))
    minP,maxO = minmax(X)
    print("Минимальный элемент среди положительных:", minP)
    print("Максимальный элемент среди отрицательных:", maxO)