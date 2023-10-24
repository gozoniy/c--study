#ifndef LINE_H
#define LINE_H

class Line{
    protected:
        float l;
    public:
        Line(){}
        Line(float L){l = L;}
        Line(Line &B);
        virtual ~Line(){}
        
        virtual float length();
        virtual string myName(){return "Line\n";}
        //¬вод-вывод
        virtual void set();
        virtual void get() const;
        void operator=(const Line B);
        bool operator>(const Line B);
        bool operator<(const Line B);

        friend ostream& operator<<(ostream& s_out, const Line& D);//~
        friend istream& operator>>(istream& s_in, Line& D);//~

        //дописать сюда функцию заполнени€ массива указателей объектов лайн
        //virtual void () = 0;
};


#endif //AEROFLOT_H