class Aeroflot:
    def __init__(self, destination, number, Type, time, day):
        self.__destination = destination
        self.__number = number
        self.__Type = Type
        self.__time = time
        self.__day = day
    def Set(self):
        self.__destination = input("Введите назначение: ")
    def get(self):
        return f"Рейс {self.__number} в {self.__destination} самолётом {self.__Type} прилетает в {self.__time} по {self.__day}"
    def get_des(self):
        return self.__destination
    def get_type(self):
        return self.__Type
    def get_time(self):
        return (self.__time,self.__day)
class Flights:
    def __init__(self):
        self.__aeroflot = []
    def set_file(self,filename):
        self.__aeroflot = []
        with open(filename, 'r') as file:
            lines = file.readlines()
        for line in lines:
            flight_data = line.strip().split('\t')
            destination = flight_data[0]
            flight_number = flight_data[1]
            aircraft_type = flight_data[2]
            departure_time = flight_data[3]
            weekday = flight_data[4]
            flight = Aeroflot(destination, flight_number, aircraft_type, departure_time, weekday)
            self.add_flight(flight)
    def add(self, A):
        self.__aeroflot.append(A)
    def get(self):
        for i in self.__aeroflot:
            print(i.get())
    def get_dest(self, dest):
        for i in self.__aeroflot:
            if i.get_des() == dest:
                print(i.get())
    def get_type(self, Type):
        for i in self.__aeroflot:
            if i.get_type() == Type:
                print(i.get())
    def get_time(self, day, time1, time2):
        for i in self.__aeroflot:
            if int(i.get_time()[0]) > int(time1) and int(i.get_time()[0]) < int(time2) and i.get_time()[1] == day:
                print(i.get())
    
            
a = Flights()
a.add(Aeroflot("Moscow", "SU123", "Boeing 737", "1230", "Monday"))
a.add(Aeroflot("New York", "SU123", "Boeing 737", "1200", "Monday"))
a.get_time("Monday","1215","1245")





