#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class hashtab {
private:
    size_t table_size;
    vector<vector<string>> table;

//случайное число в диапазоне от 0 до 1 для работы мультипликативной хеш-функции
    const double hash = 0.618033; 
public:
    //Конструктор
    hashtab() : table(table_size) {}
    hashtab(size_t size) : table_size(size), table(table_size) {}

    //Хеш-функция
    int HashFunction(string key){
        double f = hash;
        f = f / 10;
        int hash = 0;
        // умножить ключ на случайное число из диапазона 0...1
        for (char ch : key){
            hash += ch;
        }
        f = hash * f;
        // взять дробную часть
        f = f - int(f);
        // возвратить число в диапазоне 0...n-1
        return table_size*f;
    }

    //Вставка ключа / возвращает число коллизий
    int insert(const std::string& key){
        int index = HashFunction(key);
        table[index].push_back(key);
        return table[index].size();
    }
    //Поиск ключа / возвращает число сравнений
    int search(const std::string& key){
        int index = HashFunction(key);
        int count = 1;
        int comparisons = 0;
        vector<string>& chain = table[index];
        for (string value : chain) {
            comparisons++;
            if (value == key) {
                return comparisons; // Элемент найден
            }
        }
        return 0; // Элемент не найден
    }
    //Удаление ключа / возвращает число сравнений
    int remove(const std::string& key){
        int index = HashFunction(key);
        int count = 1;
        int comparisons = 0;
        for (auto i = table[index].begin(); i!=table[index].end(); i++){
            comparisons++;
            if (*i == key){
                table[index].erase(i);
                cout<<"Ключ удалён.\n";
                return comparisons;
            }
        }
        cout<<"Ключ не найден.\n";
        return comparisons;
    }
    //Вывод в поток
    ostream& print(std::ostream& out) const{
        size_t c = 0;
        size_t size = table_size;
        for (int i = 0; i < table_size; ++i){
            out << i << " : ";
            if (table[i].size() == 0){size--;}
            else{
                for(int j = 0; j < table[i].size(); j++){
                    c++;
                    out << table[i][j];
                    if (j + 1 != table[i].size()){
                        out<<" -> ";
                    }
                }
            }
            out<<"\n";
        }
        if(size!=0){
            out<<"Среднее число сравнений: "<<static_cast<double>(c) / size<< "\n";
            }
        return out;

    }
    //Очистка таблицы
    void clear(){
        for (int i = 0; i < table_size; ++i){
            table[i].clear();
        }
    }
};
ostream& operator << (ostream & out,const hashtab& p){
    p.print(out);
    return out;
}

