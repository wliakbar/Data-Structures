// by WLI AKBAR


#include <iostream>
#include "Bag.h"

using namespace std;

int main() {
	Bag p; 			//A bag p is created

	Student s1(18, "Robert");   	//Six student of objects
	Student s2(20, "Alex");			//With their respective ages and
	Student s3(22, "Rod");			//Names are created
	Student s4(19, "Ben");
	Student s5(10, "Joe");
	Student s6(20,"Wli");

	p.insert(20,s1);			//Five of the student objects are
	p.insert(23,s2);			//inserted in the bag
	p.insert(40,s3);
	p.insert(21,s4);
	p.insert(36,s5);

	cout<<p.retrieve(20);		// the five objects are retrieved
	cout<<p.retrieve(21);
	cout<<p.retrieve(23);
	cout<<p.retrieve(36);
	cout<<p.retrieve(40);

	p.insert(21,s6);	//The sixth object is inserted at an already existing
					//index so the previous value should be replaced with this
	cout<<"=================================================";

	cout<<p.retrieve(20);	//The five objects are printed again to show
	cout<<p.retrieve(21);	//the change was made
	cout<<p.retrieve(23);
	cout<<p.retrieve(36);
	cout<<p.retrieve(40);
	cout<<"=================================================";

	p.deletex(40);		//THe object at index 40 is deleted

	cout<<p.retrieve(20);	//The program should note the index is empty
	cout<<p.retrieve(21);	//And return a empty student for index 40  now
	cout<<p.retrieve(23);
	cout<<p.retrieve(36);
	cout<<p.retrieve(40);

	return 0;
}
