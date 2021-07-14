#include <cctype>
#include <iostream>
#include <cstring>

int countVowels(const char*);
int length(const char*);
int countConsonants(const char* str);
int countAlnum(const char* str);
void toUpper(char*, unsigned int);

int main(){
    const int LENGTH = 10;
    char str[LENGTH];
    std::cin.getline(str, LENGTH);
    std::cout << "You have entered: " << str << std::endl;
    int len = length(str);
     std::cout << len << std::endl;
     int count = countVowels(str);
     std::cout << count << std::endl;
     std::cout << countAlnum(str) << std::endl;
     toUpper(str, len);
     std::cout << str << std::endl;
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



int countAlnum(const char* str){
    int count = 0;
    for (const char* i = str; *i != '\0'; i++){
        if (isalnum(*i)){
            count++;
        }
    }
    return count;
}

void toUpper(char* str, unsigned int size){

    for (size_t i = 0; i < size; i++){
        if (isalnum(str[i])){
            str[i] = toupper(str[i]);
        }

    }


}