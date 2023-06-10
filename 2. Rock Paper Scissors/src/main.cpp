#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedlist/linkedlist.h"
using namespace std;

char decr(char choice){ return (choice + 2) % 3; }
char incr(char choice){ return (choice + 1) % 3; }

int getPoints(char opp, char mine){
    if(opp == mine)       return mine + 4;
    if(opp == decr(mine)) return mine + 7; 
    return mine + 1; 
}

char getChoice(char opp, char mine){
    if(mine == 'Y') return opp;
    if(mine == 'Z') return incr(opp);
    if(mine == 'X') return decr(opp);
    return -1;
}

int main(){
    ifstream in("input.txt");

    int points = 0;
    char opp, mine;

    while(in >> opp >> mine){
        opp -= 'A';
        points += getPoints(opp, getChoice(opp, mine));
    }    

    cout << "Points = " << points;
}