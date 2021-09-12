#include "LongInt.h"

LongInt::LongInt(){
    negative = false;
}

LongInt::LongInt(const string& str){
    string temp(str);
    int stringItr = 0;
    if (temp[0] == '-'){
        negative = true;
        stringItr =1;
    }else{
        negative = false;
    }

    for (; stringItr < temp.length(); stringItr ++){
        char ch = temp[stringItr];
        deque_.addBack(ch);
    }
}

LongInt::LongInt(const LongInt& rhs){
    negative = rhs.negative;
    deque_ = rhs.deque_;
}

ostream& operator<<(ostream& out, const LongInt& num){
    LongInt temp = num;
    int size = temp.deque_.size();
    if (temp.negative == true){
        out << '-';
    }

    for (int i= 0; i < size; i++){
        char ch = temp.deque_.getFront();
        temp.deque_.removeFront();
        out << ch;
        
    }
    return out;
}


LongInt::~LongInt(){
    deque_.clear();
}



//assignment operator
LongInt& LongInt::operator=(const LongInt& rhs){
    negative = rhs.negative;
    deque_ = rhs.deque_;

    return *this;
}

bool LongInt::operator==(const LongInt& rhs) const{
    if (deque_.size() != rhs.deque_.size() || negative != rhs.negative){
        return false;
    }

    Deque<char> lhsD = deque_;
    Deque<char> rhsD = rhs.deque_;

    while(!rhsD.isEmpty() && !lhsD.isEmpty()){
        char leftChar = lhsD.getFront();
        char rightChar = rhsD.getFront();

        lhsD.removeFront();
        rhsD.removeFront();

        if (leftChar != rightChar){
            return false;
        }
    }
    return true;
}

bool LongInt::operator!=(const LongInt& rhs) const {
    return !(*this== rhs); 
}

bool LongInt::operator<(const LongInt& rhs) const{
    


}



