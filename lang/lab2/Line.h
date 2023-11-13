#ifndef LINE_H
#define LINE_H

class Line{
    protected:
        float l;
    public:
        Line(){}
        Line(const float L):l(L){};
        Line(const Line &B):l(B.l){};
        virtual ~Line(){}
        
        virtual float length() const{return l;};
        virtual string myName() const{return "Line";}
        //¬вод-вывод
        virtual void set(istream& s_in);
        virtual ostream& get(ostream& s_out) const;
        void operator=(const Line B);
        bool operator>(const Line B)const;
        bool operator<(const Line B)const;
        virtual Line* getCopy() const;
};
ostream& operator<<(ostream& s_out, const Line& D);
istream& operator>>(istream& s_in, Line& D);

#endif //AEROFLOT_H