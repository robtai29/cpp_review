#ifndef POLY_H
#define POLY_H
#include <iostream>

class Poly{

    public:
        Poly();
        Poly(int coeff, int expo);
        Poly(int coeff);
        Poly(const Poly& other);
        ~Poly();

        bool operator==(const Poly& other);
        bool operator!=(const Poly& other);
        Poly& operator=(const Poly& other);
        friend std::ostream& operator<<(std::ostream&, const Poly& p);
        
void resize(int newSize);
    void setCoeff(int expo, int coeff);
    int getCoeff(int);


    private:
        int* arr;
        int size;
        //resize only works if newSize is greater than existing size
        




};





#endif