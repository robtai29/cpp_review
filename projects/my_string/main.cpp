#include "MYString.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void bubblesort(vector<MYString>& v){
    int n = v.size();
    for (int i = 0; i < n; i++){
        for (int j = 1; j < n - i; j++){
            if (v[j-1] > v[j]){
                swap(v[j-1], v[j]);
            }
        }
    }

}

int main(){

    ifstream input;
    input.open("file.txt");
    if (input.fail()){
        cout << "File error" << endl;
    }

    MYString s;

    vector<MYString> v;
    int count = 0;
    v.push_back(MYString());
    int index = 0;
    while (input >> s){
        if (count == 2){
            v.push_back(MYString());
            count = 0;
            index++;
        }
        if (count < 2){
        v[index] = v[index] + s;
        count++;
        }
    }
    
    for (MYString& str : v){
        cout << str << endl;
    }

  bubblesort(v);
    cout << "\nSorted\n";
    for (MYString str : v){
        cout << str << endl;
    }
    
}


