#pragma once
#ifndef COMPLEX_H

using namespace std;
class complex 
{ 
private: 
    double real, img; 
public:  
    complex() { real = 0; img = 0; }
    complex(double r, double i) { real = r; img = i; }  
    complex(const complex &ob){ real = ob.real; img = ob.img; };      
    complex& operator = (complex); 
    complex operator + (complex);
    complex operator - (complex);
    complex& operator += (complex); 
    complex& operator -= (complex); 
    bool operator == (complex& com);  
    bool operator != (complex& com);
    bool operator > (const complex& com); 
    bool operator < (const complex& com);
    
    friend istream& operator>>(std::istream&, complex&); 
    friend ostream& operator<< (std::ostream&, const complex&);

    bool operator < (const float I);
    bool operator > (const float I);
    complex& operator = (const float I); 
    friend float operator+= (float &I, complex& comp);
    
};   

#endif //COMPLEX_H