#ifndef COLOREDLINE_H
#define COLOREDLINE_H

class ColoredLine : public Line{
        int r,g,b;
    public:
        ColoredLine(){}
        ColoredLine(float L) : Line(L) {}
        ColoredLine(ColoredLine &B);
        virtual ~ColoredLine(){}

        string myName() override {return "ColoredLine";}
        //ввод-вывод
        void setColor();
        void getColor();
        void set(istream& s_in) override;
        ostream& get(ostream& s_out) const override;

        virtual void operator=(const ColoredLine B) ;
};

#endif //COLOREDLINE_H
