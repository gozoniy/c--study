
//Структура товара
struct product{
    char name[20];
    char country[20];
    int c;
};

//Задание одной струтуры product1
void setProduct(product &product1){
    int count;
    cout<<"Введите имя товара:"<<endl;
    cin>>product1.name;
    cout<<"Введите страну товара:"<<endl;
    cin>>product1.country;
    cout<<"Введите количество товара:"<<endl;
    cin>>count;
    product1.c=count;
}

//Чтение одной струтуры product1
void readProduct(product &product1){
    cout<<"Имя товара: "<< product1.name<<endl;
    cout<<"Страна товара: "<<product1.country<<endl;
    cout<<"Количество товара: "<<product1.c<<endl;
    system("pause");
}

//Заполнение массива tovar N структурами
void setMP(product *tovar,int N){ 
    for (int i = 0; i<N ; i++){
        cout<<"<Укажите данные позици №"<<i+1<<">"<<endl;
        setProduct(tovar[i]);
    }
}

//Чтение массива tovar из N структур
void readMP(product *tovar,int N){
    cout<<"<<Чтение массива струтур из "<<N<<" элементов.>>"<<endl;
    for (int i = 0; i<N ; i++){
        cout<<"<Позиция №"<<i+1<<">"<<endl;
        readProduct(tovar[i]);
    }
}

//выборка стран в которые экспортируется товар
void COUNTRY(product *tovar,int N, char *prod){
    cout<<"Страны экспорта этого товара:"<<endl;
    int c=0;
    for (int i = 0; i<N; i++){
        if (!strcmp(tovar[i].name,prod)){
            cout<<tovar[i].country<<" - объёмом: "<< tovar[i].c << endl;
            c++;
        }
    }
    cout<<"Всего: "<<c<<endl;
    system("pause");
}