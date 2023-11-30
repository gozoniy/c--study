#Чтение
def read_file(file_path):
    with open(file_path, "r") as file:
        return list(map(float,file.read().split()))

#Обработка
def process_list(original_list):
    nZ = 1
    aboveAvg = 0
    total_sum = 0
    for element in original_list:
        total_sum += element
        if element != 0:
            nZ *= element
        if element > sum(original_list) / len(original_list):
            aboveAvg += 1
    return (nZ, aboveAvg)

#Запись
def save_result(result, output_file_path):
    with open(output_file_path, "w") as file:
        file.write(f"Произведение ненулевых элементов: {result[0]}\n")
        file.write(f"Количество элементов, превышающих среднее: {result[1]}")
