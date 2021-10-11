#include "MYString.h"

MYString::MYString(){
    cap = INITIAL_CAP;
    str = new char[cap];
    end = 0;
    str[end] = '\0';
}

MYString::MYString(const char* rhs){
    end = getLength(rhs);
    cap = requiredCap(end);
    str = new char[cap];

    for (int i = 0; i < end; i++){
        str[i] = rhs[i];
    }
    str[end] = '\0';
}

MYString::MYString(const MYString& rhs){
    clear();
    *this = rhs;
}

MYString::~MYString(){
    clear();
}

void MYString::clear(){
    cap = 0;
    delete[] str;
    str = nullptr;
}

int MYString::getLength(const char* str){
    int length = 0;
    if (str == nullptr){
        return 0;
    }

    const char* newPtr = str;
    while (*newPtr != '\0'){
        length++;
        newPtr++;
    }
    return length;
}

int MYString::length() const{
    return end;
}

int MYString::capacity() const{
    return cap;
}

int MYString::requiredCap(int len){
    if ((len + 1) % 20 == 0){
        return len + 1;
    }

    return (((len + 1) / 20) + 1) * 20; 
}

MYString& MYString::operator=(const MYString& rhs){
    clear();
    cap = rhs.cap;
    end = rhs.end;
    str = new char[cap];

    for (int i = 0; i < end; i++){
        str[i] = rhs[i];
    }

    str[end] = '\0';
    return *this;
}

char& MYString::operator[](int index){
    //no error checking
    return str[index];
}

const char& MYString::operator[](int index) const{

    return str[index];
}

const char* MYString::c_str(){
    return str;
}