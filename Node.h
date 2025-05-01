#pragma once
#include "Item.h"
#include <string>
using namespace std;

class Node { // Node class that has a pointer that points to the Item object holding the string word 

private:
	Item * itemStrP; // Item pointer 

public:
	Node* next; // pointer to the next 
	Node(Item * itemStrP, Node * n); // node constructor with pointer to item holding string and another node next
	Node(Item * itemStrP); // node constructor with pointer to item holding string
	Node(); // empty constructor
	Node(Node &n); // copy constructor for node taking a reference to another node 
	Node(Node * n); // // copy constructor for node taking a pointer to another node
	~Node(); // destructor
	Item * getitemStrP(); // getter to return the ItemPointer 
	void setNext(Node &n); // setting next to a reference node input 
	Node * getNext(); // getter 
	void printNode(); // node printer 
};