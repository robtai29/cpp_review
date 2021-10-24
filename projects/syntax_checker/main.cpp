#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int checkSyntax(string file){
    GenStack<char> s;
    string str;
    int line = 0;
    ifstream input;
    input.open(file);
    while (input >> str){
        line++;
        for (char ch : str){
            if (ch == '[' || ch == '(' || ch == '{'){
                s.push(ch);
            }else if (ch == ']' || ch == ')' || ch == '}'){
                if (s.empty()){
                    return line;
                }
                char match = s.top();

                if ((ch == ']' && match == '[') || (ch == ')' && match == '(') ||
                     (ch == '}' && match == '{')){
                         s.pop();
                     }else{
                         return line;
                     }
            }
        }
    }

    return s.empty() ? 0 : -1;
}

int main(int argc, char* argv[]){

    if (argc < 2){
        cout << "invalid argument" << endl;
    }else{

    string filename = argv[1];

    int res = checkSyntax(filename);

    if (res == 0){
        cout << "No issue with syntax";
    }else if (res == -1){
        cout << "Reached end of file";

    }else{
        cout << "issue on line " << res << endl;
    }
    }
}