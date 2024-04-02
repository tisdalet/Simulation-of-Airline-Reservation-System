#include <iostream>
#include <cstdlib>
#include <linked_list.h>
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
    else if (head->data > temp->data){
        prev = head;
        curr = head->next;
        while (curr != NULL && curr->data < temp->data) {
            prev = curr;
            curr = curr->next;
        }
        temp->next = curr;
        prev->next = temp;
        return true;
    }
}

bool linked_list::search(int key) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return false;
    }
    else if (head->data == key){
        cout << "Found it at first node." << endl;
        return true;
    }
    else {
        prev = head;
        curr = head->next;
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr == NULL) {
            return false;
        }
        else {
            cout << "Found it at " << cnt << endl;
            return true; 
        }
    }
}

bool linked_list::delete_node(node* temp) {
    if (head == NULL) {
        return false;
    }
    else if (head->data == temp->data) {
        node* del = head;
        head = head->next;
        delete del;
        return true;
    }
    else {
        if (search(temp->data)) {
            prev->next = curr->next;
            return true;
        }
        else {
            return false;
        }
    }
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
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}