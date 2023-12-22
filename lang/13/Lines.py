from abc import ABC, abstractmethod

class Line(ABC):
    def __init__(self, length = 0):
        self._length = float(length)

    #@abstractmethod
    def Lenght(self):
        return self._length
    
    def my_name(self):
        return str(type(self).__name__)
    
    def from_string(self,string):
        self._length = float(string)

    def to_string(self):
        return f"{self._length}"
    
class ColoredLine(Line):
    def __init__(self, length = 0, color = "0 0 0"):
        super().__init__(length)
        self._color = color

    def get_color(self):
        return self._color

    def from_string(self,string):
        length, color = map(str, string.strip().split("   "))
        self._length = float(length)
        self._color = color

    def to_string(self):
        return f"{self._length}   {self._color}"

class PolyLine(Line):
    def __init__(self, lengths = [0,0]):
        super().__init__(float(lengths[0]))
        self._segment_lengths = map(float,lengths[1:])
        

    def Lenght(self):
        return self._length + sum(self._segment_lengths)
    
    def from_string(self,string):
        length, ls = string.strip().split("   ")
        self._length = float(length)
        self._segment_lengths = list(map(float,ls.split()))

    def to_string(self):
        return f"{self._length}   {' '.join(map(str,self._segment_lengths))}"
        


class Picture:
    def __init__(self):
        self._objects = []
    def add_from_console(self):
        sw = int(input("""Выберите тип линии:
1) Line
2) ColoredLine
3) PolyLine
"""))
        match sw:
            case 1:
                obj = Line()
                obj.from_string(input("Введите длину: "))
                self._objects.append(obj)
            case 2:
                obj = ColoredLine()
                l = input("Введите длину: ")
                col = input("Введите цвет: ")
                obj.from_string(f"{l}   {col}")
                self._objects.append(obj)
            case 3:
                obj = PolyLine()
                l = input("Введите длину: ")
                ls = input("Введите длины участков через пробел: ")
                obj.from_string(f"{l}   {ls}")
                self._objects.append(obj)
        
    def add(self, obj):
        self._objects.append(obj)

    def get(self):
        print("Содержимое picture:")
        for obj in self._objects:
            print(f"{type(obj).__name__}:\nПараметры: {obj.to_string()}")

    def get_in_range(self, min_length, max_length):
        for obj in self._objects:
            if float(min_length) <= obj.Lenght() <= float(max_length):
                print(f"{type(obj).__name__}:\nПараметры: {obj.to_string()}")

    def get_sorted_by_length(self):
        sorted_objects = sorted(self._objects, key=lambda x: x.Lenght())
        for obj in sorted_objects:
            print(f"{type(obj).__name__}:\nПараметры: {obj.to_string()}")
    
    def read(self, filename):
        with open(filename, 'r') as file:
            for string in file:
                if string == "\n":
                    continue
                else:
                    ty,meta = string.split("|")
                if ty == "Line":
                    obj = Line()
                    obj.from_string(meta)
                elif ty == "ColoredLine":
                    obj = ColoredLine()
                    obj.from_string(meta)
                elif ty == "PolyLine":
                    obj = PolyLine()
                    obj.from_string(meta)
                else:
                    print("Найден неизвестный тип в файле:", ty)
                    continue
                self._objects.append(obj)

    def write(self, filename):
        with open(filename, 'w') as file:
            for obj in self._objects:
                file.write(f"{obj.my_name()}|{obj.to_string()}\n")

