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
    date(){srand(time(NULL)); day=rand()%31+1; month = rand()%12+1; year = rand()%2023+1;}
    date(int d, int m, int y){day = d; month = m; year = y;}
    date(date &A){day = A.day; month = A.month; year = A.year;}
    //����������
    //~date(){cout<<"���� "<<day<<"."<<month<<"."<<year<<" �������.\n";}

    //�������� + 
    const date operator + (date &Date){
        date curr = *this;
        date Res;
        Res.undays(curr.days() + Date.days()) ;
        return Res;
    }
    //�������� - (���������� ���� ����� ������)
    const int operator - (date &Date) {
        date curr = *this;
        int Res;
        Res = (curr.days() - Date.days()) ;
        return Res;
    }
    date operator ++ () {
        int N = days();
        undays(N++);
        return *this;
    }
};

#endif DATE_H