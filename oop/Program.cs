using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace file_text
{
  
  class Program
    {
        static void Main(string[ ] args)
        {
            try   
                { 
               // Создание объекта класса StreamReader для чтения из файла
               // input.txt
                 StreamReader f = new StreamReader("input.txt");
                string s;
                long i = 0;
               // Чтение строк из файла. Строка определяется как последователь-
               // ность символов, за которыми следует перевод строки (\n), 
              // возврат каретки (\r) или за символом возврата каретки сразу 
              // следует символ перевода строки (\r\n)
              // Возвращается значение null, если достигнут конец входного 
              // потока
                while ((s = f.ReadLine( )) != null)
              // Вывод на экран пронумерованных строк
                 Console.WriteLine("{0}: {1}", ++i, s);
                              f.Close( );             
// Закрытие файла
            }

           // Исключение FileNotFoundException создается, когда попытка
           // доступа к файлу, не существующему на диске, заканчивается 
           // неудачей
            catch (FileNotFoundException e)
            {
                Console.WriteLine(e.Message);
                 Console.WriteLine("Проверьте правильность имени файла");
                return;
           }
        }
    }
}
