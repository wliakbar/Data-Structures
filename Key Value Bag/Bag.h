//FILE : Bag.h
//Class Provided: Bag
//
//	MEMBER CONSTANTS
//static const size_type CAPACITY = _____
//Bag::CAPACITY is the maximum number of items that a sequence can hold.
//
//	CONSTRUCTOR
//Initializes used to 0 and provides dynamic memory for the array of student
//objects
//
//	DECONSTRUCTOR
//Deallocates the memory used for the array of student objects
//
//	MODIFICATION MEMBER FUNCTIONS
//void insert(int x, const Student y);
//Adds/replaces an element in the array of student objects and shifts
// the array of keys and students accordingly to keep in sorted order
//void deletex(int x);
//Deletes an element at the index x and reduces the arrays accordingly
//
//	OTHER MEMBER FUNCTIONS
//size_t binarysearch(int a[],int b, int c);
//Runs a binary search on the array of keys to find the index of the key
//being searched for
//	Student getit(int x);
// Retrieves the Student object that is in the index x of the array

#ifndef BAG_H_
#define BAG_H_

#include<iostream>
#include "Student.h"

class Bag{
public:
	//CONSTRUCTOR
	Bag();
	//DESTRUCTOR
	~Bag();
	//MODIFICATION FUNCTIONS
	void insert(int x, const Student y);
	void deletex(int x);
	Student retrieve(int x);
	size_t binarysearch(int a[],int b, int c);
	//MEMBER CONSTANTS
	static const int CAPACITY=20;
private:
	Student *data;
	int used;
	int key[CAPACITY];
};
#endif /* BAG_H_ */
