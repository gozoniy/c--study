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
    const void operator = (date Date){
        date curr = *this;
        date Res;
        undays(Date.days());
    }
    //�������� + (����������� ���� � ����)
    const date operator + (int Date){
        date curr = *this;
        date Res;
        undays(curr.days() + Date);
        Res.undays(curr.days() + Date) ;
        return Res;
    }
    //�������� - (��������� ���� �� ����)
    const date operator - (int Date){
        date curr = *this;
        date Res;
        undays(curr.days() - Date);
        Res.undays(curr.days() - Date) ;
        return Res;
    }
    //�������� - (���������� ���� ����� ������)
    const int operator - (date &Date) {
        date curr = *this;
        int Res;
        Res = (curr.days() - Date.days()) ;
        return Res;
    }

//������� ���������
    //�������� ++ (������)
    const date operator ++ () {
        int N = days();
        undays(++N);
        return *this;
    }
    //�������� -- (�����)
    const date operator -- () {
        int N = days();
        undays(--N);
        return *this;
    }

//��������� ���������
    const bool operator == (date &Date){
        date curr = *this;
        if (curr.days()==Date.days()){return true;}
        else {return false;}
    }
        const bool operator > (date &Date){
        date curr = *this;
        if (curr.days()>Date.days()){return true;}
        else {return false;}
    }
    const bool operator < (date &Date){
        date curr = *this;
        if (curr.days()<Date.days()){return true;}
        else {return false;}
    }

};

#endif DATE_H