#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class hashtab {
private:
    size_t table_size;
    vector<vector<string>> table;

//��������� ����� � ��������� �� 0 �� 1 ��� ������ ����������������� ���-�������
    const double hash = 0.618033; 
public:
    //�����������
    hashtab() : table(table_size) {}
    hashtab(size_t size) : table_size(size), table(table_size) {}

    //���-�������
    int HashFunction(string key){
        double f = hash;
        f = f / 10;
        int hash = 0;
        // �������� ���� �� ��������� ����� �� ��������� 0...1
        for (char ch : key){
            hash += ch;
        }
        f = hash * f;
        // ����� ������� �����
        f = f - int(f);
        // ���������� ����� � ��������� 0...n-1
        return table_size*f;
    }

    //������� ����� / ���������� ����� ��������
    int insert(const std::string& key){
        int index = HashFunction(key);
        table[index].push_back(key);
        return table[index].size();
    }
    //����� ����� / ���������� ����� ���������
    int search(const std::string& key){
        int index = HashFunction(key);
        int count = 1;
        int comparisons = 0;
        vector<string>& chain = table[index];
        for (string value : chain) {
            comparisons++;
            if (value == key) {
                return comparisons; // ������� ������
            }
        }
        return 0; // ������� �� ������
    }
    //�������� ����� / ���������� ����� ���������
    int remove(const std::string& key){
        int index = HashFunction(key);
        int count = 1;
        int comparisons = 0;
        for (auto i = table[index].begin(); i!=table[index].end(); i++){
            comparisons++;
            if (*i == key){
                table[index].erase(i);
                cout<<"���� �����.\n";
                return comparisons;
            }
        }
        cout<<"���� �� ������.\n";
        return comparisons;
    }
    //����� � �����
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
            out<<"������� ����� ���������: "<<static_cast<double>(c) / size<< "\n";
            }
        return out;

    }
    //������� �������
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

