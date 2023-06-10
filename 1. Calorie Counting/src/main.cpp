#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "linkedlist/linkedlist.h"

using namespace std;

int main(){
    ifstream in("input.txt");

    if (in.fail()) {
        cout<<"Error: File not found!\n";
        exit(1);
    }

    string line;
    LinkedList list;

    for(int count = 0; getline(in, line); ){
        if(line != "") count += stoi(line);

        if(in.peek() == '\n' || in.peek() == EOF){
            list.add(count);
            count = 0;
        }
    }
    
    int tot = 0;

    for(int i = 0, max; i < 3; i++){     
        max = list.max();
        list.erase(max);

        tot += max;
    }

    cout<<"Total = " << tot;
}
