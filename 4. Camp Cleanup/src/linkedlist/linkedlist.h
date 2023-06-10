#pragma once

#include <iostream>

class Node{

    public:
        int data;
        Node *next;

        Node(int value);         
};

class LinkedList{ 
        
    public:
        LinkedList();

        void push(const int value);
        void add(const int value);
        void remove();
        void pop();
        void erase(const int value);
        int  size() const;
        int  max() const;
        void print();

        int& operator[](const int index);  

    private:
        Node *head;
        int& at(const int index);  
};