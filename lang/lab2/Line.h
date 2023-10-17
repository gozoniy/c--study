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
        
        //дописать сюда функцию заполнени€ массива указателей объектов лайн
};


#endif //AEROFLOT_H