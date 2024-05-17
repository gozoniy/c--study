import random
#Задание списка кодов
def gen(length=5, count=10):
    binary_list = []
    for _ in range(count):
        binary_num = ''.join(str(random.randint(0, 1)) for _ in range(length))
        binary_list.append(binary_num)
    return binary_list
#Расширенный код Хемминга
def hamCode(n):
    k1 = ((n[0] + n[1] + n[3] + n[4]).count('1')) % 2
    k2 = ((n[0] + n[2] + n[3]).count('1')) % 2
    k3 = ((n[1] + n[2] + n[3]).count('1')) % 2
    k4 = ((n[4]).count('1')) % 2
    result = str(k1) + str(k2) + n[0] + str(k3) + n[1:4] + str(k4) + n[4:]
    if (result.count('1') % 2) == 0:
        hamming_code = result + '0'
    else:
        hamming_code = result + '1'
    return hamming_code
#Одиночная ошибка
def single_mistake(code):
    code_list = list(code)
    index = random.randint(0, 9)
    if code_list[index] == '1':
        code_list[index] = '0'
    else:
        code_list[index] = '1'
    Icode = ''.join(code_list)
    return Icode, index+1
#Двойная ошибка
def doub(code):
    code_list = list(code)
    indices = random.sample(range(10), 2)
    for index in indices:
        if code_list[index] == '1':
            code_list[index] = '0'
        else:
            code_list[index] = '1'
    dIcode = ''.join(code_list)
    return dIcode, (indices[0]+1, indices[1]+1)
#Обнаружение ошибок
def detector(code):
    s1 = ((code[0] + code[2] + code[4] + code[6] + code[8]).count('1')) % 2
    s2 = ((code[1] + code[2] + code[5] + code[6]).count('1')) % 2
    s3 = ((code[3] + code[4] + code[5] + code[6]).count('1')) % 2
    s4 = ((code[7] + code[8]).count('1')) % 2
    s = str(s4) + str(s3) + str(s2) + str(s1)
    if (code.count('1') % 2) == 1:
        return s
    else:
        if int(s, 2) == 0:
            return 'Ошибки нет'
        else:
            return s
#Исправление одиночной ошибки
def corrector(code, syndrome):
    s = int(syndrome, 2)
    code_list = list(code)
    if code_list[s-1] == '1':
        code_list[s-1] = '0'
    else:
        code_list[s-1] = '1'
    correct_code = ''.join(code_list)
    return correct_code

if __name__ == "__main__":
    bina = gen()
    hamm = []
    for n in bina:
        hamm.append(hamCode(n))
    Imiss = []
    ImissID = []
    for code in hamm:
        Icode, single_mistake_index = single_mistake(code)
        Imiss.append(Icode)
        ImissID.append(single_mistake_index)
    IImiss = []
    IImissID = []
    for code in hamm:
        dIcode, doub_index = doub(code)
        IImiss.append(dIcode)
        IImissID.append(doub_index)
    Isyn = []
    for code in Imiss:
        Isyn.append(detector(code))
    dIsyn = []
    for code in IImiss:
        dIsyn.append(detector(code))
    corr = []
    for i in range(len(Imiss)):
        corr.append(corrector(Imiss[i], Isyn[i]))

    print(f'{str("Код"):^16}| {str("Код Хемминга"):^16}') 
    print("----------------|-----------------")
    for i in range(len(bina)):
        print(f'{bina[i]:^16}|{hamm[i]:^16}')

    print(" Код Хемминга   | 1 ошибка        | Ошибочный разряд    | "
        "    Симптом      | Исправленный код")
    print("----------------|-----------------|---------------------|------------------|----------")
    for i in range(len(hamm)):
        print(f'{hamm[i]:^15} | {Imiss[i]:^15} | {ImissID[i]:^20}'
            f'| s = {Isyn[i]} = 'f'{int(Isyn[i], 2)}     | {corr[i]}')

    print(f'{str("Двойная ошибка"):^100}')
    print(f'{str("Код Хемминга"):^16}| {str("2 ошибки"):^15} | {str("Ошибочные разряды"):^19} | {str("Симптом"):^16}')
    print("----------------|-----------------|---------------------|-----------------")
    for i in range(len(hamm)):
        print(f'{hamm[i]:^15} | {IImiss[i]:^15} | {(IImissID[i])[0]:^9} |'
            f'{(IImissID[i])[1]:^9}| s = {dIsyn[i]:^}')
