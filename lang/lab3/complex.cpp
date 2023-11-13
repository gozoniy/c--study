#include <iostream>
#include "complex.h"

bool complex::operator != (complex& comp) {  
    if(this->real != comp.real || this->img != comp.img) 
       return 1; 
    else  
        return 0;
}
 
bool complex::operator==(complex& comp){  
    if(this->real == comp.real && this->img == comp.img) 
        return 1; 
    else 
        return 0;
}

complex& complex::operator =(complex comp){  
    this->real = comp.real; 
    this->img = comp.img; 
    return *this;
} 
complex& complex::operator = (const float I){
    real = I;
    return *this;
}
 
complex complex::operator+(complex comp){ 
    this->real = this->real + comp.real; 
    this->img = this->img + comp.img; 
    return *this;
} 
 
complex complex::operator-(complex comp){ 
    this->real = this->real - comp.real; 
    this->img = this->img - comp.img; 
    return *this;
}

complex& complex::operator+=(complex comp){ 
    real += comp.real; 
    img += comp.img; 
    return *this;
}

//перегрузка дружественного +=
float operator+= (float &I, complex& comp){
    I = I + comp.real;
    return I;
}
 
complex& complex::operator-=(complex comp){ 
    real -= comp.real; 
    img -= comp.img; 
    return *this;
}

bool complex:: operator > (const complex& com) 
{  
    if(this->real > com.real) 
        return 1; 
    else if(this->real == com.real && this->img > com.img) 
        return 1; 
    else 
        return 0;
}
 
bool complex ::operator < (const complex& com) 
{ 
    if(this->real < com.real) 
        return 1; 
    else if(this->real == com.real && this->img < com.img) 
        return 1; 
    else 
        return 0;
 
}
bool complex::operator < (const float I) 
{ 
    if(real < I)
        return 1;
    else 
        return 0;
 
}
bool complex::operator > (const float I) 
{ 
    if(real > I)
        return 1;
    else 
        return 0;
 
}

ostream& operator << (std::ostream& out, const complex& com) 
{  
    if (&out == &cout){
        if(com.img < 0) 
            out << com.real << " + i(" << com.img << ")"; 
        else 
            out << com.real << " + i" << com.img ; 
    }
    else{
            out << com.real <<" " << com.img; 
    }
    return out;
} 
 
istream& operator >> (std::istream& in, complex& com) 
{   
    in >> com.real; 
    in >> com.img;
    return in; 
}