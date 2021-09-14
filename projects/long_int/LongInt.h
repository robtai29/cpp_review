#ifndef LONGINT_H
#define LONGINT_H
#include "deque.h"
#include <iostream>
#include <string>

using namespace std;

class LongInt{

    friend ostream& operator<<(ostream&, const LongInt&);
    friend istream& operator>>(istream&, LongInt&);

    public:
        LongInt();
        LongInt(const LongInt&);  //copy constructor
        LongInt(const string&);

        //destructor
        ~LongInt();

        //arithmetic operator
        LongInt operator+(const LongInt&);
        LongInt operator-(const LongInt&);

        //assignment operator
        LongInt& operator=(const LongInt&);

        //logical operator
  // Logical binary operators
  bool operator< ( const LongInt & rhs ) const;
  bool operator<=( const LongInt & rhs ) const;
  bool operator> ( const LongInt & rhs ) const;
  bool operator>=( const LongInt & rhs ) const;
  bool operator==( const LongInt & rhs ) const;
  bool operator!=( const LongInt & rhs ) const;

    private:
        Deque<char> deque_;
        bool negative;
        int compareTo(const LongInt & rhs) const;
        int compareToMagnitude(const LongInt & rhs) const;
        void removeZeroes();
};




#endif