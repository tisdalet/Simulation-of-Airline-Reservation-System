#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <iostream>
#include <fstream>	// to open database file
#include <cstdlib>
using namespace std;
#include "linked_list.h"	// linked_list class

class reservation
{
	public:
		reservation();
		// constructor initializes data to database
        char menu();
        //reservation system menu  
		void start();
		// starts user input
		void search();
		// allows user to display specific passenger info
		void insert();
		//allows user to make a new passenger reservation
		void remove();
		  // allows user to cancel a reservation
		void print();
		  // prints list of all passengers
		void changeFood();
		  // user can change food preference of passenger
		void changeSeat();
		// user can change seat of passenger if available
		void copyDatabase();
		  // linked_list is initialized to database
	private:
		linked_list mine;
		  // declare an object of the linked list class
		int id;
		  // stores id for search functions		
};

#include "reservation.cpp"	// implementation for class

#endif