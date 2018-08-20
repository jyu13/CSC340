//implemention file

#include "LinkedList.h"

//default constructor
LinkedList::LinkedList(){
	head = NULL;
	size = 0;
}

//constructor with variable val
LinkedList::LinkedList(double val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	head = temp;
	size = 1;
	
}

//copy constructor		
LinkedList::LinkedList(const LinkedList& that){
	cout<<"In copy constructor"<<endl;
	if(that.head == NULL){
		head = NULL;
		size = 0;
	}
	else{
		head = new node;
		this->head = NULL;
		size = 0;
		node* thatTemp = that.head;
		while(thatTemp!=NULL){
			pushBack(thatTemp->data);
			thatTemp = thatTemp->next;
		} 
	}
}

//overload assignment operator
LinkedList& LinkedList::operator=(const LinkedList& that){
	if(that.head == NULL)
		deleteList();
	else{
		deleteList();
		node* thatHead = that.head;
		node* temp = new node;
		head = temp;
		head->data = thatHead->data;
		head->next = NULL;
		thatHead = thatHead->next;
		while(thatHead != NULL){
			node* newNode = new node;
			newNode->data = thatHead->data;
			newNode->next = NULL;
			temp->next = newNode;
			temp = temp->next;
			thatHead = thatHead->next; 			
		}
		size = that.size;
	}
	return *this;
}

//destructor
LinkedList::~LinkedList(){
	cout<<"In destructor"<<endl;
	if(head = NULL)
		return;
	node* temp;
	while(head != NULL){
		temp = head; 
		head = temp->next;
		delete temp;
		temp = NULL;
	}
	head = NULL;
	size = 0;
}

//print out the data in the linkedlist		
void LinkedList::printList() const{
	node* walk = head;
	while(walk != NULL){
		cout<<walk->data<<" ";
		walk = walk->next;
	}
}

//delete the whole linkedlist
void LinkedList::deleteList(){
	if(head == NULL)
		return;
	else{
		node* temp;
		while(head != NULL){
			temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
		}
		head = NULL;
		size = 0;
		
	}
}

//insert at front of the linkedlist
void LinkedList::pushFront(double data){
	node* temp = new node;
	temp->data = data;
	temp->next = head;
	head = temp;
	size++;
}

//insert at last of the linkedlist
void LinkedList::pushBack(double data){
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else{
		node* last = head;
		while(last->next != NULL)
			last = last->next;
		last->next = temp;
	}
	size++; 
}

//delete first node
void LinkedList::popFront(){
	if(head == NULL)
		return;
	else{
		node* first = head;
		head = head->next;
		delete first;
		first = NULL;
		size--;
	}
}

//delete last node
void LinkedList::popBack(){
	if(head == NULL)
		return;
	else{
		node* last = head;
		while(last->next->next !=NULL)
			last = last->next;
		delete last->next;
		last->next = NULL;
		size--;
	}
}

//insert a node into any position of the linkedlist
void LinkedList::insert(int index,double val){
	if(index > size)
		cout<<"index doesn't exist"<<endl;
	else{
		if(index==0)
			pushFront(val);
		else{
		
			node* temp = head;
			node* newNode = new node;
			for(int i = 1 ; i < index; i++)
				temp = temp->next;
			newNode->data = val;
			newNode->next = temp->next;
			temp->next = newNode;
			size++;	
		}
	}
}

//delete duplicate of variable val
void LinkedList::deleteDuplicates(double val){
	if(head == NULL)
		return;

	while(head->data == val){
		popFront();
	}
	
	node* temp = head->next;
	node* beforeTemp = head;
	while(temp != NULL){
		if(temp->data == val){
			node* d = temp;
			temp = temp->next;
			beforeTemp->next = temp;
			delete d;
			d = NULL;
			size--;
		}
		else{
			beforeTemp = temp;
			temp = temp->next;
		}
	}
}

//return m to lastelement
double LinkedList::mtoLastElement(int M) const{
	if(M>size){
		cout<<"List is smaller than M"<<endl;
		return 0;
	}

	else{
		int index = size-M-1;
		node* temp = head;
		for(int i = 0 ; i < index; i++)
			temp = temp->next;
		return temp->data;
	}
}

//get size of linkedlist
int LinkedList::getSize() const{
	return size;
}

//overload << operator 
ostream& operator<<(ostream& out, const LinkedList& rhs){
	rhs.printList();
	cout<<endl;
	return out;	
}

//reverseList reverse the linkedlist 
void LinkedList::reverseList(){
	if (head == NULL)
		return;
	node* temp = head;
	node* prevTemp = NULL;
	node* tempNext;
	for(int i = 0 ; i < size; i++){
		tempNext = temp->next;
		temp->next = prevTemp;
		prevTemp = temp;
		temp = tempNext;
	}
	head = prevTemp;
	
}
