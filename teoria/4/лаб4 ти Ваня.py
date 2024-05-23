import random


# Список 10 случайных 15-разрядных двоичных кодов
def generate_binary_list(length=6, count=10):
    binary_list = []
    for _ in range(count):
        binary_num = ''.join(str(random.randint(0, 1)) for _ in range(length))
        binary_list.append(binary_num)
    return binary_list


# Расширенный код Хемминга
def modified_hamming_code(number):
    k1 = ((number[0] + number[1] + number[3] + number[4] ).count('1')) % 2
    k2 = ((number[0] + number[2] + number[3] + number[5] ).count('1')) % 2
    k3 = ((number[1] + number[2] + number[3] ).count('1')) % 2
    k4 = ((number[4] + number[5]).count('1')) % 2
    result = str(k1) + str(k2) + number[0] + str(k3) + number[1:4] + str(k4) + number[4:6]
    if (result.count('1') % 2) == 0:
        hamming_code = result + '0'
    else:
        hamming_code = result + '1'
    return hamming_code


# Добавление в коды случайной одиночной ошибки
def single_mistake(code):
    code_list = list(code)
    index = random.randint(0, 10)
    if code_list[index] == '1':
        code_list[index] = '0'
    else:
        code_list[index] = '1'
    single_mistake_code = ''.join(code_list)
    return single_mistake_code, index+1


# Добавление в коды случайной двойной ошибки
def double_mistake(code):
    code_list = list(code)
    indices = random.sample(range(10), 2)
    for index in indices:
        if code_list[index] == '1':
            code_list[index] = '0'
        else:
            code_list[index] = '1'
    double_mistake_code = ''.join(code_list)
    return double_mistake_code, (indices[0]+1, indices[1]+1)


# Обнаружение ошибок
def mistake_detection(code):
    s1 = ((code[0] + code[2] + code[4] + code[6] + code[8]).count('1')) % 2
    s2 = ((code[1] + code[2] + code[5] + code[6] + code[9]).count('1')) % 2
    s3 = ((code[3] + code[4] + code[5] + code[6]).count('1')) % 2
    s4 = ((code[7] + code[8] + code[9]).count('1')) % 2
    s = str(s4) + str(s3) + str(s2) + str(s1)
    if ((code.count('1') % 2) == 1):
        return s
    else:
        if int(s, 2) == 0:
            return 'Ошибки нет'
        else:
            return s


# Исправление одиночной ошибки
def single_mistake_correction(code, syndrome):
    s = int(syndrome, 2)
    code_list = list(code)
    if code_list[s-1] == '1':
        code_list[s-1] = '0'
    else:
        code_list[s-1] = '1'
    correct_code = ''.join(code_list)
    return correct_code


binary_numbers = generate_binary_list()
hamming_codes_list = []
for number in binary_numbers:
    hamming_codes_list.append(modified_hamming_code(number))

single_mistake_codes_list = []
single_mistake_indicies = []
for code in hamming_codes_list:
    single_mistake_code, single_mistake_index = single_mistake(code)
    single_mistake_codes_list.append(single_mistake_code)
    single_mistake_indicies.append(single_mistake_index)

double_mistake_codes_list = []
double_mistake_indicies = []
for code in hamming_codes_list:
    double_mistake_code, double_mistake_index = double_mistake(code)
    double_mistake_codes_list.append(double_mistake_code)
    double_mistake_indicies.append(double_mistake_index)

single_mistake_syndrome = []
for code in single_mistake_codes_list:
    single_mistake_syndrome.append(mistake_detection(code))
    
double_mistake_syndrome = []
for code in double_mistake_codes_list:
    double_mistake_syndrome.append(mistake_detection(code))

single_mistake_corrections_list = []
for i in range(len(single_mistake_codes_list)):
    single_mistake_corrections_list.append(single_mistake_correction(single_mistake_codes_list[i], single_mistake_syndrome[i]))

print("Кодовое сообщение | Код Хемминга")
for i in range(len(binary_numbers)):
    print(binary_numbers[i], "  |", hamming_codes_list[i])

print("\n\nОбнаружение и исправление одиночной ошибки")
print("Код Хемминга      | Код с 1 ошибкой  | Ошибочный разряд         | Обнаружение одиночной ошибки                  | Исправленный код")
for i in range(len(hamming_codes_list)):
    print(f'{hamming_codes_list[i]}       |      {single_mistake_codes_list[i]} | {single_mistake_indicies[i]}'
          f'                        | Вектор ошибки s = {single_mistake_syndrome[i]} => ошибка в '
          f'{int(single_mistake_syndrome[i], 2)} разряде  | {single_mistake_corrections_list[i]}')

print("\n\nОбнаружение двойной ошибки")
print("Код Хемминга      | Код с 2 ошибкой | Ошибочные разряды         | Обнаружение двойной ошибки")
for i in range(len(hamming_codes_list)):
    print(f'{hamming_codes_list[i]}       |      {double_mistake_codes_list[i]} | {(double_mistake_indicies[i])[0]} '
          f'{(double_mistake_indicies[i])[1]}                      |Вектор ошибки s = {double_mistake_syndrome[i]} '
          f'!= 0 => ошибка двойная')
