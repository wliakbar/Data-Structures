// File: hash_table.h
//class provided hash_table.h

//					CONSTRUCTORS/DESTRUCTORS
//hash_table(int x=CAP)
//creates a hashtable with the specified size that is inserted or the
//default size of 20 is used
//~hash_table();
//Destructors deallocated the memory and deletes the hashtable

//				MODIFICATION MEMBER FUNCTIONS
//void put(int key,Item x);
//Inserts the key and value pair into the hashtable and also converts to
//a binary search tree if the inputs at a index exceed 12
//void remove(int key)
//Removes the node at the specified key and also converts back to a linked list
//if the inputs in a index become 7 or less

//					OTHER FUNCTION
//Item get(int key);
//Returns the item value at the specified index
//node<Item>* rdata(int i){return data[i];}
//Returns the node head pointer at the specified index
//void linktotree(node<Item>*& x);
//Converts a linkedlist to a binary search tree
//void treetolink(node<Item>* x);
//Converts a binary search tree to a linked list
//void makeit(node<Item>*& x, link_node<Item>*& y);
//Set the headpointer x to the linked list y; in esscence it helps carry out
//the conversion between tree to link
//void addtolink(link_node<Item>*& x, int y, Item z);
//Add the key value pair y and z to a link list node
//void addlink(link_node<Item>*& x, int y, Item z);
//Does the same as its previous verision however does not allocate new memory
//void add_tree(treenode<Item>*& x, int y, Item z);
//Adds the key value pair to a tree node
//void clearlink(node<Item>* x);
//Clears a linked list: NOTE the headpointer has to be a link list pointer
//node<Item>* rlptr(int key){return data[key];}
//Returns the headpointer ate the index specified
//treenode<Item>* get_tree(node<Item>* x, int key);
//Get the address of the tree node at the specified key
//void inorder(node<Item> *x);
//Prints a tree in a inorder traversal
//treenode<Item>* delete_tree(treenode<Item>* root, int key);
//Deletes a entry in a tree with the specified key
//treenode<Item>* findmin(treenode<Item>* root);
//Finds the entry with no children in the lowest left level of a tree
//void rehash();
//Rehash the hastable if the loadfactor exceed 0.95
//link_node<Item> ruseit(){return templink;}
//Returns the helper link_node variable templink
//void clearthetree(node<Item>* x);
//Clears a tree of all entries: NOTE the head pointer has to be a tree node
//void remove_link(node<Item>* x, int key);
//Remove entry from a link list with the specified key
//void increasetemplink()
//Increase the count of the helper variable templink
//void copylink(link_node<Item>*& x,link_node<Item>* y);
//Copies the link list y into x
//void helprehash(hash_table<Item>& x, treenode<Item>* y);
//A helper function to rehahs which adds the values in the tree y to
//the new hashtable x
//void cleartable();
//Clears the hash_table
//void hashtableprint();
//Prints the hashtable either in linklist order or in inorder traversal
//void clearthelink(link_node<Item>* x);
//Helper to clear templink
//int hash(int key){return (key%size);}
//helper function that hashs the key entered



#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <iostream>
#include "node.h"
#include<typeinfo>
template<class Item>
class hash_table{
public:
	static const int CAP=20;

	//		Constructor/Destructor
	hash_table(int x=CAP);
	~hash_table();

	// Modification Member Function
	void remove(int key);
	void put(int key,Item x);
	void addtolink(link_node<Item>*& x, int y, Item z);
	void addlink(link_node<Item>*& x, int y, Item z);
	void add_tree(treenode<Item>*& x, int y, Item z);
	void clearlink(node<Item>* x);
	Item get(int key);


	//		Other Functions
	node<Item>* rdata(int i){return data[i];}
	void linktotree(node<Item>*& x);
	void treetolink(node<Item>* x);
	void makeit(node<Item>*& x, link_node<Item>*& y);
	node<Item>* rlptr(int key){return data[key];}
	treenode<Item>* get_tree(node<Item>* x, int key);
	void inorder(node<Item> *x);
	treenode<Item>* delete_tree(treenode<Item>* root, int key);
	treenode<Item>* findmin(treenode<Item>* root);
	void rehash();
	link_node<Item> ruseit(){return templink;}
	void clearthetree(node<Item>* x);
	void remove_link(node<Item>* x, int key);
	void increasetemplink(){
		templink.increase_count();
	}
	void copylink(link_node<Item>*& x,link_node<Item>* y);
	void helprehash(hash_table<Item>& x, treenode<Item>* y);
	void cleartable();
	void hashtableprint();
	void clearthelink();

private:
	node<Item>** data;
	int hash(int key){return (key%size);}
	int size;
	int hash_count;
	link_node<Item> templink;

};

#include "hash_table.tpp"



#endif /* HASH_TABLE_H_ */
