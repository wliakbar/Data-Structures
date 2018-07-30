template<class Item>
Item link_node<Item>::get_lnode(int x){
	link_node<Item>* cursor=this;
	if(cursor->rkey()==x){return cursor->rval();}
	while(cursor->link()!=NULL || cursor->rkey()!=x){
		cursor=cursor->link();
		if(cursor->rkey()==x){return cursor->rval();}
	}
	return Item();
}



template<class Item>
void link_node<Item>::lclear(link_node<Item>** head){
	link_node<Item>* current=*head;
	link_node<Item>* next;
	while(current!=NULL){
		next=current->link();
		delete current;
		current=next;
	}
	*head=NULL;
	link_count=0;

}

template<class Item>
void treenode<Item>::cleartree(){
	treenode<Item>* cursor=this;
	if(!cursor->left_child && !cursor->right_child){delete cursor; return;}
	if(cursor->left_child){
		left_child->cleartree();
	}
	else if(cursor->right_child){
		right_child->cleartree();
	}
}


