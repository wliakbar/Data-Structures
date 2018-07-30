//File: node.h
//Classes provided: node, link_node, treenode

//			Constructor
//link_node(){ptr=NULL; link_count=0;}
//Initializes pointer with no inputs
//link_node(int x, Item y){data=y; key=x; ptr=NULL; link_count++;}
//Itilizizes list with entry x and y
//treenode(){left_child=NULL; right_child=NULL; tree_count=0;}
//Initializes pointer with no inputs
//treenode(int x, Item y){key=x; data=y; left_child=NULL; right_child=NULL; tree_count=0;}
//Initializes tree with entry x and y
//				Destructors
//The destructors here do nothing they are just here to carry out inheritance
//The memory is deallocated in the hashtable

//			Link node functions
/*void setval(Item x){data=x;}
 * This function basically sets the data to item x
void setptr(link_node* x){ptr=x;}
Sets the next pointer to the specified linknode
int rkey(){return key;}
Returns the key of the linknode
Item get_lnode(int x);
Returns the value ate the specified linknode
Item rval(){return data;}
Returns the value of a linknode
void increase_count(){link_count++;}
Increases the linklist count by one
void lclear(link_node<Item>** head);
Clears the link list
int rlcount(){return link_count;}
Return the link_count
void decrease_count(){link_count--;}
Decreases the link count by on
void setkey(int x){key=x;}
Sets the linknode key to specified key int
void set_count(int x){link_count=x;}
Sets the count to specified value
 */

//			Treenode function
/*
 void set_right(treenode* x){right_child=x;}
 Sets the right pointer to specified treenode
 void set_left(treenode* x){left_child=x;}
Sets the left pointer to specified treenode
int rkey(){return key;}
Returns the key of the node
void setval(Item x){data=x;}
Sets the value to sepciefied Item x
void setkey(int x){key=x;}
Sets the key to the enetered key x
Item rval(){return data;}
Returns the value of the node
int rtcount(){return tree_count;}
Returns the tree count
void cleartree();
Clears the tree
void increase_tcount(){tree_count++;}
Increases the tree count by one
void decrease_tcount(){tree_count--;}
decreseases the tree count by one
void set_tcount(int x){tree_count=x;
Set the tree count to the specified value
 */

#ifndef NODE_H_
#define NODE_H_

template<typename Item>
class node{
public:
	virtual ~node(){}
};

template<typename Item>
class link_node : public node<Item>{
public:
	~link_node(){}
	link_node(){ptr=NULL; link_count=0;}
	link_node(int x, Item y){data=y; key=x; ptr=NULL; link_count++;}
	link_node* link(){return ptr;}
	void setval(Item x){data=x;}
	void setptr(link_node* x){ptr=x;}
	int rkey(){return key;}
	Item get_lnode(int x);
	Item rval(){return data;}
	void increase_count(){link_count++;}
	void lclear(link_node<Item>** head);
	int rlcount(){return link_count;}
	void decrease_count(){link_count--;}
	void setkey(int x){key=x;}
	void set_count(int x){link_count=x;}


private:
	int link_count;
	Item data;
	int key;
	link_node* ptr;
};


template<typename Item>
class treenode : public node<Item>{
public:
	~treenode(){}
	treenode(){left_child=NULL; right_child=NULL; tree_count=0;}
	treenode(int x, Item y){key=x; data=y; left_child=NULL; right_child=NULL; tree_count=0;}
	treenode* rleft(){return left_child;}
	treenode* rright(){return right_child;}
	void set_right(treenode* x){right_child=x;}
	void set_left(treenode* x){left_child=x;}
	int rkey(){return key;}
	void setval(Item x){data=x;}
	void setkey(int x){key=x;}
	Item rval(){return data;}
	int rtcount(){return tree_count;}
	void cleartree();
	void increase_tcount(){tree_count++;}
	void decrease_tcount(){tree_count--;}
	void set_tcount(int x){tree_count=x;}
private:
	int tree_count;
	Item data;
	int key;
	treenode* left_child;
	treenode* right_child;
};

#include "node.tpp"


#endif /* NODE_H_ */
