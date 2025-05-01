#include "pch.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

Item::Item() { // empty constructor 
	word = "";
}

Item::Item(string word) { // constructor
	this->word = word; 
}

Item::~Item() { // destructor
	
}

string Item::getWord() { // getter for word 
	return word; 
}


void Item::setWord(string str) { // word setter
	this->word = str;
}


void Item::printWord() { // Item printer to print word 
	cout << word << endl;
}