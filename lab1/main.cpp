#include "aeroflot.cpp"

int main(void){
    system("chcp 1251");
    bool f = true, M = false;
    int sw,n;
    aeroflot* A;
    
    while (f){
        cout<<"*Главное меню*\n"
        <<"1) Создать массив\n"
        <<"2) Запись массива\n"
        <<"3) Вывод массива\n"
        <<"4) Сортировка массива\n"
        <<"5) Выборки\n"
        <<"6) Работа с файлами\n"
        <<"0) Закончить работу с программой\n";
        cin>>sw;
        switch (sw){
            case 1:{//Создание массива
                cout<<"Введите длину массива: ";
                cin>>n;
                M = true;
                A = new aeroflot[n];
                break;
            }
            case 2:{//Запись
                if (!M){
                        cout<<"Массив не создан!\n";
                    }
                    else{
                        setMA(A,n);
                        break;
                    }
            }
            case 3:{//Чтение
                if (!M){
                    cout<<"Массив не создан!\n";
                }
                else{
                    cout<<"Массив длинной "<<n<<" элементов:\n";
                    getMA(A,n);
                    system("pause");
                }
                break;
            }
            case 4:{//Сортировка
                if (!M){
                    cout<<"Массив не создан!\n";
                }
                else{
                    SORTer(A,n);
                    cout<<"Массив отсортирован по времени вылета.\n";
                }
                break;
            }
            case 5:{//Выборки
                cout<<"1) Выборка по пункту назначения\n"
                <<"2) Выборка по типу\n"
                <<"3) Выборка по промежутку времени\n";
                int sw2;
                cin>>sw2;
                switch (sw2){
                    case 1:{
                        cout<<"Введите пункт назначения: ";
                        char inp[20];
                        cin>>inp;
                        DEST(A,n,inp);
                        break;
                    }
                    case 2:{
                        cout<<"Введите тип: ";
                        char inp[20];
                        cin>>inp;
                        TYPE(A,n,inp);
                        break;
                    }
                    case 3:{
                        cout<<"Введите день недели, время от и до:  ";
                        char inp[20];
                        int t1,t2;
                        cin>>inp>>t1>>t2;
                        TIME(A,n,inp,t1,t2);
                        break;
                    }
                    sw2 = 0;
                }
                break;
            }
            case 6:{//Файл
                if (!M){
                        cout<<"Массив не создан!\n";
                    }
                else{
                    cout<<"1) Чтение из файла\n"
                    <<"2) Запись в файл\n";
                    int sw3;
                    cin>>sw3;
                    switch (sw3){
                        case 1:{
                            cout<<"Введите имя файла: ";
                            string F;
                            cin>>F;
                            if (F == "1"){F = "test.txt";}
                            ifstream fin(F);
                            if (!fin.is_open()){
                                cout << "Ошибка открытия файла ввода!" << endl;
                            }
                            else
                            {
                                cout << "Файл открыт." << endl;
                                importA(fin,A,n);
                                fin.close();
                            }
                            break;
                        }
                        case 2:{
                            cout<<"Введите имя файла: ";
                            char F[20];
                            cin>>F;
                            ofstream fout(F);
                            if (!fout.is_open())
                            {
                                cout << "Ошибка открытия файла ввода!" << endl;
                            }
                            else
                            {
                                cout << "Файл открыт." << endl;
                                exportA(fout,A,n);
                                fout.close();
                            }
                            break;
                        }
                        sw3 = 0;
                    }
                }
                break;
            }
            case 0:{//Выход
                f = false;
                break;
            }
            sw = 0;
        }
    }
}