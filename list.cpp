#include "list.h"
#include "item.h"
#include "Node.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std; 

List::List() { // list empty constructor 
	head = NULL;
}
List::List(Node * n) {
	this->head = n;
}
void List::insert(string str) { //  insert method 
	Item  * itemp = new Item(str); // creating a new itempointer with a string equal to the string requested in the input 
	Node * n = new Node(itemp); // creating a new node with the new item pointer created that has the string 
	if (head == NULL) { // if list being inserted is empty .. set the new node to be head 
			this->head = n;
			n->next = NULL; // set the next to NULL 
	}
	else {
		Node * last; // creating a pointer runner called last to go over the list until it reaches last node 
		last = head; // setting the runner to start at head 
		while (last->next != NULL) { // go to the last node to append/insert the newly created node
			last = last->next;
		}
		n->next = NULL; // inserting the node at the end setting next ot NULL
		last->next = n; // setting the last node next to the the new inserted node 
	}
}

Node List::pop() { // method to pop last node in the list 
	Node * last; // runner 
	last = head;
	while (last->next->next != NULL) { // while loop to go to the node before last node 
		last = last->next;
	}
	Node * temp = last->next; // data to return
	last->next->printNode(); // printing 
	last->next = NULL;	// popping by setting the last next to NULL
	return *temp; 
}

void List::PrintList() { // printing 
	Node * current;
	current = this->head; // runner 
	while (current != NULL) {
		current->printNode();
		current = current->next;
	}
}

void List::printReverseRecursive() { // Big o for this method is O(n) since it goes over the list twice and moves the pointer so it is probably O(4n) and as n goes to infinity it is O(n)
	Node * marker = head; // marking the head node so that the node does not get messed up
	if (head->next != NULL) {
		Node * current = head; // setting current to head 
		head = head->next; //  moving head to the next because we need to print the next node first 
		printReverseRecursive();	// recursion 
		current->printNode(); // after printing the next node .. print the current node
	}
	else {		
		head->printNode(); // base case
	}	
	head = marker; // revert back head to where it was  
}

int List::getListSize() { // method incrementing a counter to get the list size
	Node * marker = head;
	int counter;
	if (marker != NULL) {		
		counter = 1;
		while (marker->next != NULL) {
			counter++;
			marker = marker->next;
		}		
	}
	else {
		return 0; 
	}
	return counter;
}

void List::printReverseIterative() { // O(n^2) since it has a nested loop to go over the list twice 
	Node * marker = head; 
	int size = this->getListSize(); 
	for (int i = 1; i <= size; i++) { // nested for loop to go as many times as the list size
		marker = head; 
		for (int j = 1; j <= size - i; j++) { // runner to go over the list and each iteration of the smaller loop to stop at Size -i which is the number of iteration .. this way each time it will print the list in reverse order
			marker = marker->next;			
		}
		marker->printNode(); // print the last node of the iteration 
	}
}

List::List(const List &l) { // copy constructor O(n) as it goes over the original list once by one to get the string and then insert it in the new list
	if (&l == NULL) { // in case list ot be copied is emmpty 
		this->head = NULL;
	}
	else {
		Node * runner = l.head; // runner to go over the input list
		while (runner != NULL) {
			this->insert(runner->getitemStrP()->getWord()); // used the insert method to insert the strings of the old listi nto the new list
			runner = runner->next; 
		}
	}
}