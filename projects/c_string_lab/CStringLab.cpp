#include <cctype>
#include <iostream>
#include <cstring>

int countVowels(const char*);
int length(const char*);
int countConsonants(const char* str);
int countAlnum(const char* str);
void toUpper(char*, unsigned int);
char* copyString(char* buffer, unsigned int length);

int main(){
    const int LENGTH = 100;
    
    bool loop = true;
    while (loop){
        char* ptr = nullptr;
        char buffer[LENGTH];
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Your sentence will be capitalized and counted" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Enter a sentence: ";
        std::cin.getline(buffer, LENGTH);
        
        ptr = copyString(buffer, length(buffer));
        std::cout << "\nYou Entered: " << ptr;
        std::cout << "\nThe length is: " << length(ptr)  << std:: endl;

        std::cout << "Number of vowels is: " << countVowels(ptr)  << std:: endl;
        std::cout << "Number of consonants is: " << countConsonants(ptr)  << std:: endl;
        std::cout << "Number of letters and numbers is: " << countAlnum(ptr)  << std:: endl;
        toUpper(ptr, length(ptr));
        std::cout << "Sentence in upper case: " << ptr << std::endl;
        std::cout << "Do you want to continue?  y/n: ";
        char choice = 'n';
        std::cin >> choice;
        std::cin.ignore();
        loop = choice == 'y';
    }

}

char* copyString(char* buffer, unsigned int length){
    char* ptr = new char[length + 1];
    for (int i = 0; i < length + 1; i++){
        ptr[i] = buffer[i];
    }
    ptr[length + 1] = '\n';
    return ptr;
}

int countConsonants(const char* str){
   int count = 0;
    for (const char* i = str; *i != '\0'; i++){
        if (isalpha(*i)){
            char ch = tolower(*i);
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
                count++;
            }
        }
    }
    return count;
}


int countVowels(const char* str){
    int len = length(str);
    int count = 0;
    for (int i = 0; i < len; i++){
        char ch = tolower(str[i]);
        if (ch == 'a' ||ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u'){
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