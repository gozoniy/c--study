#ifndef COLOREDLINE_H
#define COLOREDLINE_H

class ColoredLine : public Line{
        int r,g,b;
    public:
        ColoredLine(){}
        ColoredLine(float L) : Line(L) {}
        ColoredLine(ColoredLine &B);
        virtual ~ColoredLine(){}

        string myName() override {return "ColoredLine\n";}
        //ввод-вывод
        void setColor();
        void getColor();

        virtual void operator=(const ColoredLine B) ;
        friend ostream& operator<<(ostream& s_out, const ColoredLine& D);//~
        friend istream& operator>>(istream& s_in, ColoredLine& D);//~


};

#endif //COLOREDLINE_H
