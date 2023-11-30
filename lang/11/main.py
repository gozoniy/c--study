from module import read_file, process_list, save_result
if __name__ == "__main__":
    input_file_path = "input.txt"
    output_file_path = "output.txt"
    # 1. Считывание элементов списка из файла
    original_list = read_file(input_file_path)

    # 2. Обработка списка в соответствии с вариантом
    result = process_list(original_list)

    # 3. Сохранение результатов в другой текстовый файл
    save_result(result, output_file_path)

    print(f"Результаты обработки сохранены в файл {output_file_path}")
