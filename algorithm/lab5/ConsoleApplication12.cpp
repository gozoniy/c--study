#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
string str;
int COUNT = 0, NUM_SIZE;
int n, MAX = 0, a;
string file = "list.txt";
fstream fin;
vector <vector<string>> num;
vector <string> vec;

class Car
{
public:

    string name;
    string color = "";
    string sd = "Закрыты", sl = "Выключены", sn = "", sc = "";


    void ch_name()
    {
        name = "";
        cout << "Введите новое название марки: ";
        cin >> name;
        cout << "Марка изменена.\n";
    }
    void ch_color(int n, vector <vector<string>> num)
    {
        color = "";
        cout << "Введите новый цвет авто:\n";
        cin >> color;
        cout << "Цвет изменен.\n";
    }
    void ch_light(int n, vector <vector<string>> num)
    {
        if (num[n - 1][2] == "Выключены")
        {
            sl = "Включены";
            cout << "Фары включены.\n\n";
        }
        else
        {
            sl = "Выключены";
            cout << "Фары выключены.\n\n";
        }
    }
    void ch_door(int n, vector <vector<string>> num)
    {
        sd = num[n - 1][3];
        if (sd == "Закрыты")
        {
            sd = "Открыты";
            cout << "Двери открыты.\n\n";
        }
        else
        {
            sd = "Закрыты";
            cout << "Двери закрыты.\n\n";
        }
    }

};
void work_spisok()
{
    fin.open("work_list.txt", fstream::in | fstream::out | fstream::app);
    ifstream("work_list.txt");
    while (getline(fin, str))
    {
        COUNT++;
    }
    fin.close();
    fin.open("work_list.txt", fstream::in | fstream::out | fstream::app);
    ifstream("work_list.txt");
    str = "";
    while (!fin.eof())
    {
        for (int i = 0; i < COUNT; i++)
        {
            vec.clear();
            for (int j = 0; j < 4; j++)
            {
                fin >> str;
                vec.push_back(str);
                str = "";
            }
            num.push_back(vec);
        }
        break;
    }
    fin.close();
    NUM_SIZE = num.size();
    if (NUM_SIZE != 0)
    {
        cout << "\nСохраненные машины:\n";
    }
    for (int i = 0; i < num.size(); i++)
    {
        cout << i + 1 << ")" << "  Марка: " << num[i][0] << "  Цвет: " << num[i][1] << "  Фары: " << num[i][2] << "  Двери: " << num[i][3] << "\n";
    }
    MAX = COUNT;
    n = MAX;
}
void vivod_pr()
{
    int pr_k = 0;
    fin.open("work_list.txt", fstream::in | fstream::out | fstream::app);
    ifstream("work_list.txt");
    while (getline(fin, str))
    {
        pr_k++;
    }
    fin.close();
    cout << "Проверка:\n";
    if (pr_k == num.size())
        cout << "Количество машин в коде совпадает с количеством машин в файле: " << pr_k << " = " << num.size() << endl;
    else cout << "Количество машин в коде не совпадает с количеством машин в файле: " << pr_k << " != " << num.size() << endl;
}
void spisok()
{
    cout << "Список машин:\n";
    for (int i = 0; i < num.size(); i++)
    {
        cout << i + 1 << ") ";
        for (int j = 0; j < 2; j++)
        {
            cout << num[i][j] << " ";
        }
        cout << "\n";
    }
}
void mashina()
{
    cout << "Машина №" << n << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << num[n - 1][i] << " ";
    }
    cout << endl;
}
void save()
{
    fin.open("work_list.txt", fstream::in | fstream::out | fstream::app);
    ofstream("work_list.txt");
    for (int i = 0; i < num.size(); i++)
    {
        fin << num[i][0] << " " << num[i][1] << " " << num[i][2] << " " << num[i][3] << "\n";
    }
    fin.close();

    fin.open(file, fstream::in | fstream::out | fstream::app);
    ofstream("list.txt");
    for (int i = 0; i < num.size(); i++)
    {
        fin << "Номер авто:" << i + 1 << "\nМарка: " << num[i][0] << "\n" << "Цвет: " << num[i][1] << "\n" << "Фары: " << num[i][2] << "\n" << "Двери: " << num[i][3] << "\n\n";
    }
    fin.close();
}
void ch_car()
{
    Car car;
    int NC;
    NC = 0;
    NUM_SIZE = num.size();
    if (NUM_SIZE == 0)
    {
        cout << "Список машин пуст. Добавьте новую машину.\n";
    }
    else
    {
        spisok();
        cout << "\nВыберите машину: "; cin >> NC;
        while (NC > MAX || NC < 1)
        {
            cout << "\nВведенное число не соотвествует количеству машин. Введите число в диапозоне от 1 до " << MAX;
            NC = 0;
            cout << "\nНомер машины № "; cin >> NC;
        }
        n = NC;
    start_change:;
        cout << "\nВыберите действие:\n"
            << "1 - Поменять название марки\n"
            << "2 - Поменять цвет авто\n"
            << "3 - Включить/выключить фары\n"
            << "4 - Открыть/закрыть двери\n"
            << "5 - Завершить работу над машиной\n";

    end1:;
        a = 0; cout << "Выбрано действие "; cin >> a; cout << "\n";
        switch (a)
        {
        case 1: {cout << "Машина до изменений: "; mashina(); car.ch_name(); num[n - 1].at(0) = car.name; cout << "Машина после изменений: "; mashina(); save(); break; }//Поменять название марки
        case 2: {cout << "Машина до изменений: "; mashina(); car.ch_color(n, num);  num[n - 1].at(1) = car.color; cout << "Машина после изменений: "; mashina(); save(); break; }//Поменять цвет авто
        case 3: {cout << "Машина до изменений: "; mashina(); car.ch_light(n, num);  num[n - 1].at(2) = car.sl; cout << "Машина после изменений: "; mashina(); save(); break; }//Включить/выключить фары
        case 4: {cout << "Машина до изменений: "; mashina(); car.ch_door(n, num);  num[n - 1].at(3) = car.sd; cout << "Машина после изменений: "; mashina(); save(); break; }// Открыть/закрыть двери
        case 5: goto end_change;//Завершить работу над машиной
        default:
            cout << "Вы выбрали несуществующий пункт. Выберите другой.\n";
            goto end1;
            break;
        }
        system("pause");
        for (int i = n - 1;;)
        {
            cout << "\nМарка: " << num[i][0] << "\n" << "Цвет: " << num[i][1] << "\n" << "Фары: " << num[i][2] << "\n" << "Двери: " << num[i][3] << "\n\n";
            break;
        }
        goto start_change;
    }
end_change:;
}
void add_car()
{
    Car car;
    MAX++;
    n = MAX;
    car.name = ""; car.color = "";
    car.sl = "Выключены"; car.sd = "Закрыты";
    vec.clear();

    cout << "Новая машина создана.\nВведите название марки: ";
    cin >> car.name;
    cout << "Введите цвет авто: ";
    cin >> car.color;
    vec.push_back(car.name);
    vec.push_back(car.color);
    vec.push_back(car.sl);
    vec.push_back(car.sd);
    num.push_back(vec);
    cout << "Фары: " << car.sl << "\n" << "Двери: " << car.sd << "\n";
    cout << "\nМашина добавлена в список.\n\n";
}
void delete_car()
{
    int ND;
    ND = 0;
    NUM_SIZE = num.size();
    if (NUM_SIZE == 0)
    {
        cout << "Список машин пуст. Добавьте новую машину.\n";
    }
    else
    {
        spisok();
        cout << "\nВведите номер машины, которую хотите удалить: "; cin >> ND;
        while (ND > MAX || ND < 1)
        {
            cout << "\nВведенное число не соотвествует количеству машин. Введите число в диапозоне от 1 до " << MAX;
            cout << "\nВведите номер машины, которую хотите удалить: ";
            ND = 0; cin >> ND;
        }
        cout << "\nПроверка:\n";
        cout << "Машины до удаления:\n";
        spisok();
        for (int j = (ND - 1);;)
        {
            swap(num.back(), num[j]);
            break;
        }
        num.pop_back();
        MAX--;
        cout << "\nМашины после удаления:\n";
        spisok();
        if (MAX == 0)
        {
            cout << "\nУдалена последняя машина.\n";
        }
        else
        {
            cout << "Машина удалена.\n\n";
        }
    }
}
void def()
{
    cout << "Вы выбрали несуществующий пункт. Выберите другой.\n";
}
void off()
{
    cout << "\nСписок созданных машин можно посмотреть в файле list.txt (см. в содержащей папке).\nЗавершение работы.\n\n";
    system("pause");
}
bool main_select(int com, bool flag)
{
    switch (com)
    {
    case 1: { ch_car(); system("pause"); break; }
    case 2: {delete_car(); save(); vivod_pr(); system("pause"); break; }
    case 3: {add_car(); save(); vivod_pr(); system("pause"); break; }
    default: {def(); flag = false; break; }
    }
    return (flag);
}
int main()
{
    system("chcp 1251");

    bool def_flag;
    work_spisok();

act:;
    cout << "\nВыберите действие:\n"
        << "1 - Изменить характеристики авто\n"
        << "2 - Удалить авто\n"
        << "3 - Добавить авто\n"
        << "0 - Завершить работу кода\n";

caseN:;
    int a;  def_flag = true; cout << "Выбрано действие "; cin >> a; cout << "\n";
    if (a == 0)
        goto exit;
    def_flag = main_select(a, def_flag);
    if (def_flag == false)
        goto caseN;
    goto act;

exit:;
    save();
    off();
    system("cls");
}