//FILE : Value.h
//Class Provided: Value

// 				CONSTRUCTOR
//`		Value(int x=0, Value* y=NULL, Value* z=NULL);
//This constructor initialized the Value to 0 and NULL pointer

//				MODIFICATION MEMBER FUNCTIONS
//		void setvhead(Key* ptr){headptr=ptr;}
//Function takes in a Key pointer and set the next/headptr pointer of the Value to
//inserted Key pointer
//		void setvprev(Key* ptr){prevptr=ptr;}
//Function takes in a Key pointer and set the prevptr pointer of the Value to
//inserted Key pointer
//		void setvalue(int val){values=val;}
//Function takes in a int value and set Value data to it

//				OTHER MEMBER FUNCTIONS
//		Key* rvhead(){return headptr;}
//Function returns the next pointer of the Value
//		Key* rvprev(){return prevptr;}
//Function returns the prev pointer to the Value
//		Key* link(){ return headptr;}
//Function return the next pointer of the Value
//		int rval(){return values;}
//FUnction return the Value data


#ifndef VALUE_H_
#define VALUE_H_

#include <iostream>
class Key;


class Value {
public:
	// 				CONSTRUCTOR
	Value(int x=0, Key* y=NULL, Key* z=NULL);
	//				MODIFICATION MEMBER FUNCTIONS
	void setvhead(Key* ptr){headptr=ptr;}
	void setvprev(Key* ptr){prevptr=ptr;}
	void setvalue(int val){values=val;}
	//				OTHER MEMBER FUNCTIONS
	int rval(){return values;}
	Key* rvhead(){return headptr;}
	Key* rvprev(){return prevptr;}
	Key* link(){ return headptr;}
private:
	int values;
	Key* headptr;
	Key* prevptr;

};

#endif /* VALUE_H_ */
