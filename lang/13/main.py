from Lines import *

if __name__ == "__main__":
    p = Picture()
    while True:
        sw = int(input("""Главное меню:
1) Добавить объект с консоли
2) Добавить из файла
3) Вывести в консоль
4) Вывести в файл
5) Вывести в диапазоне длины
6) Вывести в порядке убывания длины
0) <<< Выход
"""))
        match sw:
            case 1:
                p.add_from_console()
            case 2:
                p.read("output.txt")
            case 3:
                p.get()
            case 4:
                p.write("output.txt")
            case 5:
                l1, l2 = input("Введите диапазон длины через пробел:").split()
                p.get_in_range(l1,l2)
            case 6:
                p.get_sorted_by_length()
            case 0:
                break
        
        
    