template<class Item>
hash_table<Item>::hash_table(int x){	//Constructor initialize to NULL
	size=x;
	hash_count=0;
	data=new node<Item>*[size];
	for(int i=0;i<size;i++){
		data[i]=NULL;
	}
}

template<class Item>
hash_table<Item>::~hash_table(){		//Destructor delete everything
	for(int i=0;i<size;i++){
		node<Item>* entry=data[i];
		if(data[i]==NULL){continue;}
		else if((typeid(*data[i])==typeid(link_node<Item>))){
			while(entry!=NULL){
				node<Item>* temp=entry;
				entry=(dynamic_cast<link_node<Item>*>(entry))->link();
				delete temp;
			}
		}
		else{
			(dynamic_cast<treenode<Item>*>(entry))->cleartree();

		}
	}
}

template<class Item>
void hash_table<Item>::cleartable(){	//Same as destructor
	for(int i=0;i<size;i++){
			node<Item>* entry=this->data[i];
			if(entry==NULL){continue;}
			else if((typeid(*entry)==typeid(link_node<Item>))){
				while(entry!=NULL){
					node<Item>* temp=entry;
					entry=(dynamic_cast<link_node<Item>*>(entry))->link();
					delete temp;
				}
			}
			else{
				(dynamic_cast<treenode<Item>*>(entry))->cleartree();

			}
		}
	}

template<class Item>
void hash_table<Item>::hashtableprint(){	//Prints the hashtable
	for(int i=0;i<size;i++){
		node<Item>* entry=data[i];
		if(data[i]==NULL){continue;}
		else if((typeid(*data[i])==typeid(link_node<Item>))){		//If its a linklist
			std::cout<<"\nLINK-LIST:\n";
			while(entry!=NULL){
				std::cout<<"  Key: "<<(dynamic_cast<link_node<Item>*>(entry))->rkey()
						<<"  Value: "<<(dynamic_cast<link_node<Item>*>(entry))->rval()<<",";
				entry=(dynamic_cast<link_node<Item>*>(entry))->link();
			}

		}
		else{		//if its a BST
			std::cout<<"\nBINARY SEARCH TREE:\n";
			inorder(entry);
		}
	}
}



template<class Item>
void hash_table<Item>::clearthetree(node<Item>* x){
	treenode<Item>* cursor=dynamic_cast<treenode<Item>*>(x);
	if(!cursor->rleft() && !cursor->rright()){delete cursor; return;}
	if(cursor->rleft()){
		treenode<Item>* temp1=cursor->rleft();
		clearthetree(temp1);
	}
	else if(cursor->rright()){
		treenode<Item>* temp2=cursor->rright();
		clearthetree(temp2);
	}
}

template<class Item>
void hash_table<Item>::clearlink(node<Item>* x){
	node<Item>* entry=x;
	while(entry!=NULL){
		node<Item>* temp=entry;
		entry=(dynamic_cast<link_node<Item>*>(entry))->link();
		delete temp;
	}

}


template<class Item>
Item hash_table<Item>::get(int key){
	int index=hash(key);
	if((typeid(*data[index])==typeid(link_node<Item>))){	//For linklist
		return (dynamic_cast<link_node<Item>*>(data[index]))->get_lnode(key);
	}
	else{	//For BST
		treenode<Item>* temp= get_tree(data[index],key);
		return temp->rval();
	}
	return Item();
}

template<class Item>
treenode<Item>* hash_table<Item>::get_tree(node<Item>* x, int key){
	if(x==NULL || (dynamic_cast<treenode<Item>*>(x))->rkey()==key){
		treenode<Item>* temp=(dynamic_cast<treenode<Item>*>(x));
		return temp;
	}
	if((dynamic_cast<treenode<Item>*>(x))->rkey() < key){
		return get_tree((dynamic_cast<treenode<Item>*>(x))->rright(),key);
	}
	return get_tree((dynamic_cast<treenode<Item>*>(x))->rleft(),key);
}

template<class Item>
void hash_table<Item>::inorder(node<Item>* x){
	if(x==NULL){		//Prints the tree inorder
		return;
	}
	inorder((dynamic_cast<treenode<Item>*>(x))->rleft());
	std::cout<<"  Key: "<<(dynamic_cast<treenode<Item>*>(x))->rkey()<<
			"  Value: "<<(dynamic_cast<treenode<Item>*>(x))->rval()<<",";
	inorder((dynamic_cast<treenode<Item>*>(x))->rright());
}


template<class Item>
void hash_table<Item>::put(int key,Item x){
	int index=hash(key);
	if(data[index]==NULL){
		data[index]=new link_node<Item>(key,x);
		hash_count++;
		return;
	}
	else{
		if((typeid(*data[index])==typeid(link_node<Item>)) &&		//If it a linklist and less than 12
				(dynamic_cast<link_node<Item>*>(data[index])->rlcount())<12){

			node<Item>* cursor=data[index];
			while((dynamic_cast<link_node<Item>*>(cursor)->link())!=NULL){
					cursor=dynamic_cast<link_node<Item>*>(cursor)->link();
				}
				link_node<Item>* temp= new link_node<Item>(key,x);
				dynamic_cast<link_node<Item>*>(cursor)->setptr(temp);
				(dynamic_cast<link_node<Item>*>(data[index]))->increase_count();

		}
		else if((typeid(*data[index])==typeid(link_node<Item>)) &&	//else if its a link list with 12 entries
				(dynamic_cast<link_node<Item>*>(data[index])->rlcount())==12){
			node<Item>* temp=data[index];
			linktotree(data[index]);
			clearlink(temp);	//Delete the link list
			treenode<Item>* temp2=(dynamic_cast<treenode<Item>*>(data[index]));
			add_tree(temp2,key,x);
			(dynamic_cast<treenode<Item>*>(data[index]))->set_tcount(12);
			(dynamic_cast<treenode<Item>*>(data[index]))->increase_tcount();
		}
		else{		//Else its a tree
			treenode<Item>* temp2=(dynamic_cast<treenode<Item>*>(data[index]));
			add_tree(temp2,key,x);
			(dynamic_cast<treenode<Item>*>(data[index]))->increase_tcount();
		}

	}
	hash_count++;

	double loadfactor=hash_count/size;
	if(loadfactor>0.95){ rehash();}
}

template<class Item>
void hash_table<Item>::remove_link(node<Item>* x, int key){
	if(dynamic_cast<link_node<Item>*>(x)->rkey()==key){
		node<Item>* temp=dynamic_cast<link_node<Item>*>(x)->link();
		delete x;
		x=temp;
	}
	else{			//Removing an element from a link list
		link_node<Item>* temp;
		link_node<Item>* cursor=dynamic_cast<link_node<Item>*>(x);
		while(cursor->link()!=NULL || cursor->rkey()==key){
			temp=cursor;
			cursor=cursor->link();
			if(cursor->rkey()==key){break;}
		}
		if(cursor->rkey()==key){
			link_node<Item>* temp2=cursor->link();
			temp->setptr(temp2);
			delete cursor;
		}
	}
}

template<class Item>
void hash_table<Item>::clearthelink(){	//Resets private helper variable templink
	link_node<Item>* temp=new link_node<Item>;
	templink=*temp;
	templink.set_count(0);
}


template<class Item>
void hash_table<Item>::remove(int key){
	int index=hash(key);
	if(data[index]==NULL){return;}

	else if((typeid(*data[index])==typeid(link_node<Item>))){	//its a linklist

		remove_link(data[index],key);
		dynamic_cast<link_node<Item>*>(data[index])->decrease_count();
	}
	else if((typeid(*data[index])==typeid(treenode<Item>)) &&	//Its a tree but size is 8
		(dynamic_cast<treenode<Item>*>(data[index])->rtcount()==8)){
		node<Item>* temp=data[index];
		treetolink(data[index]);
		link_node<Item>* useit=&templink;
		makeit(data[index],useit);
		clearthelink();
		dynamic_cast<treenode<Item>*>(temp)->cleartree();
		remove_link(data[index],key);
		(dynamic_cast<link_node<Item>*>(data[index]))->decrease_count();
	}
	else{	//Its a tree
		treenode<Item>* temp=dynamic_cast<treenode<Item>*>(data[index]);
		data[index]=delete_tree(temp, key);
		dynamic_cast<treenode<Item>*>(data[index])->decrease_tcount();
	}
	hash_count--;
}

template<class Item>
void hash_table<Item>::add_tree(treenode<Item>*& x, int y, Item z){
	if(y < x->rkey()){
		if(x->rleft()){
			treenode<Item>* temp=x->rleft();
		     add_tree(temp,y, z);
		}
		 else{
		       x->set_left(new treenode<Item>(y, z));
		 }
		}
		else{
			if(x->rright()){
				treenode<Item>* temp2=x->rright();
				add_tree(temp2,y, z);
			}
		    else{
		    	x->set_right(new treenode<Item>(y, z));
		    }
		}
}

template<class Item>
treenode<Item>* hash_table<Item>::delete_tree(treenode<Item>* root, int key){
	if (root == NULL) {
	     return root;
	  }
	  if (key < root->rkey()) {  // data is in the left sub tree.
	      root->set_left(delete_tree(root->rleft(), key));
	  } else if (key > root->rkey()) { // data is in the right sub tree.
	      root->set_right(delete_tree(root->rright(), key));
	  }
	  else {
	     // no children
	     if (root->rleft() == NULL && root->rright() == NULL) {
	        delete root; // wipe out the memory, in C, use free function
	        root=NULL;
	     }
	     // one child (right)
	     else if (root->rleft() == NULL) {
	        treenode<Item>* temp = root; // save current node as a backup
	        root = root->rright();
	        delete temp;
	    //    return root;
	     }
	     // one child (left)
	     else if (root->rright() == NULL) {
	        treenode<Item>* temp = root;
	        root = root->rleft();
	        delete temp;
	     }
	     else {	//Two children
	        treenode<Item>* temp = findmin(root->rright());
	        root->setkey(temp->rkey());; // duplicate the node
	        root->setval(temp->rval());
	        root->set_right(delete_tree(root->rright(), temp->rkey()));
	     }
	  }

	  return root;

}

template<class Item>
treenode<Item>* hash_table<Item>::findmin(treenode<Item>* root){
	 while(root->rleft()!=NULL)
	    {
	        root=root->rleft();
	    }
	    return root;
}

template<class Item>
void hash_table<Item>::linktotree(node<Item>*& x){
	treenode<Item>* temp=new treenode<Item>((dynamic_cast<link_node<Item>*>(x)->rkey()),(dynamic_cast<link_node<Item>*>(x)->rval()));
	while(dynamic_cast<link_node<Item>*>(x)->link()!=NULL){
		x=dynamic_cast<link_node<Item>*>(x)->link();
		add_tree(temp,dynamic_cast<link_node<Item>*>(x)->rkey(),dynamic_cast<link_node<Item>*>(x)->rval());

	}
	int linkcount=dynamic_cast<link_node<Item>*>(x)->rlcount();
	temp->set_tcount(linkcount);		//Basically add each element to a tree and then sets
	x=temp;								//Head to tree
}

template<class Item>
void hash_table<Item>::addlink(link_node<Item>*& x, int y, Item z){
	if(x->rlcount()==0){	//Both these next twoo functions carry out the
		x->setkey(y);		//same function but are divided
		x->setval(z);		//for clarity
		x->setptr(NULL);
		x->increase_count();
	}
	else{
		link_node<Item>* cursor=x;
		while(cursor->link()!=NULL){
			cursor=(cursor)->link();
		}
		link_node<Item>* temp= new link_node<Item>(y,z);
		(cursor)->setptr(temp);
		x->increase_count();
	}
}

template<class Item>
void hash_table<Item>::addtolink(link_node<Item>*& x, int y, Item z){
	if(x->rlcount()==0){
		x->setkey(y);
		x->setval(z);
		x->setptr(NULL);
		increasetemplink();
	}
	else{
		link_node<Item>* cursor=x;
		while(cursor->link()!=NULL){
			cursor=(cursor)->link();
		}
		link_node<Item>* temp= new link_node<Item>(y,z);
		(cursor)->setptr(temp);
		increasetemplink();
	}
}

template<class Item>
void hash_table<Item>::treetolink(node<Item>* x){	//recursively adds the helper link templink
	if(x==NULL){return;}
	link_node<Item>* temp=&templink;
	addtolink(temp,dynamic_cast<treenode<Item>*>(x)->rkey(),dynamic_cast<treenode<Item>*>(x)->rval());
	node<Item>* temp2=dynamic_cast<treenode<Item>*>(x)->rleft();
	node<Item>* temp3=dynamic_cast<treenode<Item>*>(x)->rright();
	treetolink(temp2);
	treetolink(temp3);
}

template<class Item>
void hash_table<Item>::copylink(link_node<Item>*& x,link_node<Item>* y){
	link_node<Item>* cursor=y;	//Copies a link list into another
	while(cursor!=NULL){
		addlink(x,cursor->rkey(),cursor->rval());
		cursor=cursor->link();
	}
	int temp=y->rlcount();
	x->set_count(temp);

}

template<class Item>
void hash_table<Item>::makeit(node<Item>*& x, link_node<Item>*& y){
	link_node<Item>* temp=new link_node<Item>;	//Sets head to linknode y
	temp->set_count(0);
	copylink(temp,y);
	x=temp;
}

template<class Item>
void hash_table<Item>::helprehash(hash_table<Item>& x, treenode<Item>* y){
	if(y==NULL){return;}
	x.put(y->rkey(),y->rval());
	treenode<Item>* temp1=y->rleft();
	treenode<Item>* temp2=y->rright();
	helprehash(x,temp1);
	helprehash(x,temp2);

}


template<class Item>
void hash_table<Item>::rehash(){	//Rehash the function
	int current_size=size;
	int newsize=size*2;
	hash_table<Item> temp(newsize);
	for(int i=0;i<current_size;i++){
		node<Item>* tempnode=this->data[i];
		if(tempnode==NULL){continue;}
		else if((typeid(*tempnode)==typeid(link_node<Item>))){
			node<Item>* cursor=tempnode;
				while(cursor!=NULL){
					temp.put(dynamic_cast<link_node<Item>*>(cursor)->rkey(),dynamic_cast<link_node<Item>*>(cursor)->rval());
					cursor=dynamic_cast<link_node<Item>*>(cursor)->link();
				}
		}
		else{
			treenode<Item>* temptree=dynamic_cast<treenode<Item>*>(tempnode);
			helprehash(temp,temptree);
		}

	}
	hash_table<Item>* tempdelete=this;
	this->data=temp.data;
	tempdelete->cleartable();
}



