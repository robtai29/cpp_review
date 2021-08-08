/******************************************************************************
Rob Tai
8.8.2021
*******************************************************************************/

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;

class complex{
    friend ostream& operator <<(ostream&, const complex&);
    friend istream& operator>>(istream& input, complex&);
    
    public:
        complex(double = 0, double = 0);
        
        double getReal();
        double getImaginary();
        
        complex operator+(const complex&) const;
        complex operator-(const complex&) const;
        complex operator*(const complex&) const;
        complex operator/(const complex&) const;
        
        complex& operator+=(const complex&);
        complex& operator-=(const complex&);
        complex& operator*=(const complex&);
        complex& operator/=(const complex&);
    
        bool operator==(const complex&) const;  
        bool operator!=(const complex&) const;
        
        complex conjugate() const;
        
    private:
        double real;
        double imaginary;
};

#endif