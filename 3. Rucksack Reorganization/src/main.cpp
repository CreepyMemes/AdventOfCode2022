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

char findItem(string sack1, string sack2, string sack3){

    int first[MAX]{}, second[MAX]{}, third[MAX]{};

    for(auto i: sack1){ first [getPriority(i)]++; }
    for(auto i: sack2){ second[getPriority(i)]++; }
    for(auto i: sack3){ third [getPriority(i)]++; }

    for(int i = 0; i < MAX; i++){
        if(first[i] > 0 && second[i] > 0 && third[i] > 0) return getChar(i);
    }
    
    return 0;
}
int main(){
    ifstream in("input.txt");

    int sum = 0;
    string sack1, sack2, sack3;

    while(in >> sack1 >> sack2 >>sack3){
        sum += getPriority(findItem(sack1, sack2, sack3)) + 1;
    }

    cout << "Total = " << sum;
}