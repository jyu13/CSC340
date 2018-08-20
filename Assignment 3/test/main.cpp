#include "linkedlist.h"

int main(){

	linkedlist one;
	linkedlist two;

	linkedlist* three =  new linkedlist();

	for(int i = 0; i < 5; i++)
		one.append(i);
	for(int i = 0; i < 5; i++)
		two.pushFront(i);
	for(int i = 10; i < 15; i++)
		three->append(i);

	// one.printList();
	// two.printList();

	*three = two;
	three->append(25);
	two.append(99);

	cout<<one;
	cout<<"address of one : "<<&one<<endl;
	cout<<two;
	cout<<"address of two : "<<&two<<endl;
	cout<<*three;
	cout<<"address of three : "<<three<<endl;
	




	if(one == two)
		cout<<"lists are same"<<endl;
	else
		cout<<"not equal"<<endl;

	delete three;



return 0;
}
