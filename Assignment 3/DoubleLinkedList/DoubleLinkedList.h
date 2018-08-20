//header
#include <iostream>
using namespace std;

#pragma once

class DoubleLinkedList{
	private:
		struct node{
			int data;
			node* next;
			node* previous;
		};
		int size;
		node* head;
		node* tail;
	public:
		DoubleLinkedList();
		DoubleLinkedList(int val);
		//big-3
		DoubleLinkedList(const DoubleLinkedList& that);
		DoubleLinkedList& operator=(const DoubleLinkedList& rhs); 
		~DoubleLinkedList();
		
		void printList() const;
		void deleteList();
		void pushFront(int data);
		void pushBack(int data);
		void popFront();
		void popBack();
		void insert(int index,int val);
		void deleteDuplicates(int val);
		int mtoLastElement(int M) const;
		int getSize() const;
		friend ostream& operator<<(ostream& out, const DoubleLinkedList& rhs);
		void reverseList();
		
};
