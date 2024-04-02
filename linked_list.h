#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <cstdlib>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int value){ // Default constructor
        data = value;
        next = nullptr;
    };
};

class linked_list {
    public:
    linked_list(); // Constructor
    bool insert_first(node*); // Insert before first node
    bool insert_last(node*); // Put node at end
    bool insert_in_order(node*); // Insert in ascending order
    bool search(int key); // Search for specific node
    bool delete_node(node*); // Delete node
    int size_list(); // Return number of nodes
    void print_list(); // Print all data in the list
    //void copy_list(); // Copy a list
    
    private:
    node *prev, *head, *curr;
    int cnt;
};
#endif