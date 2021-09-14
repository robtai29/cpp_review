#include "LongInt.h"

LongInt::LongInt(){
    deque_.clear();
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
    deque_.clear();
    *this = rhs;
}

ostream& operator<<(ostream& out, const LongInt& num){
    LongInt temp = num;
    temp.removeZeroes();
    int size = temp.deque_.size();
    if (size == 0 ){
        out << "0";
        return out;
    }

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

istream& operator>>(istream& input, LongInt& num){
    num.deque_.clear();
    num.negative = false;
    
    char ch;
    if (input.fail()){
        return input;
    }

    if (input.get(ch)){
        if (ch == '-'){
        num.negative = true;
        }else if (isdigit(ch)){
            num.deque_.addBack(ch);
        }
    }

    while(input.get(ch) && isdigit(ch)){
        num.deque_.addBack(ch);
    }

    return input;
}


LongInt::~LongInt(){
    deque_.clear();
}



//assignment operator
LongInt& LongInt::operator=(const LongInt& rhs){
    negative = rhs.negative;
    deque_ = rhs.deque_;
    removeZeroes();

    return *this;
}

bool LongInt::operator==(const LongInt& rhs) const{
    return (*this).compareTo(rhs) == 0;
}

bool LongInt::operator!=(const LongInt& rhs) const {
    return (*this).compareTo(rhs) != 0; 
}

bool LongInt::operator>(const LongInt& rhs) const{

    return (*this).compareTo(rhs) > 0;
}

bool LongInt::operator>=(const LongInt& rhs) const{
    return (*this).compareTo(rhs) >= 0;
}

bool LongInt::operator<(const LongInt& rhs) const{
    return (*this).compareTo(rhs) < 0;
}

bool LongInt::operator<=(const LongInt& rhs) const{
    return (*this).compareTo(rhs) <= 0;
}


int LongInt::compareTo(const LongInt & rhs) const{
    if (negative == true && rhs.negative == false){
        return -1;
    }

    if (negative == false && rhs.negative == true){
        return 1;
    }

    int comparison = compareToMagnitude(rhs);

    return negative == false ? comparison : comparison * -1;
}

int LongInt::compareToMagnitude(const LongInt & rhs) const{
    Deque<char> lhsD = deque_;
    Deque<char> rhsD = rhs.deque_;

    while(!lhsD.isEmpty() && lhsD.getFront() == '0'){
        lhsD.removeFront();
    }

    while(!rhsD.isEmpty() && rhsD.getFront() == '0'){
        rhsD.removeFront();
    }

    if (lhsD.size() > rhsD.size()){
        return 1;
    }else if (lhsD.size() < rhsD.size()){
        return -1;
    }else{
        
        while(!lhsD.isEmpty() && !rhsD.isEmpty()){
            int lNum = lhsD.getFront() - '0';
            int rNum = rhsD.getFront() - '0';

            if (lNum > rNum){
                return 1;
            }else if (lNum < rNum){
                return -1;
            }else{
                lhsD.removeFront();
                rhsD.removeFront();
            }

        }
            return 0;


}

}
void LongInt::removeZeroes(){
    if (deque_.size() <= 1){
        return;
    }

    while(!deque_.isEmpty() && deque_.getFront() == '0'){
        deque_.removeFront();
    }

    if (deque_.size() == 0){
        negative = false;
    }

}

LongInt LongInt::operator+(const LongInt& rhs){
    //check for 0 + 0;
    LongInt temp;
    if (deque_.size() == 0 && rhs.deque_.size() == 0){
        return temp;
    }

    if (negative != rhs.negative){
        return (*this);// need to fix
    }

    temp.negative = negative;
    Deque<char> left = deque_;
    Deque<char> right = rhs.deque_;
    int carryover = 0;

    while (!(left.isEmpty() && right.isEmpty())){
        int leftNum = left.isEmpty() ? 0 : left.removeBack() - '0';
        int rightNum = right.isEmpty() ? 0 : right.removeBack() - '0';
        int digit = (leftNum + rightNum + carryover) % 10;
        carryover = (leftNum + rightNum + carryover) / 10;
        temp.deque_.addFront(digit + '0');
    }

    if (carryover == 1){
        temp.deque_.addFront(carryover + '0');
    }
     temp.removeZeroes();
    return temp;
}

LongInt LongInt::operator-(const LongInt& rhs){
    LongInt temp;
    if (deque_.size() == 0 && rhs.deque_.size() == 0){
        return temp;
    }

    if (negative != rhs.negative){
        temp = rhs;
        temp.negative = negative;
        return (*this) + temp;
    }

    int comparison = (*this).compareToMagnitude(rhs);
        Deque<char> top;
        Deque<char> bottom;

    if (comparison == 0){
        return temp;
    }else if (comparison > 0){
        temp.negative = negative == false ? false : true;

        top = deque_;
        bottom = rhs.deque_;
    }else{
        //comparison < 0

        temp.negative = negative == false ? true : false;
        top = rhs.deque_;
        bottom = deque_;
    }
    
    int carryover = 0;
    while (!(top.isEmpty() && bottom.isEmpty())){
        int topNum = top.isEmpty() ? 0 : top.removeBack() - '0';
        int bottomNum = bottom.isEmpty() ? 0 : bottom.removeBack() - '0';
        int digit = topNum + carryover >= bottomNum ? topNum - bottomNum + carryover: topNum + 10 - bottomNum + carryover;
        carryover = topNum + carryover >= bottomNum ? 0 : -1; 

        temp.deque_.addFront(digit + '0');
    }
    return temp;
}


