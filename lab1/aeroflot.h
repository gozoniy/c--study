#ifndef AEROFLOT_H
#define AEROFLOT_H

class aeroflot{
        char destination[20];
        char index[20];
        char type[20];
        char day[20];
        int time;
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
        //void DEST(aeroflot *B, int n, char *D);

};

#endif AEROFLOT_H