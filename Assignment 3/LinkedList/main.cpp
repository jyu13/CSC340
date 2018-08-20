#include <iostream>

//test file

#include "LinkedList.h"

int main(){

	LinkedList one;
	LinkedList* two =  new LinkedList();
	
	//test pushBack and pushFront
	one.pushFront(.32);
	one.pushFront(2.0);
	one.pushFront(4);
	one.pushFront(2.0);
	one.pushFront(2.0);
	two->pushBack(19.2);
	two->pushFront(1.3);
	two->pushFront(17.43);
	two->pushFront(29.323);	

	one.pushBack(3.5);
	one.pushBack(6.2);
	two->pushBack(10.384);
	
	//test getSize
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
	//test insert, first element is index 0
	one.insert(2,10.32);
	two->insert(4,50.43);
	
	cout<<"List one: "<<one;
	cout<<"size of list one: "<<one.getSize()<<endl;
	cout<<"List two: "<<*two;
	cout<<"size of list two: "<<two->getSize()<<endl;
	
	//test overload operator=
	*two = one;
	one.pushFront(9.9);
	two->pushBack(25.00);

	
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
	cout<<"4 to Last Element is: "<<two->mtoLastElement(4)<<endl;
	cout<<"List one: "<<one;


	one.deleteList();
	cout<<"List one after deleteList: "<<one;
	
	delete two;
}
