//Project 3
//BY: Wli Akbar

#include <iostream>
#include "List.h"
using namespace std;

int main() {
	/*		QUESTION 3 OF THE ASSIGNMENT
	 * The function implemented to sort the link list is known
	 * as a mergesort. I implemented the function recursively; therefore,
	 * it satisfies the condition of it using O(1) space. The running time of
	 * this function is O(nlogn).
	 */

	List D;

	D.insert_head(1,4);		//Keep pushing values
	D.insert_head(2,2);		//Push
	D.insert_head(4,3);		//Push
	D.insert_head(3,1);		//Push
	D.insert_end(6,2);		//Insert at end of list
	D.insert_at(5,5,9);		//insert at the fifth index

	Key* use=NULL;
	cout<<"			THE INITIAL LINK LIST\n";
	for(int i=1;i<D.size()+1;i++){
			use=D.retreive_at_index(i);
			cout<<"The Key is: "<<use->rkey()<<" The value is: "<<use->link()->rval()<<endl;
			}

	cout<<"============================================="<<endl;

	D.remove_at(5);		//Remove fifth index
	D.remove_head();	//Reomve the head ke value pair

	cout<<"			LINK LIST AFTER REMOVING FIRST AND FIFTH INDEX\n";
	use=NULL;
	for(int i=1;i<D.size()+1;i++){
				use=D.retreive_at_index(i);
				cout<<"The Key is: "<<use->rkey()<<" The value is: "<<use->link()->rval()<<endl;
				}
	cout<<"============================================="<<endl;

	Key* head=D.rhead();
	D.mergesort(head);		//Sort the list using merge sort

	cout<<"			LINK LIST AFTER SORTING\n";

	use=NULL;
	for(int i=1;i<D.size()+1;i++){
		use=D.retreive_at_index(i);
		cout<<"The Key is: "<<use->rkey()<<" The value is: "<<use->link()->rval()<<endl;
		}

	return 0;
}
