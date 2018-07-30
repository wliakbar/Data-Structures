#include<iostream>
#include "Bag.h"
#include "Student.h"

Bag::Bag(){
	used=0;
	data= new Student[CAPACITY];
}
void Bag::insert(int x,const Student y){
	int index=binarysearch(key, used, x);
	if(index==-1){			//If index is empty or does not exist
		if(x>key[used-1]){	//And if the desired key is greater than the
			index=used;		//Last key in in the array of keys
			key[index]=x;	//Simply add the object at the end
			*(data+index)=y;
		}
		else{			//If the desired key is not greater than the last
			int i=0;	//Find where the key would fit in sorted order
			while(x>key[i]){ i++;index=i;} //in the array of keys
			int temp2;
			int temp=key[index];	//Next simply add the key and object
			key[index]=x;			//there and make according shifts
			Student f;				// to maintain sorted order
			Student m=*(data+index);
			*(data+index)=y;
			for(int i=1;i<=used-index; i++){
				temp2=key[index+i];
				key[index+i]=temp;
				temp=temp2;
				f=*(data+index+i);
				*(data+index+i)=m;
				m=f;
			}
		}
	}
	else{			//Else if the index already has an existing key
		key[index]=x;	//Replace the old value/object with the new one
		*(data+index)=y;
		used--;		//Ensures used counter remains the same
		}
	used++;		//Increase used size counter
	return;
}
Bag::~Bag(){
	delete [] data;
}
Student Bag::retrieve(int y){
	int ind= binarysearch(key,used,y);
	if(ind==-1){
		std::cout<<"\nThe bag at this index "<<y<< " is empty";
		Student x;
		return x;
	}
	return *(data+ind);
}
void Bag::deletex(int x){
	int index= binarysearch(key,used,x);
	for(int i=0; i<used-index;i++){
		*(data+index+i)=*(data+index+i+1);
		key[index+i]=key[index+i+1];
	}
	used--;
}
size_t Bag::binarysearch(int a[], int cap, int val){
	int low=0;			//Runs a binary search to find index
	int high= cap-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==val){return mid;}
		else if(val<a[mid]){high=mid-1;}
		else {low=mid+1;}
	}
	return -1;
}

