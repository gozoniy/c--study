#ifndef POLYLINE_H
#define POLYLINE_H

class PolyLine : public Line{
        int n = 0;
        float *L;
    public:
        PolyLine(){}
        PolyLine(int N){n = N;}
        PolyLine(PolyLine &B);
        virtual ~PolyLine(){delete[] L;}

        string myName() override {return "PolyLine";}
        //ввод-вывод
        float length() override {
            float LM = 0;
            for (int i = 0; i<n; i++){
                LM+=L[i];
            }
            LM += Line::length();
            return LM;
        }
        void set(istream& s_in) override;
        ostream& get(ostream& s_out) const override;
        void operator=(const PolyLine B);
};

#endif //POLYLINE_H
