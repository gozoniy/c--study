#ifndef COLOREDLINE_H
#define COLOREDLINE_H

class ColoredLine : public Line{
        int r,g,b;
    public:
        ColoredLine(){}
        ColoredLine(const float L) : Line(L) {}
        ColoredLine(const ColoredLine &B);
        virtual ~ColoredLine(){}

        string myName() const override  {return "ColoredLine";}
        //ввод-вывод
        void setColor();
        void getColor() const;
        void set(istream& s_in) override;
        ostream& get(ostream& s_out) const override;

        virtual void operator=(const ColoredLine B) ;
};

#endif //COLOREDLINE_H
