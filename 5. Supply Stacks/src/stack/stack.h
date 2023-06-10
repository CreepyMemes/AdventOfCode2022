#pragma once

#include <iostream>

const int MAX_STACK_SIZE = 100;

class Stack{
    public:
        Stack();

        void push(const int value);
        void reverse();
        void print();

        int pop();
        int peek();
        int size();

        bool isEmpty();
        bool isFull();
            
    private:
        int top;
        char data[MAX_STACK_SIZE];

        void swap(char &a, char &b);
};
