from random import randint
import numpy as np

matrix_1=[[1, 0, 0, 0, 0,],
          [0, 1, 0, 0, 0,],
          [0, 0, 1, 0, 0,],
          [0, 0, 0, 1, 0,],
          [0, 0, 0, 0, 1]] 

matrix_p=[[1,1,1,1],
          [1,1,1,0],
          [1,1,0,1],
          [1,1,0,0],
          [1,0,1,1]]
          
matrix_h=[[1,1,1,1,1],
          [1,1,1,1,0],
          [1,1,0,0,1],
          [1,0,1,0,1]]

matrix_h_1=[[1,0,0,0],
            [0,1,0,0],
            [0,0,1,0],
            [0,0,0,1]]

matrix_h_for_decode=   [[1,1,1,1],
                        [1,1,1,0],
                        [1,1,0,1],
                        [1,1,0,0],
                        [1,0,1,1]]

def sum_vectors(vec1,vec2):
    sum=[]
    for i in range(len(vec1)):
        sum.append((vec1[i]+vec2[i])%2)
    return sum

def get_codes_with_p(count):
    codes = []
    for i in range(0, count):
        random_codes_without_k = [randint(0, 1) for i in range(5)]
        codes.append(random_codes_without_k)
        vector_0=[0,0,0,0]
        for j in range (len(codes[i])):
            if codes[i][j] ==1:
                vector_0=sum_vectors(vector_0,matrix_p[j])
        for p in vector_0:
            codes[i].append(p)
    return codes

def decode(code):
    flag = 0
    s=[]
    s1 = (code[5] + code[0] + code[1] + code[2] + code[3] + code[4])%2
    s2 = (code[6] + code[0] + code[1] + code[2] + code[3])%2
    s3 = (code[7] + code[0] + code[1] + code[4])%2
    s4 = (code[8] + code[0] + code[2] + code[4])%2
    s.append(s1)
    s.append(s2)
    s.append(s3)
    s.append(s4)
    if s==[0,0,0,0]:
        return 0
    else:
        flag = 1
        for i in range(len(matrix_h_for_decode)):
            k = 1
            if matrix_h_for_decode[i]==s:
                k = 0
                print(f"Обнаружена ошибка в разряде {i+1}.")
                if code[i] == 0:
                    code[i] = 1
                else:
                    code[i] = 0
                print(f"Исправленный код: {code}")
        if k:
            print("Ошибку невозможно исправить (она не в информационной матрице)")
                
    return flag

sw=0
codes=[]
flag = True
while (flag):
    print("Главное меню")
    print("1 Сгенерировать линейно-групповые коды")
    print("2 Проверить коды на ошибки")
    print("3 Изменить бит")
    print("0 Завершить работу")
    sw = int(input())
    match sw:
        case 1:
            print("Введите кол-во кодов:")
            count=int(input())
            codes = get_codes_with_p(count)
            for i in range(len(codes)):
                print(f"{i + 1}) {codes[i]}")
        case 2:
            count = 0
            for i in range(len(codes)):
                tr = decode(codes[i])
                if tr:
                    print(f"В коде {i+1} была ошибка.")
                count += tr
            print(f"Всего {count} ошибок.")
        case 3:
            print("Линейно-групповые коды")
            for i in range(len(codes)):
                print(f"{i + 1}) {codes[i]}")
            print("Выберите код:")
            find_error = int(input())
            print("Введите индекс:")
            index_for_create_error = int(input())
            flag = codes[find_error-1][index_for_create_error - 1]
            print(codes[find_error-1][index_for_create_error - 1])
            print(codes)
            if codes[find_error-1][index_for_create_error - 1]:
                codes[find_error-1][index_for_create_error - 1] = 0
            else:
                codes[find_error-1][index_for_create_error - 1] = 1
            print("Линейно-групповые коды")
            for i in range(len(codes)):
                print(f"{i + 1}) {codes[i]}")
