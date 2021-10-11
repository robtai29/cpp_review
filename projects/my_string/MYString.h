#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MYString{
    private:
        static const int INITIAL_CAP = 20;
        char* str;
        static int getLength(const char*);
        int cap;
        int end;
        int compareTo(const MYString& rhs);
        void clear();
        int requiredCap(int len);
    
    public:
        MYString();
        MYString(const MYString& mystr);
        MYString(const char*);
        ~MYString();

        MYString& operator=(const MYString& rhs);
        char& operator[](int index);
        const char& operator[](int index) const;

        int length() const;
        int capacity() const;
        const char* c_str();

};

#endif