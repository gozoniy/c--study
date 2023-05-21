#ifndef DATE_H
#define DATE_H

class date{
    int day,month,year;
public:
    void set();
    void print();
    long format();
    int days()const;
    void undays(int N);

    //������������
    date(){srand(time(NULL)); day=rand()%31+1; month = rand()%12+1; year = 2022+rand()%2;}
    date(int d, int m, int y){day = d; month = m; year = y;}
    date(date &A){day = A.day; month = A.month; year = A.year;}
    //����������
    ~date(){}

//�������������� ���������
    const void operator = (const date &Date);   //�������� = (�����������)
    const date operator + (int Date);   //�������� + (����������� ���� � ����)
    const date operator - (int Date);   //�������� - (��������� ���� �� ����)
    const int operator - (const date &Date);  //�������� - (���������� ���� ����� ������)
//������� ���������
    const date operator ++ ();    //�������� ++ (������)
    const date operator -- ();    //�������� -- (�����)
//��������� ���������
    const bool operator == (date &Date);
    const bool operator > (date &Date);
    const bool operator < (date &Date);


};

#endif DATE_H