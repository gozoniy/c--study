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
        
        void setL();
        void getL() const;
        
};
class ColoredLine : public Line{
        int r,g,b;
    public:
        ColoredLine(){}
        ColoredLine(float L) : Line(L) {}
        ColoredLine(ColoredLine &B);
        virtual ~ColoredLine(){}

        string myName() override {return "ColoredLine\n";}

        void setColor();
        void getColor();

};
class PolyLine : public Line{
        int n;
        float *L;
    public:
        PolyLine(){}
        PolyLine(float L){l = L;}
        PolyLine(PolyLine &B);
        virtual ~PolyLine(){delete[] L;}

        string myName() override {return "PolyLine\n";}
        float length() override {
            float LM = 0;
            for (int i = 0; i<n; i++){
                LM+=L[i];
            }
            LM += Line::length();
            return LM;
        }
};
/*class Picture{
    int n;
    int *p;
};*/

#endif //AEROFLOT_H