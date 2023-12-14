#include <iostream>
#include <string>
#include <vector>
#include <list>

class hashtab {
private:
    const size_t table_size = 100;
    std::vector<std::string> table;

public:
    //Конструктор
    hashtab() : table(table_size, "") {}
    //Хеш-функция
    int HF(int key){
        float f = rand()%9+rand()/static_cast <float> (RAND_MAX);
        f = f / 10;
        // умножить ключ на случайное число из диапазона 0...1
        f = key * f;
        // взять дробную часть
        f = f - int(f);
        // возвратить число в диапазоне 0...n-1
        return table_size*f;
    }

    int HashFunction(const std::string& key){
        int hash = 0;
        for (char ch : key){
            hash += ch;
        }
        return hash % table_size;
    }
    //Вставка ключа
    void insert(const std::string& key, size_t& collisions_cnt){
        int index = HashFunction(key);
        int count = 1;
        collisions_cnt = 0;
        while (!table[index].empty()){
            collisions_cnt++;
            index = (index + count * count) % table_size; //Открытая адресация (квадратичные пробы)
            count++;
        }
        table[index] = key;
    }
    //Поиск ключа
    bool search(const std::string& key, size_t& comparisons_cnt){
        int index = HashFunction(key);
        int count = 1;
        comparisons_cnt = 0;
        while (!table[index].empty()){
            comparisons_cnt++;
            if (table[index] == key) return true;
            index = (index + count * count) % table_size;
            count++;
        }
        return false;
    }
    //Удаление ключа
    void remove(const std::string& key){
        int index = HashFunction(key);
        int count = 1;
        while (!table[index].empty()){
            if (table[index] == key){
                table[index] = "";
                return;
            }
            index = (index + count * count) % table_size;
            count++;
        }
    }
    //Вывод в поток
    std::ostream& print(std::ostream& out) const{
        for (int i = 0; i < table_size; ++i){
            out << i << ": " << table[i] << std::endl;
        }
        return out;
    }
    //Очистка таблицы
    void clear(){
        for (int i = 0; i < table_size; ++i){
            table[i] = "";
        }
    }
};
std::ostream& operator << (std::ostream & out,const hashtab& p){
    p.print(out);
    return out;
}

