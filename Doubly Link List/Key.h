//FILE : Key.h
//Class Provided: Key

// 				CONSTRUCTOR
//`		Key(int x=0, Value* y=NULL, Value* z=NULL);
//This constructor initialized the Key to 0 and NULL pointer

//				MODIFICATION MEMBER FUNCTIONS
//		void setkhead(Value* ptr){headptr=ptr;}
//Function takes in a Value pointer and set the next/headptr pointer of the key to
//inserted value pointer
//		void setkprev(Value* ptr){prevptr=ptr;}
//Function takes in a Value pointer and set the prevptr pointer of the key to
//inserted value pointer
//		void setkey(int key){keys=key;}
//Function takes in a int value and set Key data to it

//				OTHER MEMBER FUNCTIONS
//		Value* rkhead(){return headptr;}
//Function returns the next pointer of the key
//		Value* rkprev(){return prevptr;}
//Function returns the prev pointer to the key
//		Value* link(){ return headptr;}
//Function return the next pointer of the key
//		int rkey(){return keys;}
//Function returns the Key data




#ifndef KEY_H_
#define KEY_H_
#include <iostream>
#include "Value.h"

class Key {
public:
	// 				CONSTRUCTOR
	Key(int x=0, Value* y=NULL, Value* z=NULL);
	//				MODIFICATION MEMBER FUNCTIONS
	void setkhead(Value* ptr){headptr=ptr;}
	void setkprev(Value* ptr){prevptr=ptr;}
	void setkey(int key){keys=key;}
	//				OTHER MEMBER FUNCTIONS
	int rkey(){return keys;}
	Value* rkhead(){return headptr;}
	Value* rkprev(){return prevptr;}
	Value* link(){ return headptr;}
private:
	int keys;
	Value* headptr;
	Value* prevptr;
};

#endif /* KEY_H_ */
