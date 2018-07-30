#include <iostream>
#include "List.h"
#include "Key.h"
#include "Value.h"

List::List() {
	headptr=NULL;
}
List::~List(){
	clear_list();
}

void List::insert_end(int key, int value){
	int s=size();		//Gets size of index
	Value* x=NULL;
	Value* temp=NULL;
	Key* y=new Key(key,x,temp);
	x=new Value(value,NULL,y);
	y->setkhead(x);			//Create new Key and Value pair and links them

	Key* last=retreive_at_index(s);		//Gets the last key in list
	last->link()->setvhead(y);
	y->setkprev(last->link());		//Links new and last key

}

void List::insert_head(int key, int value){
	Value* x=NULL;
	Key* y=new Key(key,x,NULL);
	x=new Value(value,headptr,y);
	y->setkhead(x);
	headptr=y;		//Create and link new key and set headptr to new key
}

void List::insert_at(const int& index,const int& key,const int& value){
	if(index==1){
		insert_head(key,value);
		return;
	}
	else if(index==(size()+1)){
		insert_end(key,value);
		return;					//Checks if your inserting at the head or tail
	}
	else{
	Key* current= headptr;
	Key* tempt=NULL;
	Value* temp=NULL;
	Value* x=NULL;
	Key* y=new Key(key,x,temp);
	x=new Value(value,tempt,y);
	y->setkhead(x);				//Create a link Key and Value pair
	for(int i=0; i<(index-2); i++){
		current=(current->link())->link();	//Go to key before desired index
	}
	x->setvhead(current->link()->link());
	current->link()->link()->setkprev(x);
	y->setkprev(current->link());	//Link next and prev pointer according to
	current->link()->setvhead(y);	//new key
	return;
}
}

void List::remove_head(){
	Key* temp=headptr;
	Value* nextv=headptr->link();
	Key* x=nextv->rvhead();
	headptr=x;		//Delete the first key and value pair and adjust
	delete temp;	//pointer and headptr accordingly
	delete nextv;
}

void List::remove_at(const int& index){
	if(index==1){
		remove_head();
		return;
	}
	Key* current= headptr;
	Key* ktemp;
	Value* vtemp;
	for(int i=0; i<(index-2); i++){
		current=(current->link())->link();
	}
	ktemp=current->link()->link();
	vtemp=ktemp->link();
	current->link()->setvhead(vtemp->link());
	vtemp->link()->setkprev(current->link());
	delete ktemp;	//Similar to insert but finds the index and key before
	delete vtemp;	//deletes the key at index and adjusts pointers accordingly

}

void List::clear_list(){
	while(headptr!=NULL){		//Removes first Key value pair until empty
		remove_head();
	}
}

int List::retireve_at_key(const int& x){
	Key* cursor=headptr;
	while(cursor->link()->link()!=NULL){
		if(cursor->rkey()==x){return cursor->link()->rval();}
		cursor=cursor->link()->link();
	}
	if(cursor->rkey()==x){return cursor->link()->rval();}
	return -1;
}

int List::size(){
	int length=0;
		Value* cursor=headptr->link();
		while(cursor->link()!=NULL){
			length++;
			cursor=cursor->link()->link();
		}
		length++;
		return length;

}

Key* List::retreive_at_index(const int& x){
	Key* cursor=headptr;
	for(int i=1;i<x;i++){
		cursor=cursor->link()->link();
	}
	return cursor;
}

Key* List::merge(Key*& a, Key*& b){
	Key* result;
	if(a==NULL){
		return b;
	}
	if(b==NULL){
			return a;
	}

	if(a->rkey()<=b->rkey()){//	if the key of a is less than or equal to b
		Key* next=a->link()->link();//make a the first element and b the second
		a->link()->setvhead(merge(next,b));
		a->link()->link()->setkprev(a->link());
		a->setkprev(NULL);
		result=a;

	}
	else{

		Key* next=b->link()->link();	//otherwise make b first and then a
		b->link()->setvhead(merge(next,a));
		b->link()->link()->setkprev(b->link());
		b->setkprev(NULL);
		result=b;

	}

	return result;
}

Key* List::mergesort(Key*& x){

	Key* head=NULL;
	if(x==NULL || x->link()->link()==NULL){	//if empty or only one key/value
		return x;							//return
	}
	Key* middle=midkey(x);	//otherwise break list into two
	Key* next=middle->link()->link();
	middle->link()->setvhead(NULL);
	next->setkprev(NULL);
	Key* left= mergesort(x);	//and recursively keep doing so to the
	Key* right=mergesort(next);	//divisions until single key/values are left
	head=merge(left,right);	//Lastly merge these single lists one by one
	headptr=head;
	return head;
}

Key* List::midkey(Key* head){
	int count=0;
	Key* mid=head;
	while(head->link()->link()!=NULL){
		if(count & 1){
			mid=mid->link()->link();
		}
		++count;
		head=head->link()->link();
	}
	return mid;
}

