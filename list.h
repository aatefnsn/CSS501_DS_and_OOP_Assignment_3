#pragma once
#include "Node.h"
#include <string>
//#include "Item.cpp"

class List {

private:
	Node * head; 

public: 
	List();
	List(Node * n);
	List(const List &l);
	void insert(string str);
	Node pop();
	void PrintList(); // print list
	int getListSize();
	void printReverseRecursive(); 
	void printReverseIterative();
	string getNodeString(Node &n);
};
