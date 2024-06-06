#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <cstdlib>
using namespace std;

class node {
    public:
    string first, last, food, seat;
    int id;
    node* next;
    node(){// default
        first = "";
        last = "";
        food = "";
        seat = "";
        id = 0;
        next = nullptr;
    }
    node(int phone, string f, string l, string fo, string s){
        first = f;
        last = l;
        food = fo;
        seat = s;
        id = phone;
        next = nullptr;
    };
};


class linked_list {
    friend class reservation; // gives reservation class access to private linked list attributes (prev, curr, head, cnt)
    public:
    linked_list(); // Constructor
    bool insert_first(node*); // Insert before first node
    bool insert_last(node*); // Put node at end
    bool insert_in_order(node*); // Insert in ascending order
    bool search(int key); // Search for specific node
    bool delete_node(node*); // Delete node
    int size_list(); // Return number of nodes
    void print_list(); // Print all data in the list
    void copy_list(linked_list& new_list); // Copy a list
    
    private:
    node *prev, *head, *curr;
    int cnt;
};

#include "linked_list.cpp"
#endif