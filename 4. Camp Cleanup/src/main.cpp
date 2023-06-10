#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include "linkedlist/linkedlist.h"
using namespace std;

bool in(const int n, const int min, const int max){
    return n >= min && n <= max;
}

bool check(const int a, const int b, const int c, const int d){
    return in(a, c, d) || in(b, c, d) || in(c, a, b) || in(d, a, b);
}

int main(){
    ifstream in("input.txt");

    int count = 0, a, b, c, d;

    string line;

    while(in >> line){
        sscanf(line.c_str(), "%d-%d,%d-%d", &a, &b, &c, &d);
        count += check(a, b, c, d);
    }

    cout << count << endl;
}