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
        //~aeroflot();
    //������
        void set();
        void print();
        void set_time(int T);
        void get_time();
        friend void DEST(aeroflot *B, int n, char *D);
        friend void TYPE(aeroflot *B, int n, char *T);
        friend void TIME(aeroflot *B, int n, char *D, int t1, int t2);
        friend void SORT(aeroflot *B, int n);
    //���������
        void operator = (aeroflot B);
    //��������� ����-�����
        friend ostream& operator<<(ostream& s_out, const aeroflot& D);
        friend istream& operator>>(istream& s_in, aeroflot& D);
    //������ � �������
        friend void importA(char *F, aeroflot *B, int n);
        friend void exportA(char *F, aeroflot *B, int n)
};

#endif AEROFLOT_H