from master import *
if __name__ == "__main__":
    a = Flights()
    while True:
        print("Главное меню")
        print("1) Добавить с консоли")
        print("2) Добавить из файла")
        print("3) Вывести в консоль")
        print("4) Вывести в файл")
        print("5) Выборка по назначению")
        print("6) Выборка по типу")
        print("7) Выборка по времени")
        print("8) Отсортировать по времени")
        print("0) <<< Выход")
        ans = int(input())
        match ans:
            case 1:
                des, num, ty, t1, day = input("Введите назначение, номер, тип, время вылета и день через пробел: ").split()
                m = Aeroflot(des,num,ty,t1,day)
                a.add(m)
            case 2:
                a.read("input.txt")
            case 3:
                a.get()
            case 4:
                a.save("output.txt")
            case 5:
                des = input("Введите назначение: ")
                a.get_dest(des)
            case 6:
                ty = input("Введите тип: ")
                a.get_type(ty)
            case 7:
                d,t1,t2 = input("Введите день, время от и до через пробел d_t1_t2: ").split()
                a.get_time(d,t1,t2)
            case 8:
                a.sort_by_time()
            case 0:
                break
                





