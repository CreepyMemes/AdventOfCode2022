#include "stack.h"

// Constructor to initialize the stack
Stack::Stack() : top(-1) {}

// Function to add an element 'value' to the stack
void Stack::push(const int value){

    if(isFull()){
        std::cerr << "Error: Stack Overflow!" << std::endl;
        exit(1);
    }

    data[++top] = value;
}

// Reverse the order of the elements of the stack
void Stack::reverse(){
    for(int i = 0; i < (top + 1) / 2; i++){
        swap(data[i], data[top - i]);
    }
}

// Function to pop and return the top element of the stack
int Stack::pop(){
    if(isEmpty()){
        std::cerr << "Error: Stack Underflow!" << std::endl;
        exit(1);
    }

    return data[top--];
}

// Function to return the top element of the stack
int Stack::peek(){
    if(isEmpty()){
        std::cerr << "Error: Stack is Empty!" << std::endl;
        exit(1);
    }

    return data[top];
}

// Function to print all the elements of the stack
void Stack::print(){
    std::cout << "[";
    for(int i = 0; i <= top; i++){
        std::cout << data[i];
        
        if(i != top) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Function that returns the size of the stack
int Stack::size(){
    return top + 1;
}

// Function that checks if the stack is empty
bool Stack::isEmpty(){
    return top == -1;
}

// Function that checks if the stack is full
bool Stack::isFull(){
    return top == MAX_STACK_SIZE - 1;
}

//----------------------------- PRIVATE METHODS --------------------------

// Swap two characters passed by reference
void Stack::swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}