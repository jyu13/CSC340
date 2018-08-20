// Default constructor
#include "tree.h"
#include <iostream>

using namespace std;

Tree::Tree(){
	start = NULL;
}

// Copy constructor
Tree::Tree(const Tree& other){
	if(other.start == NULL){
		start = NULL;
	}else{
		start = NULL;
		copyOther(other);
	}
}

// overloaded Assignment Operator
Tree& Tree::operator=(const Tree& other){
	if(other.start == NULL){
		clear();
		start = NULL;
	}
	else{
		clear();
		start = NULL;
		copyOther(other);
	}
	return *this;
}

//copyOther
// you should implement and use this helper function inside your
// copy constructor and overloadedAssignment operator.
void Tree::copyOther(const Tree& other){
	if(other.start == NULL){
		return;
	}
	else{
		copyFrom(other.start);
	}
}

// copyFrom
// Recursively copy another tree's nodes. Use
// pre-order traversal. Use this in CopyOther function.
void Tree::copyFrom(TreeNode* startingPoint){
	if(NULL == startingPoint)
		return;
	push(startingPoint->value);
	copyFrom(startingPoint->left);
	copyFrom(startingPoint->right);	
}

//Destructor
Tree::~Tree(){
	cout<<"In destructor."<<endl;	
	if(start == NULL)
		return;
	else
		clear();
		
}

// clear
// you should implement and use this function inside your 
// destructor to delete all the nodes and free memory
void Tree::clear(){
	cout<<"Deleting"<<endl;
	clearFrom(start);
	cout<<start->value<<endl;
	delete start;
	start = NULL;
}

// clearFrom
// Recursively delete nodes. Use post-order traversal.
// Use it in clear function.
void Tree::clearFrom(TreeNode* startingPoint){
	if(startingPoint->left == NULL && startingPoint->right == NULL){
		return;
	}

	if(startingPoint->left != NULL){
		clearFrom(startingPoint->left);
		cout << startingPoint->left->value << " ";
		delete startingPoint->left;
		startingPoint->left = NULL;
	}
	if(startingPoint->right != NULL){
		clearFrom(startingPoint->right);
		cout << startingPoint->right->value << " ";
		delete startingPoint->right;
		startingPoint->right = NULL;
	}
}


// Similar to insert function we discussed earlier
// creates node and inserts it at appropriate position.
void Tree::push(int value){
	TreeNode* newTreeNode = new TreeNode;
	newTreeNode->value = value;
	if(start == NULL){
		start = newTreeNode;
	}else{
			pushFrom(start, newTreeNode);

	}
}

// pushFrom
// Recursively push a single element into a tree.
// Use it in your push function.
void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush){
	if(nodeToPush->value > startingPoint->value){
		if(startingPoint->right == NULL){
			startingPoint->right = nodeToPush;
		}else
			pushFrom(startingPoint->right,nodeToPush);
	}else{
		if(startingPoint->left == NULL){
			startingPoint->left = nodeToPush;
		}else
		pushFrom(startingPoint->left, nodeToPush);
	}
}

// Returns the address of the node containing the value.
TreeNode* Tree::find(int value) const{
	if(start == NULL)
		return NULL;
	findFrom(start, value);
	
}

// findFrom
// Recursively find a single element in a tree.
TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const{
	if(startingPoint == NULL)
		return startingPoint;
	else if(value == startingPoint->value){
		return startingPoint;
	}else if(value < startingPoint->value){
		findFrom(startingPoint->left, value);
	}else{
		findFrom(startingPoint->right, value);
	}
}

// Print the tree data
void Tree::print() const{
	printFrom(start,0);
}

//  Helper function that you should use inside your print function
void Tree::printFrom(TreeNode* startingPoint, int numSpaces) const{
	if(startingPoint == NULL)
		return;
	string spaces = "";
	for(int i = 0 ; i < numSpaces;i++){
		spaces += " ";
	}
	
	cout<<spaces<<startingPoint->value<<endl;
	printFrom(startingPoint->left, numSpaces+2);
	printFrom(startingPoint->right, numSpaces+2);

}

// Deletes the node with value in the tree and deallocates its memory.
void Tree::deleteNode(int value){
	if(NULL == start)
		return;
	else if(value == start->value){		//if value equals to start value
		if(start->left != NULL){		//if start has left treeNode, find largest
			int large = largestLeft(start->left);
			deleteFrom(start->left , large);
			start->value = large;
		}else if(start->right != NULL){ //if start only has right treeNode
			TreeNode* temp = start;
			start = start->right;
			delete temp;
			temp = NULL;
		}else{							//if start has no child treeNodes
			delete start;
			start = NULL;
		}
		
	}else
		deleteFrom(start, value);
}


// deleteFrom
// should implement and use in the delete function.
// Deletes the node with the value specified in the below function. 

void Tree::deleteFrom(TreeNode* startingPoint, int value){
	
	if(startingPoint->left->value == value){
		if(startingPoint->left->left == NULL && startingPoint->left->right == NULL){   //delete if it is a leaf node
			delete startingPoint->left;
			startingPoint->left = NULL;
		}
		else if(startingPoint->left->right == NULL){		//delete if it has one children
			TreeNode* temp = startingPoint->left;
			startingPoint->left = startingPoint->left->left;
			delete temp;
		}
		else if(startingPoint->left->left == NULL){			//delete if it has one children
			TreeNode* temp = startingPoint->left;
			startingPoint->left = startingPoint->left->right;
			delete temp;
		}
		else{	//delete if it has two children
			//find largest value on the left tree
			int largest = largestLeft(startingPoint->left);
			startingPoint->left->value = largest;
			deleteFrom(startingPoint->left, largest);			
		}
	}
	else if(startingPoint->right->value == value){
		if(startingPoint->right->left == NULL && startingPoint->right->right == NULL){	//delete if it is a leaf node
			delete startingPoint->right;
			startingPoint->right = NULL;
		}
		else if(startingPoint->right->right == NULL){		//delete if it has one children
			TreeNode* temp = startingPoint->right;
			startingPoint->right = startingPoint->right->left;
			delete temp;
		}
		else if(startingPoint->right->left == NULL){		//delete if it has one children
			TreeNode* temp = startingPoint->right;
			startingPoint->right = startingPoint->right->right;
			delete temp;
		}
		else{	//delete if it has two children
			//find largest value on the left tree
			int largest = largestLeft(startingPoint->left);
			startingPoint->left->value = largest;
			deleteFrom(startingPoint->left, largest);
		}		
	}
	else{
		if(value < startingPoint->value){
			deleteFrom(startingPoint->left, value);
		}
		else{
			deleteFrom(startingPoint->right, value);
		}
	}
}


//find the largest value on the left tree of the node
int Tree::largestLeft(TreeNode* startingPoint){
	//if it is a leaf node, return the value
	if(startingPoint->left == NULL && startingPoint->right == NULL){
		return startingPoint->value;
		
	}else{
		// the largest value always appeared on right node
		while(startingPoint->right != NULL)
			startingPoint = startingPoint->right;
		return startingPoint->value;
	}
}
