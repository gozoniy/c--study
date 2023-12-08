
class MasterAeroflot:
    def __init__(self):
        self.__aeroflot = []
    

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