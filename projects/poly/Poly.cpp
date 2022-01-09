#include "Poly.h"
#include <iostream>

Poly::Poly(){
    size = 1;
    arr = new int[size];
    arr[0] = 0;

}

Poly::Poly(int coeff, int expo){
    if (expo < 0){
        size = 1;
        arr = new int[size];
        arr[0] = 0;
    }else{

        size = 1 + expo;
        arr = new int[size];
        arr[size -1] = coeff;
        for (int i = 0; i < size -1; i++){
            arr[i] = 0;
        }


    }
}

Poly::Poly(int coeff){
    size = 1;
    arr = new int[size];
    arr[0] = coeff;
}

Poly::Poly(const Poly& other){
    size = other.size;
    arr = new int[size];

    for (int i = 0; i < size; i++){
        arr[i] = other.arr[i];
    }

}

Poly::~Poly(){
    size = 0;
    delete [] arr;
    arr = nullptr;
}

bool Poly::operator==(const Poly& other){
    if (size != other.size){
        return false;
    }

    for (int i = 0; i < size; i++){
        if (arr[i] != other.arr[i]){
            return false;
        }
    }

    return true;
}

bool Poly::operator!=(const Poly& other){
    return !((*this)== other);
}

std::ostream& operator<<(std::ostream& out, const Poly& p){
    out << "size: " << p.size << "  [" << p.arr[0];

    for (int i = 1; i < p.size; i++){
        out << " " << p.arr[i];
    }
    out << "]";
    return out;
}

Poly& Poly::operator=(const Poly& other){
    if (this == &other){
        return *this;
    }

    delete [] this-> arr;
    this-> size = other.size;
    this-> arr = new int[size];
    for (int i = 0; i < size; i++){
        this-> arr[i] = other.arr[i];
    }

    return *this;
}

void Poly::resize(int newSize){
    if (newSize > size){
        int* newArr = new int[newSize];
        for (int i = 0; i < newSize; i++){
            if (i < size){
                newArr[i] = arr[i];
            }else{
                newArr[i] = 0;
            }
        }

        delete [] arr;
        arr = newArr;
        newArr = nullptr;
        size = newSize;
    }

}

    int Poly::getCoeff(int expo) const{
        if (expo < 0 || expo > size -1){
            return 0;
        }

        return this-> arr[expo];
    }

    void Poly::setCoeff(int expo, int coeff){
        if (expo < 0){
            return;
        }

        if (expo > size -1){
            this-> resize(expo + 1);
        }

        (*this).arr[expo] = coeff;
    }

    Poly Poly::operator+(const Poly& other) const{
        if (this-> size > other.size){
            Poly temp = 
        }



        
    }


    Poly Poly::operator-(const Poly& other) const{
        Poly temp(other);
        for (int i = 0; i < other.size; i++){
            temp.arr[i] *= -1;
        }

        return (*this)- other;

    }

int main(){
    Poly a;
    Poly b(3);
    Poly c(3, 3);


    c.setCoeff(6, 1);
    std::cout << c.getCoeff(6);
std::cout << c;
return 0;

}

