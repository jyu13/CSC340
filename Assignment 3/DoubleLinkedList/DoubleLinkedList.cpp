//implemention file

#include "DoubleLinkedList.h"

//default constructor
DoubleLinkedList::DoubleLinkedList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

//constructor with variable val
DoubleLinkedList::DoubleLinkedList(int val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	temp->previous = NULL;
	head = temp;
	tail = temp;
	size = 1;
	
}
	
//copy constructor	
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& that){
	cout<<"In copy constructor"<<endl;
	if(that.head == NULL){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	else{
		head = new node;
		this->head = NULL;
		head->previous = NULL; 
		size = 0;
		node* thatHead = that.head;
		while(thatHead!=NULL){
			pushBack(thatHead->data);
			thatHead= thatHead->next;
		} 
	}
}

//overload assignment operator
DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& that){
	if(that.head == NULL)
		deleteList();
	else{

		deleteList();		
		node* thatHead = that.head;
		while(thatHead != NULL){
			pushBack(thatHead->data);
			thatHead = thatHead->next; 			
		}
		size = that.size;
	}
	return *this;
}

//destructor
DoubleLinkedList::~DoubleLinkedList(){
	cout<<"In destructor"<<endl;
	if(head = NULL)
		return;
	node* temp;
	while(head != NULL){
		temp = head; 
		head = temp->next;
		head->previous = NULL;
		delete temp;
		temp = NULL;
	}
	head = NULL;
	tail = NULL;
	size = 0;
}

//printout the data of the doublelinkedlist		
void DoubleLinkedList::printList() const{
	node* walk = head;
	while(walk != NULL){
		cout<<walk->data<<" ";
		walk = walk->next;
	}
}

//delete the list
void DoubleLinkedList::deleteList(){
	if(head == NULL)
		return;
	else{
		node* temp;

		while(head->next != NULL){
			temp = head;
			head = head->next;
			head->previous = NULL;
			temp->next = NULL;
			delete temp;
			temp = NULL;
		}
		temp = tail;
		tail->previous = NULL;
		delete temp;
		temp = NULL;
		
		head = NULL;
		tail = NULL;
		size = 0;
		
	}
}

//insert at the front
void DoubleLinkedList::pushFront(int data){
	node* temp = new node;
	temp->data = data;
	temp->previous = NULL;
	if(head == NULL){
		temp->next = NULL;
		head = temp;
		tail = temp;
	}
	else{	 
		temp->next = head;
		head->previous = temp;	
		head = temp;
 	} 
	size++;
}

//insert at the back
void DoubleLinkedList::pushBack(int data){
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		temp->previous = NULL;
		head = temp;
		tail = temp;
	}
	else{
		temp->previous = tail;
		tail->next = temp;
		tail = temp;		
	}
	size++; 
}

//delete the first node
void DoubleLinkedList::popFront(){
	if(head == NULL)
		return;
	else{
		node* first = head;
		head = head->next;
		head->previous = NULL;
		delete first;
		first = NULL;
		size--;
	}
}

//delte the last node
void DoubleLinkedList::popBack(){
	if(tail == NULL)
		return;
	else{
		node* last = tail;
		tail = tail->previous;
		tail->next = NULL;
		delete last;
		last = NULL;
		size--;
	}
}

//insert at any index of the doublelinkedlist
void DoubleLinkedList::insert(int index,int val){
	if(index > size)
		cout<<"index doesn't exist"<<endl;
	else{
		if(index == 0)
			pushFront(val);
		else if(index == size)
			pushBack(val);
		else if(index <= size/2){
			node* temp = head;
			node* newNode = new node;

			for(int i = 0 ; i<index; i++)
				temp = temp->next;			
			newNode->data = val;
			newNode->previous = temp->previous;
			newNode->next = temp;
			temp->previous->next = newNode;
		}
		else{
			node* temp = tail;
			node* newNode = new node;
			for(int i = 1 ; i < size-index; i++)
				temp = temp->previous;
			newNode->data = val;
			newNode->previous = temp->previous;
			newNode->next = temp;
			temp->previous->next = newNode;
		} 
		size++;		
	}
}

//delete duplicates of variable val
void DoubleLinkedList::deleteDuplicates(int val){
	if(head == NULL)
		return;

	while(head->data == val){
		popFront();
	}
	
	node* temp = head->next;
	while(temp != NULL){
		if(temp->data == val){
			node* d = temp;
			temp = temp->next;
			d->previous->next = temp;
			temp->previous = d->previous;
			d->next = NULL;
			d->previous = NULL;
			delete d;
			d = NULL;
			size--;
		}
		else{
			temp = temp->next;
		}
	}
}

//get data of m posiition to the last element
int DoubleLinkedList::mtoLastElement(int M) const{
	if(M >= size){
		cout<<"List index is smaller than "<< M <<endl;
		return 0;
	}
	else{
		int index = size-M-1;
		if(index <= size){
			node* temp = head;
			for(int i = 0 ; i < index; i++)
				temp = temp->next;
			return temp->data;
		}
		else{
			node* temp = tail;
			for(int i = 0 ; i < M+1; i++)
				temp = temp->previous;	
			return temp->data;
		}
	}
}

//get size of the doublelinkedlist
int DoubleLinkedList::getSize() const{
	return size;
}

//overload << operator
ostream& operator<<(ostream& out, const DoubleLinkedList& rhs){
	rhs.printList();
	cout<<endl;
	return out;	
}

//reverse the doublelinkedlist
void DoubleLinkedList::reverseList(){
	if (head == NULL)
		return;
	node* temp = head;
	node* prevTemp = NULL;
	node* tempNext;
	for(int i = 0 ; i < size; i++){
		tempNext = temp->next;
		temp->next = prevTemp;
		temp->previous = tempNext;
		prevTemp = temp;
		temp = tempNext;
	}
	tail = head;
	head = prevTemp;
	
}

