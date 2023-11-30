from armstrong import *

if __name__ == "__main__":
    k = int(input())
    answ = ''
    for i in range(1,k+1):
        if isArm(i):
            answ+=str(i)+' '
    print("Числа Армстронга:")
    print(answ)
        