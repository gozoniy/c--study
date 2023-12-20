from minmax import *
if __name__ == "__main__":
    X = list(map(float,input("Введите список: ").split()))
    minP,maxO = minmax(X)
    print("Минимальный элемент среди положительных:", minP)
    print("Максимальный элемент среди отрицательных:", maxO)
    #[:] deepcopy
    #[_ for _ in _ if _]