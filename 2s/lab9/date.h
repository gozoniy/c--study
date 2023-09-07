#ifndef DATE_H
#define DATE_H

class date{
    int day,month,year;
public:
    void set();
    void print();
    long format();
    int days();
    void undays(int N);

    //������������
    date(){srand(time(NULL)); day=rand()%31+1; month = rand()%12+1; year = 2022+rand()%2;}
    date(int d, int m, int y){day = d; month = m; year = y;}
    date(date &A){day = A.day; month = A.month; year = A.year;}
    //����������
    ~date(){}

//�������������� ���������
    const void operator = (date Date);
    const date operator + (int Date);   //�������� + (����������� ���� � ����)
    const date operator - (int Date);   //�������� - (��������� ���� �� ����)
    const int operator - (date &Date);  //�������� - (���������� ���� ����� ������)
//������� ���������
    const date operator ++ ();    //�������� ++ (������)
    const date operator -- ();    //�������� -- (�����)
//��������� ���������
    const bool operator == (date &Date);
    const bool operator > (date &Date);
    const bool operator < (date &Date);

//���������� �������� �����/������
friend ostream& operator<<(ostream& s_out, const date& D);
friend istream& operator>>(istream& s_in, date& D);
};



#endif DATE_H