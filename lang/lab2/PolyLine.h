#ifndef POLYLINE_H
#define POLYLINE_H

class PolyLine : public Line{
        int n;
        float *L;
    public:
        PolyLine(){}
        PolyLine(float L){l = L;}
        PolyLine(PolyLine &B);
        virtual ~PolyLine(){delete[] L;}

        string myName() override {return "PolyLine\n";}
        
        //ввод-вывод
        float length() override {
            float LM = 0;
            for (int i = 0; i<n; i++){
                LM+=L[i];
            }
            LM += Line::length();
            return LM;
        }

        void set() override;
        void get() const override;

};

#endif //POLYLINE_H
