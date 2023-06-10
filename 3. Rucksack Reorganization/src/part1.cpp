#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedlist/linkedlist.h"
using namespace std;

#define MAX 52

int getPriority(char type){
    if(type <= 'z' && type >= 'a') return type - 'a';
    if(type <= 'Z' && type >= 'A') return type - 'A' + MAX / 2;
    return -1;
}

char getChar(int index){
    return index + ( (index < MAX / 2)? 'a' : 'A' - MAX / 2);
}

char findItem(string sack){

    int len = sack.size() / 2;

    int first[MAX]{}, second[MAX]{};

    for(int i = 0; i < len; i++){ 
        first [getPriority(sack[i]      )]++; 
        second[getPriority(sack[i + len])]++;
    }

    for(int i = 0; i < MAX; i++){
        if(first[i] > 0 && second[i] > 0) return getChar(i);
    }
    
    return 0;
}
int main(){
    ifstream in("input.txt");

    int sum = 0;
    string sack;

    while(in >> sack){
        sum += getPriority(findItem(sack)) + 1;
    }

    cout << "Total = " << sum;
}