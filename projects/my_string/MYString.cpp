#include "MYString.h"

std::ostream& operator<<(std::ostream& output, const MYString& mystr){
    for (int i = 0; i < mystr.end; i++){
        output << mystr[i];
    }
    return output;
}

std::istream& operator>>(std::istream& input, MYString& mystr){
    int maxbuffer = 99;
    char temp[maxbuffer]; //read up to 99
    if (input.fail()){
        return input;
    }

    char ch;
    int count;
    for (count = 0; count < maxbuffer && input.get(ch); count++){
        if (!isalnum(ch)){
            count--;
            break;
        }
        temp[count] = ch;
    }
    mystr.clear();
    mystr.end = count + 1;
    mystr.cap = MYString::requiredCap(mystr.end);

    mystr.str = new char[mystr.cap];
    int end = mystr.end;
    for (int i = 0; i < end; i++){
        mystr.str[i] = temp[i];
    }

    mystr.str[mystr.end] = '\0';

    return input;
}

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
    cap = rhs.cap;
    end = rhs.end;
    str = new char[cap];
    for (int i = 0; i < end; i++){
        str[i] = rhs.str[i];
    }
}

MYString::~MYString(){
    clear();
}

void MYString::clear(){
    cap = 0;
    end = 0;
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

int MYString::requiredCap(int end){
    end = end + 1;
    if (end % 20 == 0){
        return end;
    }

    return ((end / 20) + 1) * 20; 
}

MYString& MYString::operator=(const MYString& rhs){
    if (this == &rhs){
        return *this;
    }

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

MYString MYString::operator+(const MYString& rhs){
    MYString temp;
    temp.clear();
    MYString& lhs = *this;
     temp.end = lhs.end + rhs.end;
    temp.cap = requiredCap(temp.end);
    temp.str = new char[temp.cap];

    int index = 0;
    for (; index < lhs.end; index++){
        temp.str[index] = lhs[index];
    }

    for (int i = 0; i < rhs.end; i++){
        temp.str[index] = rhs[i];
        index++;
    }
    
    temp.str[temp.end] = '\0';
    return temp;
}

int MYString::compareTo(const MYString& rhs){

for (int i = 0; i < end || i < rhs.end; i++){
    int lhsChar = i < end ? (int)str[i] : 0;
    int rhsChar = i < rhs.end ? (int)rhs.str[i] : 0;

    if (lhsChar > rhsChar){
        return 1;
    }

    if (lhsChar < rhsChar){
        return -1;
    }
}

return 0;
}

int MYString::operator==(const MYString& rhs){
    return compareTo(rhs) == 0;
}

int MYString::operator>(const MYString& rhs){
    return compareTo(rhs) > 0;
}

int MYString::operator<(const MYString& rhs){
    return compareTo(rhs) < 0;
}

const char* MYString::c_str(){
    return str;
}
