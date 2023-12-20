#Рейс
class Aeroflot:
    #Конструктор с параметрами
    def __init__(self, destination ="", number ="", Type ="", time ="", day =""):
        self.__destination = destination
        self.__number = number
        self.__Type = Type
        self.__time = time
        self.__day = day
    #Сетер из строки
    def set_st(self, st):
        self.__destination,self.__number,self.__Type,self.__time,self.__day = st.strip().split('\t')
    #Гетеры
    def get(self):
        return f"Рейс №{self.__number} в {self.__destination} самолётом {self.__Type} прилетает в {self.__time} по {self.__day}"
    def getU(self):
        return f"{self.__destination}\t{self.__number}\t{self.__Type}\t{self.__time}\t{self.__day}"
    def get_des(self):
        return self.__destination
    def get_type(self):
        return self.__Type
    def get_time(self):
        return (int(self.__time),self.__day)

#Класс массива рейсов
class Flights:
    #Конструктор по умолчанию
    def __init__(self):
        self.__aeroflot = []
    #Ввод из файла
    def read(self,filename):
        self.__aeroflot = []
        with open(filename, 'r') as file:
            lines = file.readlines()
        for line in lines:
            flight = Aeroflot()
            flight.set_st(line)
            self.add(flight)
    #Вывод в файл
    def save(self, filename):
        with open(filename, 'w') as file:
            for flight in self.__aeroflot:
                file.write(f"{flight.getU()}\n")

    def add(self, A):
        self.__aeroflot.append(A)
    def get(self):
        for i in self.__aeroflot:
            print(i.get())
    #ВЫБОРКИ
    #а) списка рейсов для заданного пункта назначения
    def get_dest(self, dest):
        for i in self.__aeroflot:
            if i.get_des() == dest:
                print(i.get())
    #б) списка рейсов самолетов указанного типа
    def get_type(self, Type):
        for i in self.__aeroflot:
            if i.get_type() == Type:
                print(i.get())
    #в) списка рейсов для заданного дня недели, время вылета которых находится в заданном интервале
    def get_time(self, day, time1, time2):
        for i in self.__aeroflot:
            if i.get_time()[1] == day and int(i.get_time()[0]) > int(time1) and int(i.get_time()[0]) < int(time2):
                print(i.get())
                
    #Сортировка по полю времени вылета
    def sort_by_time(self):
        self.__aeroflot = sorted(self.__aeroflot, key=lambda flight: flight.get_time()[0])
