class Aeroflot:
    def __init__(self, destination, flight_number, aircraft_type, departure_time, day_of_week):
        self.__destination = destination
        self.__flight_number = flight_number
        self.__aircraft_type = aircraft_type
        self.__departure_time = departure_time
        self.__day_of_week = day_of_week
    def __str__(self):
        return f"Flight {self.flight_number} to {self.destination} ({self.aircraft_type}), {self.day_of_week}, {self.departure_time}"

class MasterAeroflot:
    def __init__(self):
        self.aeroflot = []

    def add_flight(self, aeroflot_instance):
        self.aeroflot.append(aeroflot_instance)

    def flights_by_destination(self, destination):
        for flight in self.aeroflot:
            if flight._Aeroflot__destination == destination:
                print(self)

    def flights_by_aircraft_type(self, aircraft_type):
        return [flight for flight in self.aeroflot if flight._Aeroflot__aircraft_type == aircraft_type]

    def flights_by_day_and_time_range(self, day_of_week, start_time, end_time):
        return [
            flight for flight in self.aeroflot
            if flight._Aeroflot__day_of_week == day_of_week
            and start_time <= flight._Aeroflot__departure_time <= end_time
        ]

    def sort_flights_by_departure_time(self):
        self.aeroflot.sort(key=lambda flight: flight._Aeroflot__departure_time)

# Пример использования:

# Создаем экземпляр мастер-класса
master_aeroflot = MasterAeroflot()

# Добавляем рейсы
master_aeroflot.add_flight(Aeroflot("Moscow", "SU123", "Boeing 737", "1200", "Monday"))
master_aeroflot.add_flight(Aeroflot("Paris", "AF456", "Airbus A320", "1400", "Wednesday"))
master_aeroflot.add_flight(Aeroflot("London", "BA789", "Boeing 747", "1600", "Friday"))

# Выборка по пункту назначения
flights_to_moscow = master_aeroflot.flights_by_destination("Moscow")
print("Flights to Moscow:", flights_to_moscow)

# Выборка по типу самолета
boeing_flights = master_aeroflot.flights_by_aircraft_type("Boeing 737")
print("Boeing flights:", boeing_flights)

# Выборка по дню недели и интервалу времени
weekday_flights = master_aeroflot.flights_by_day_and_time_range("Wednesday", "1300", "1500")
print("Wednesday flights between 1300 and 1500:", weekday_flights)

# Сортировка по времени вылета
master_aeroflot.sort_flights_by_departure_time()
print("Sorted flights by departure time:", master_aeroflot.aeroflot)