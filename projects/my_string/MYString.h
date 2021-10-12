#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

class MYString{
    friend std::ostream& operator<<(std::ostream&, const MYString&);
    friend std::istream& operator>>(std::istream&, MYString&);
    private:
        static const int INITIAL_CAP = 20;
        char* str;
        static int getLength(const char*);
        int cap;  //capacity of the char array, in multiples of 20
        int end;  // location of the null terminator
        int compareTo(const MYString& rhs);
        void clear();  // to manually free memory
        static int requiredCap(int end);
    
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

        MYString operator+(const MYString& rhs);

        int operator==(const MYString& rhs);
        int operator>(const MYString& rhs);
        int operator<(const MYString& rhs);
};

#endif