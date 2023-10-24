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

};

#endif //COLOREDLINE_H
