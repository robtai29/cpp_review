#include "MYString.h"
#include <iostream>

using namespace std;

int main(){

    cout << "sup" << endl;
    MYString s1("1234567890123456789");
    MYString s2= s1;
    cout << s2.c_str() << endl;
}