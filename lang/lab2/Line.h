#ifndef LINE_H
#define LINE_H

class Line{
        int l;
    public:
        Line(){}
        Line(int L){l = L;}
        Line(Line &B);
        virtual ~Line(){}
        
        virtual int lenght(){}


};
class ColoredLine : private Line{
        int r,g,b;
    public:
        int lenght(){
            return l;
        }

};
class PolyLine : private Line{
    int n;
    int *L;
};
class Picture{
    int n;
    int *p;
};

#endif //AEROFLOT_H