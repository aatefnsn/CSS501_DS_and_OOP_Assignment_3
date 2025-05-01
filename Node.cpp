#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

Node::Node(Item * itemStrP, Node * n) { // node constructor 
	this->next = n;
	this->itemStrP = itemStrP;
}

Node::Node(Item * itemStrP) { // node constructor 
	this->next = NULL;
	this->itemStrP = itemStrP;
}

Node::Node() { // empty node constructor 
	this->next = NULL;
	this->itemStrP = NULL;
}

Node::~Node() { // destructor 
}

Item * Node::getitemStrP() {  // getter 
	return this->itemStrP;
}

void Node::setNext(Node &n) { // setter for next
	if (&n != NULL)
		this->next = &n;
	else
		this->next = NULL;
}

Node * Node::getNext() { // getter 
	return this->next;
}

void Node::printNode() {// print method 
	this->itemStrP->printWord();
}

Node::Node(Node &n) { // copy constructor 

	this->itemStrP = n.itemStrP; // setting item string pointer
	this->next = n.next;  // setting next
}

Node::Node(Node * n) { // copy constructor 

	this->itemStrP = n->itemStrP; // setting item string pointer 
	this->next = n->next; // setting next
}