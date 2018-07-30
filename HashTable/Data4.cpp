//Assignement 4
//BY Wli Akbar

#include <iostream>
#include "node.h"
#include "hash_table.h"
using namespace std;
int main() {

	/*		Answers to the short questions in the Assignment
	 * ADVANTAGE OF SWITCHING BETWEEN LINKLIST AND BST?
	 * For a large number of entries a binary search tree would prove
	 * to be more efficent in terms of searching, inserting and deleting as
	 * its average time complexity for searching is O(logn) while for a linked
	 * list it is O(n). It is suggested that we switch back to a linklist
	 * on the entries decrease as the Binary search tree also has a worst case
	 * of O(n).
	 *
	 *
	 * WHY CALL IT REHASH?
	 * The function is called rehash as by increasing the table size, one would
	 * need to maniuplate the hash function again inorder to abide by this
	 * larger table;therefore, in esscene you are hashing again.
	 */

	hash_table<int> x; 		// for convinence all the entries are entered
	x.put(41,2);			// so they are placed in the same index
	x.put(21,3); 			// in the hashtable
	x.put(1,4);
	x.put(61,5);
	x.put(81,7);
	x.put(101,10);  		//In total for now 6 entries are entered
							//therefore currently we should have a linklist
	node<int>* firstindex=x.rlptr(1);//this sets the pointer to the first index

	cout<<endl<<"If this is a linklist the following comparison should return one: "
			<<(typeid(*firstindex)==typeid(link_node<int>))<<endl;
	x.hashtableprint();
	//x.inorder(temp4);
	cout<<endl;

	x.put(121,2);		//Now index one should have a total of 14 entries
	x.put(141,3); 		//Therefore it should be converted into a
	x.put(161,4);		//Binary search tree
	x.put(181,5);
	x.put(201,7);
	x.put(221,47);
	x.put(241,68);
	x.put(261,102);

	cout<<endl<<"\nIf this is a BST the following comparison should return one: "
				<<(typeid(*firstindex)==typeid(treenode<int>))<<endl;
	x.hashtableprint();		//this will print in a inorder traversal

	x.remove(241);		//Now I have removed 7 entries
	x.remove(201);		//therefore my hashtable inde
	x.remove(21);		//should covert back to a linklist
	x.remove(81);
	x.remove(181);
	x.remove(141);
	x.remove(161);
	node<int>* temp=x.rlptr(1);
	cout<<endl<<"\n\nIf this is a linklist the following comparison should return one: "
				<<(typeid(*temp)==typeid(link_node<int>))<<endl;
	x.hashtableprint();

	//the get function returns you the value at the key entered

	cout<<endl<<"\nthe value at key 121: "<<x.get(121);
	cout<<endl<<"\nthe value at key 261: "<<x.get(261);


	return 0;
}
