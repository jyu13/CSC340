
//test file

#include "DoubleLinkedList.h"

int main(){

	DoubleLinkedList one;
	DoubleLinkedList* two =  new DoubleLinkedList();
	
	//test pushBack
	one.pushFront(2);
	one.pushFront(2);
	one.pushFront(4);
	one.pushFront(2);
	one.pushFront(2);
	two->pushBack(20);
	two->pushFront(1);
	two->pushFront(17);
	two->pushFront(29);	
	//test pushFront 
	one.pushBack(3);
	one.pushBack(6);
	two->pushBack(10);
	
	cout<<"List one: "<<one;
	cout<<"size of list one: "<<one.getSize()<<endl;
	cout<<"List two: "<<*two;
	cout<<"size of list two: "<<two->getSize()<<endl;
	
	one.popFront();
	two->popBack();
	
	cout<<"List one: "<<one;
	cout<<"size of list one: "<<one.getSize()<<endl;
	cout<<"List two: "<<*two;
	cout<<"size of list two: "<<two->getSize()<<endl;
	
	//first element is index 0
	one.insert(2,10);      
	two->insert(3,50);
	
	cout<<"List one: "<<one;
	cout<<"size of list one: "<<one.getSize()<<endl;
	cout<<"List two: "<<*two;
	cout<<"size of list two: "<<two->getSize()<<endl;
	
	//test overload operator=
	*two = one;
	one.pushFront(99);
	two->pushBack(25);

	
	cout<<"List one: "<<one;
	cout<<"size of list one: "<<one.getSize()<<endl;
	cout<<"List two: "<<*two;
	cout<<"size of list two: "<<two->getSize()<<endl;
		
	//test reverseList
	two->reverseList();
	cout<<"List two after reverse: "<<*two;

	//test deleteDuplicates
	one.deleteDuplicates(2);
	cout<<"List one after deleteDuplicates: "<<one;
	//test mtoLastElement;
	cout<<"List two: "<<*two; 
	cout<<"2 to Last Element is: "<<two->mtoLastElement(2)<<endl;	
	cout<<"5 to Last Element is: "<<two->mtoLastElement(5)<<endl;
	cout<<"List one: "<<one;


	one.deleteList();
	cout<<"List one after deleteList: "<<one;
	
	delete two;
	
	return 0;
}

