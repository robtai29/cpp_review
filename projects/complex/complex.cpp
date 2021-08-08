/******************************************************************************
Rob Tai
8.8.2021
*******************************************************************************/

#include "complex.h"
#include <stdexcept>
#include <cmath>


complex::complex(double real_, double imaginary_) : real(real_), imaginary(imaginary_) {}

double complex::getReal(){
    return real;
}

double complex::getImaginary(){
    return imaginary;
}

istream& operator>>(istream& input, complex& c){
    input >> c.real >> c.imaginary;
    return input;
    
}

ostream& operator << (ostream &output, const complex &c) {
	if (c.real == 0 && c.imaginary ==0) {
		output << "0";
		return output;
	}
	
	if (c.real != 0){
	    output << c.real;
	    
	    if (c.imaginary > 0){
	        output << "+";
	    }
	}
	
	if (c.imaginary == 1){
	    
	    output << "1";
	}else if (c.imaginary == -1){
	    output << "-1";
	}else if (c.imaginary != 0){
	    output << c.imaginary << "i";
	}
	
	return output;
}
complex complex::operator+(const complex& c) const{
    
    complex result;
    result.real = real + c.real;
    result.imaginary = imaginary + c.imaginary;
    return result;
}

complex complex::operator-(const complex& c) const{
    complex result;
    result.real = real - c.real;
    result.imaginary = imaginary - c.imaginary;
    return result;
}

complex complex::operator*(const complex& c) const{
    complex result;
    result.real = real * c.real - imaginary * c.imaginary;
    result.imaginary = real * c.imaginary + imaginary * c.real;
    return result;
}

complex complex::operator/(const complex& c) const{
    if (c.real == 0.0 && c.imaginary == 0.0){
        cout << ("Error Don't divide by zero");
        return *this;
    }
    
    complex result(real, imaginary);
    double denominator = (c * c.conjugate()).getReal();
    
    result *= c.conjugate();
    double x = result.real / denominator;
    double y = result.imaginary /denominator;
    
    return complex{x, y};
}


complex& complex::operator/=(const complex& c){
    *this = (*this)/ c;
    return *this;
}

complex& complex::operator+=(const complex& c){
    *this = (*this) + c; 
    return *this;
}

complex& complex::operator-=(const complex& c){
    *this = (*this) - c; 
    return *this;
}

complex& complex::operator*=(const complex& c){
    *this = (*this) * c; 
    return *this;
}

bool complex::operator==(const complex& c) const{
    return real == c.real && imaginary == c.imaginary;
}

bool complex::operator!=(const complex& c) const{
    return !((*this) == c);
}

complex complex::conjugate() const{
    return complex{real, -imaginary};
}


