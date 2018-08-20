//header
#include <iostream>
using namespace std;

#pragma once

class LinkedList{
	private:
		struct node{
			double data;
			node* next;
		};
		int size;
		node* head;
	public:
		LinkedList();
		LinkedList(double val);
		//big-3
		LinkedList(const LinkedList& that);
		LinkedList& operator=(const LinkedList& rhs); 
		~LinkedList();
		
		void printList() const;
		void deleteList();
		void pushFront(double data);
		void pushBack(double data);
		void popFront();
		void popBack();
		void insert(int index,double val);
		void deleteDuplicates(double val);
		double mtoLastElement(int M) const;
		int getSize() const;
		friend ostream& operator<<(ostream& out, const LinkedList& rhs);
		void reverseList();
		
};
