#include <iostream>
#include <cstdlib>
#include "linked_list.h"
using namespace std;

linked_list::linked_list(){
    head = nullptr;
    curr = nullptr;
    cnt = 0;
}

bool linked_list::insert_first(node* temp){
    if (head == NULL) {
        head = temp;
        return true;
    }
    else {
        temp->next = head;
        head = temp;
        return true;
    }
}

bool linked_list::insert_last(node* temp){
    if (head == NULL){
        head = temp;
        return true;
    }
    else {
        node* temp2 = head;
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        return true;
    }
}

bool linked_list::insert_in_order(node* temp) {
    if (head == NULL) {
        head = temp;
        return true;
    }
    else if (head->seat > temp->seat){
        prev = head;
        curr = head->next;
        while (curr != NULL && curr->seat < temp->seat) {
            prev = curr;
            curr = curr->next;
        }
        temp->next = curr;
        prev->next = temp;
        return true;
    }
    
  return false;    
}

bool linked_list::search(int key) {
    if (head == nullptr) {
        return false; // List is empty, no need to search
    }
    
    node* temp = head;
    while (temp != nullptr) {
        if (temp->id == key) {
            curr = temp; 
            return true; // Key found
        }
        temp = temp->next;
    }
    
    return false; // Key not found
}

bool linked_list::delete_node(node* temp) {
    if (head == NULL)
	{
		return false;
	}
	else if(head->id == temp->id)
	{
		node* del;
		del = head;
		head = head -> next;
		delete del;
	}
	else{
		node* prev, *curr;
		prev = head;
		curr = head->next;
		while ( curr != NULL && curr->id != temp->id)
		{
			prev = curr;
			curr = curr -> next;
		}
		if (curr != NULL)
		{
			prev->next = curr -> next;
			return true;
		}
		else
			return false;
	}
 return false;	
}
int linked_list::size_list(){
    if (head == NULL) {
        return 0;
    }
    else {
        node* temp = head;
        while (temp != head){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
}

void linked_list::print_list() {
    if (head == NULL) {
        cout << "List is empty." << endl;
    }
    else {
        node* temp = head;
        while (temp != NULL){
            cout << temp->first<< " ";
            temp = temp->next;
        }
    }
    
}
void linked_list::copy_list(linked_list& new_list) {
    if (head == nullptr) { // If list is empty
        cout << "List is empty. Cannot copy." << endl;
        return;
    }

    node* temp = head;
    while (temp != nullptr) { // For the length of original list
        node* new_node = new node(temp->id, temp->first, temp->last, temp->food, temp->seat); // Make new node
        
        if (new_list.head == nullptr) { // Make first node the head
            new_list.head = new_node;
        } 
        else {
            node* last_node = new_list.head; // Starting at head
            while (last_node->next != nullptr) { // Find last node
                last_node = last_node->next;
            }
            last_node->next = new_node; // Add the new node
        }
        
        temp = temp->next; // Go to next node in temp
    }
    
    new_list.cnt = this->cnt;
}