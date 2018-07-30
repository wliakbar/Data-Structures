//FILE : List.h
//Class Provided: List
// 				CONSTRUCTOR/DESTRUCTOR
//		List()
// Initializes the headptr to NULL
// 		~List()
//	Clears the list and deallocates dyanmic memory
//
//				MODIFICATION MEMBER FUNCTIONS
//		void insert_end(int key, int value);
//This function takes in a key and value and inserts it at the end of
//the link list
//		void insert_head(int key, int value);
//This function takes in a key and value and inserets it at the front of the
//link list
//		void insert_at(const int& index,const int& key,const int& value);
//This function takes in a index, key and value and inserts the key and value
//at the specified index in the link list
//		void remove_head();
//This function removes the first key/value in the link list
//		void remove_at(const int& index);
//This function takes in a index value and removes the key/value at the
//specified index
//		void clear_list();
//This function clears the whole list and deallocates the dynamic memory
//		void sethead(Key*& x){headptr=x;}
//Takes in a Key pointer and sets the headptr to this Key ptr
//
//				OTHER MEMBER FUNCTIONS
//		int size();
//Returns the size of the linked list
//		Key* rhead() const{return headptr;}
//Returns the headptr of the link list
//		int retireve_at_key(const int& x);
//Function takes in a key value (which in essence is a int value) and returns
//The matching Value
//		Key* retreive_at_index(const int& x);
//The function takes in a index value and returns the Key pointer at that index
//		Key* mergesort(Key*& x);
//This function takes in a Key pointer which should be the headptr of the link
//list and then uses mergesort recursively to sort the link list
//		Key* merge(Key*& a, Key*& b);
//This merge function takes in the headptr to two link lists and
//merges two sorted link lists together
//		Key* midkey(Key* head);
//The function takes in the headptr of a link list and returns Key pointer to
//that middle element



#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include "Key.h"
#include "Value.h"

class List {
public:
	// 				CONSTRUCTOR/DESTRUCTOR
	List();
	~List();
//					MODIFICATION MEMBER FUNCTIONS
	void insert_end(int key, int value);
	void insert_head(int key, int value);
	void insert_at(const int& index,const int& key,const int& value);
	void remove_head();
	void remove_at(const int& index);
	void clear_list();
	void sethead(Key*& x){headptr=x;}
	int size();
	//				OTHER MEMBER FUNCTIONS
	Key* rhead() const{return headptr;}
	int retireve_at_key(const int& x);
	Key* retreive_at_index(const int& x);
	Key* mergesort(Key*& x);
	Key* merge(Key*& a, Key*& b);
	Key* midkey(Key* head);


private:
	Key* headptr;

};

#endif /* LIST_H_ */
