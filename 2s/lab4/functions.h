
//��������� ������
struct product{
    char name[20];
    char country[20];
    int c;
};

//������� ����� �������� product1
void setProduct(product &product1){
    int count;
    cout<<"������� ��� ������:"<<endl;
    cin>>product1.name;
    cout<<"������� ������ ������:"<<endl;
    cin>>product1.country;
    cout<<"������� ���������� ������:"<<endl;
    cin>>count;
    product1.c=count;
}

//������ ����� �������� product1
void readProduct(product &product1){
    cout<<"��� ������: "<< product1.name<<endl;
    cout<<"������ ������: "<<product1.country<<endl;
    cout<<"���������� ������: "<<product1.c<<endl;
    system("pause");
}

//���������� ������� tovar N �����������
void setMP(product *tovar,int N){ 
    for (int i = 0; i<N ; i++){
        cout<<"<������� ������ ������ �"<<i+1<<">"<<endl;
        setProduct(tovar[i]);
    }
}

//������ ������� tovar �� N ��������
void readMP(product *tovar,int N){
    cout<<"<<������ ������� ������� �� "<<N<<" ���������.>>"<<endl;
    for (int i = 0; i<N ; i++){
        cout<<"<������� �"<<i+1<<">"<<endl;
        readProduct(tovar[i]);
    }
}

//������� ����� � ������� �������������� �����
void COUNTRY(product *tovar,int N, char *prod){
    cout<<"������ �������� ����� ������:"<<endl;
    int c=0;
    for (int i = 0; i<N; i++){
        if (!strcmp(tovar[i].name,prod)){
            cout<<tovar[i].country<<" - �������: "<< tovar[i].c << endl;
            c++;
        }
    }
    cout<<"�����: "<<c<<endl;
    system("pause");
}