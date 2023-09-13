#ifndef AEROFLOT_H
#define AEROFLOT_H

class aeroflot{
        char destination[20];
        char index[20];
        char type[20];
        int time;
        char day[20];
        
    public:
    //������������
        aeroflot();
        aeroflot(int T);
        aeroflot(const aeroflot &B);
        ~aeroflot() {}
    //������
        void set();
        void print()const;
        void set_time(const int T);
        void get_time()const;
        friend void DEST(aeroflot *B, int n, char *D);
        friend void TYPE(aeroflot *B, int n, char *T);
        friend void TIME(aeroflot *B, int n, char *D, int t1, int t2);
        friend void SORT(aeroflot *B, int n);
    //���������
        const void operator = (const aeroflot B);
        const bool operator == (const aeroflot &B);
        const bool operator > (const aeroflot &B);
        const bool operator < (const aeroflot &B);
    //��������� ����-�����
        friend ostream& operator<<(ostream& s_out, const aeroflot& D);
        friend istream& operator>>(istream& s_in, aeroflot& D);
};

#endif AEROFLOT_H