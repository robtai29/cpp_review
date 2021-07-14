#include <cctype>
#include <iostream>
#include <cstring>

int countVowels(const char*);
int length(const char*);
int countConsonants(const char* str);
int countAlnum(const char* str);
const char* toUpper(const char*);

int main(){
    const int LENGTH = 10;
    char str[LENGTH];
    std::cin.getline(str, LENGTH);
    std::cout << "You have entered: " << str << std::endl;
    int len = length(str);
     std::cout << len << std::endl;
     int count = countVowels(str);
     std::cout << count << std::endl;
}

int countConsonants(const char* str){
    return 26 - countVowels(str);
}

int countVowels(const char* str){
    int len = length(str);
    int count = 0;
    for (int i = 0; i < len; i++){
        if (str[i] == 'o' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u'){
            count++;
        }
    }
    return count;
}

int length(const char* str){
    const char* end = str;
   for( ; *end != '\0'; ++end){

   }
      
   return end - str;
}

const char* toUpper(const char*){


}

int countAlnum(const char* str){
    int count;
    for (int i = str; *i != '\n'; i++){
        if (isalnum(*i)){
            count++;
        }
    }
    return count;
}