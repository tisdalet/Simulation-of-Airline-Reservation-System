#include <iostream>
#include <cstdlib>
#include "reservation.h"
#include "linked_list.h"
using namespace std;


reservation::reservation() 
{
    
}

char reservation::menu() {
/*  This is the menu for the user. The menu displays the choices the user has. 
The user will enter a character, and that character will be returned to be
used in the start function of the reservation class.*/
	string choice;

	cout << "\n\t\tMenu\n";
	cout << "\t 1\tEnter a reservation\n";
	cout << "\t 2\tCancel a reservation\n";
	cout << "\t 3\tPrint a passenger list\n";
	cout << "\t 4\tSearch for a passenger\n";
	cout << "\t 5\tChange Reservation Seat\n";
	cout << "\t 6\tChange Reservation Food\n";
	cout << "\t 0\tEXIT\n";
	
	cout << "\nEnter your choice: ";
	cin  >> choice;	// user input
	cin.ignore();
	
	return choice[0];	// returns user input
}

void reservation::start() 
{
    bool done = false;	// done boolean

	do{
	
		char choice = menu(); //get the choice from the user
		switch(choice)
		/*this switch compares the choice entered
		  by the user to determine which function
 		  to call.
			*/
		{
			case '1': insert(); break;
			case '2': remove(); break;
			case '3': print(); break;
			case '4': search(); break;
			case '5': changeSeat(); break;
			case '6': changeFood(); break;
			case '0': done = true; break;
		default: cout << "INVALID INPUT" << endl;
		}
	} while(!done); // if done, then quit, else continue

	cout << "\nThank you for using my simulation." << endl;
}

void reservation::search() 
{
	int id_input; //for getting ID from input
	cout<<"Enter reservation ID: ";
	cin>>id_input;
	cin.ignore();
	
	if(mine.search(id_input))
	{
		cout<<"Name: "<<mine.curr->first<<" "<<mine.curr->last<<endl;
		cout<<"Food: "<<mine.curr->food<<endl;
		cout<<"Seat: "<<mine.curr->seat<<endl;
	}
	else
		cout<<"Reservation not found."<<endl;
}

void reservation::insert() 
{
    node* temp;
	temp = new node;
	int id_input; //storing passenger ID from input for checking if ID is already used
	
	cout<<"Enter first name for reservation: ";
	getline(cin, temp->first);
	
	cout<<"Enter last name for reservation: ";
	getline(cin, temp->last);
	
	cout<<"Enter food item: ";
	getline(cin, temp->food);
	
	cout<<"Enter seat number: ";
	getline(cin, temp->seat);
	
	cout<<"Enter passenger ID: ";
	cin>>id_input;
	cin.ignore();

	if(!mine.search(id_input)) //true when ID is not found
		{
			temp->id = id_input;
		}
	else //ID has been used already, so prompt user for another ID to use
		while(mine.search(id_input))
			{
				cout<<"That ID has been used, please choose another reservation ID: "<<endl;
				cin>>id_input;
				cin.ignore();
			}
	temp->id = id_input;
	mine.insert_last(temp);		
}

void reservation::remove() 
{
    int id_input; //for storing passenger ID
    
    cout<<"Please enter passenger ID: ";
    cin>>id_input;
    cin.ignore();
    
    if(mine.search(id_input)) //checking if passenger is in the list
    {
    	mine.delete_node(mine.curr);
    	cout<<"Reservation has been removed."<<endl;
    }
    else
    	cout<<"Reservation not found."<<endl;
}

void reservation::print() 
{
   mine.print_list(); //only prints out passenger ID
}

void reservation::changeFood() { 
	int key; // this may not be needed if we set the passenger id
	cout << "Enter the ID of the passenger: " << endl;
	cin >> key;
	if (mine.search(key)) {
		string newfood;
		cout << "Enter the new food: " << endl;
		cin >> newfood;
		// assuming the search function stopped where curr = key
		mine.curr->food = newfood;
		cout << "New food added." << endl;
	}
	else {
		cout << "We do not have that passenger." << endl;
	}
    
}

void reservation::changeSeat() {
	int key;
	
    //read in the passenger id
    cout << "Enter passenger ID to change seat number: ";
    cin >> key;
    cin.ignore();
    //validate the passenger id
        if (mine.search(key)) {
            ;
        }
        else {
            cin.clear();

            cout << "Invalid input. Please enter a valid integer." << endl;
            cout << "Enter passenger ID to change: ";
        }
    string newSeat;
    //read in the new seat
    cout << "Enter new seat number: ";
    //validate the new seat
    while (true) {
        if (getline(cin, newSeat)) {
            break;
        }
        else {
            cin.clear();
           
            cout << "Invalid input. Please enter a valid integer." << endl;
            cout << "Enter new seat number: ";
        }
    }
    //change the passenger seat
    mine.curr->seat = newSeat;
    //sync the database
    copyDatabase();
}

void reservation::copyDatabase()
{
    linked_list copy;
    mine.copy_list(copy);
}