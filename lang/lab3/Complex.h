#pragma once
#ifndef COMPLEX_H

class Complex{
        double a,b;
    public:
        Complex(){a = 0; b = 0;}
        Complex(double r, double i){a = r; b = i;}
        Complex(Complex& B){a = B.a; b = B.b;}

        Complex& operator=(Complex B);
};

#endif //COMPLEX_H