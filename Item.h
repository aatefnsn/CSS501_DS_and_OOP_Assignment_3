#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

class Item { // class just to hold the string 
private:

	string word;

public:
	Item(); // empty constructor 
	Item(string word); // constructor with the string word 
	~Item(); // destructor
	string getWord(); // getter to retuen the word
	void setWord(string str); // setter 
	void printWord(); // printer 
};