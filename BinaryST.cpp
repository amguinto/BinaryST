/*
Andy Matthew Guinto
*/

#include "BinaryST.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Call BinaryST class, structure, and constructor.
BinaryST::BinaryST() {
	/*cout << "Class BinaryST's Constructor is called." << endl;*/
	root = NULL;
};
BinaryST::~BinaryST() {/*cout << "Class BinaryST's Destructor is called." << endl;*/}
ManipulateTree::ManipulateTree() {/*cout << "ManipulateTree's Constructor is called." << endl;*/}
ManipulateTree::~ManipulateTree() {/*cout << "ManipulateTree's Destructor is called." << endl;*/}

//Set New Node.
//Need class before return type since it needs to return a Node*, and not a system return type from the ManipulateTree
ManipulateTree::Node* ManipulateTree::CreateNode(int data) {
	//Data = temp.
	Node* temp = new Node;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
};

void ManipulateTree::AddNode(int data) {

	RecursiveAdd(data, root);
};

void ManipulateTree::RecursiveAdd(int data, Node* foo) {

	if (root == NULL) {
		root = CreateNode(data);
	}
	//If the data we are trying to add is less than or equal to the current data, go left.
	else if (data <= foo->data) {
		//If there is a left node existing, then recursively go back down the tree again.
		if (foo->left != NULL) {
			//This time, pass in the data that we are trying to add, and the currently existing left node.
			RecursiveAdd(data, foo->left);
		}
		//If not, then take the NULL left pointer value and set it equal to the data we are trying to add.
		else {
			foo->left = CreateNode(data);
		}
	}
	//If the data we are trying to add is greater than the current data, go right.
	else if (data > foo->data) {
		//If there is a right node existing, then recursively go back down the tree again.
		if (foo->right != NULL) {
			//This time, pass in the data that we are trying to add, and the currently existing right node.
			RecursiveAdd(data, foo->right);
		}
		//If not, then take the NULL right pointer value and set it equal to the data we are trying to add.
		else {
			foo->right = CreateNode(data);
		}

	}
};

void ManipulateTree::PrintTraversalOrder() {
	//Root is a pointer, and this function takes in a pointer, so this is valid.
	RecursivePrintTraversalOrder(root);
};
void ManipulateTree::RecursivePrintTraversalOrder(Node* foo) {

	if (root != NULL) {
		//Keep going down left side until we hit the last.
		if (foo->left != NULL) {
			//Since a left pointer exists, keep going down.
			RecursivePrintTraversalOrder(foo->left);
		}
		cout << foo->data << " ";

		if (foo->right != NULL) {
			RecursivePrintTraversalOrder(foo->right);
		}
		
	}
	else {
		cout << "The tree is empty" << endl;
	}
};

void ManipulateTree::DeleteNode(int data) {
	RecursiveDelete(data, root);
}


void ManipulateTree::RecursiveDelete(int data, Node* foo) {
	if (root != NULL) {

	}
}


