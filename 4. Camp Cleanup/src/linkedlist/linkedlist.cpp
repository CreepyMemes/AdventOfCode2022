#include "linkedlist.h"


Node::Node(int value) : data(value), next(nullptr) {}          

LinkedList::LinkedList() : head(nullptr) {}

// Pushes a new Node at the beginning of the List
void LinkedList::push(const int value){
    Node *newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        return;
    }
    
    newNode->next = head;
    head = newNode;
}

// Adds a new Node at the ending of the List
void LinkedList::add(const int value){
    Node *newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        return;
    }
    
    Node *current = head;

    while(current->next != nullptr){
        current = current->next;
    }

    current->next = newNode;   
}

// Removes the first Node of the List
void LinkedList::remove(){
    if(head == nullptr) return;
    
    Node *temp = head->next;

    delete head;
    head = temp;
}

// Removes the last Node of the List
void LinkedList::pop(){
    if(head == nullptr) return;

    if(head->next == nullptr){
        this->remove();
        return;
    }

    Node *current = head;
    Node *prev    = nullptr;

    while(current->next != nullptr){
        prev    = current;
        current = current->next;
    }

    delete current;
    prev->next = nullptr;
}

// Removes the first Node that has a certain value give by argument
void LinkedList::erase(const int value){
    if(head == nullptr) return;

    if(head->data == value) {
        this->remove();
        return;
    }

    Node *current = head;
    Node *prev    = nullptr;

    while( (current->next != nullptr) && (current->data != value) ){
        prev    = current;
        current = current->next;
    }

    if(current->data == value){
        prev->next = current->next;
        delete current;
    }
}

// Counts how many Nodes are present in the List
int LinkedList::size() const{
    Node *current = head;

    int size = 0;
    for(; current != nullptr; size++){
        current = current->next;
    }

    return size;
}

// Overloads ooperator to return a reference to the value of a Node at index given by argument
int& LinkedList::operator[](const int index){
    return this->at(index);
}

// Returns the maximum value held by one of the Nodes of this List
int LinkedList::max() const{
    Node *current = head;

    int max = INT_MIN;
    while(current != nullptr){
        max = max < current->data? current->data : max;
        current = current->next;
    }
    
    return max;
}

// Prints the all the Nodes of the List
void LinkedList::print(){
    Node *current = head;

    std::cout <<"[";
    while(current != nullptr){
        std::cout << current->data; if(current->next != nullptr) std::cout << ", ";
        current = current->next;
    }
    std::cout <<"]\n";
}

// Returns the value of a Node at index given by argument
int& LinkedList::at(const int index){
    Node *current = head;

    for(int i = 0; current != nullptr; i++){
        if(i == index) return current->data;
        current = current->next;
    }    

    std::cerr << "\nError: Index out of bounds!\n";
    exit(1);
}