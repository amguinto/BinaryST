/*
Andy Matthew Guinto
*/

#include "BinaryST.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Call BinaryST class, structure, and constructor.
BinaryST::BinaryST() {
	root = NULL;
};
BinaryST::~BinaryST() {};

//Need class before return type since it needs to return a Node*, and not a system return type from the BinaryST
BinaryST::Node* BinaryST::CreateNode(int data) {
	Node* temp = new Node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;

	return temp;
};

void BinaryST::AddNode(int data) {
	RecursiveAdd(data, root);
};

void BinaryST::RecursiveAdd(int data, Node* addPtr) {
	if (root == NULL) {
		root = CreateNode(data);
	}
	//Less than, go left.
	else if (data <= addPtr->data) {
		//If there is a left node existing, then recursively go back down the tree again.
		if (addPtr->left != NULL) {
			RecursiveAdd(data, addPtr->left);
		}
		else {
			addPtr->left = CreateNode(data);
		}
	}
	//Greater than, go right.
	else if (data > addPtr->data) {
		//If there is a right node existing, then recursively go back down the tree again.
		if (addPtr->right != NULL) {
			RecursiveAdd(data, addPtr->right);
		}
		else {
			addPtr->right = CreateNode(data);
		}

	}
};

void BinaryST::PrintTraversal() {
	RecursivePrintTraversal(root);
};
void BinaryST::RecursivePrintTraversal(Node* temp) {

	if (root != NULL) {
		if (temp->left != NULL) {
			//Reach the lowest level possible.
			RecursivePrintTraversal(temp->left);
		}
		cout << temp->data << " ";

		if (temp->right != NULL) {
			RecursivePrintTraversal(temp->right);
		}		
	}
	else {
		cout << "The tree is empty" << endl;
	}
};

void BinaryST::DeleteNode(int data) {
	RecursiveDelete(data, root);
}


void BinaryST::RecursiveDelete(int data, Node* temp) {
	//Root is passed in first.
	if (temp == NULL) {
		cerr << "The tree is empty." << endl;
	}//Found it.
	else if (data == temp->data) {
		Node* reAttach = NULL;
		Node* current = NULL;

		//No Children.
		if(temp->left == NULL && temp->right == NULL) {
			delete temp;
		}
		else if (temp->left != NULL) {
			current = temp;
			delete temp;
		}
		else if (temp->right != NULL) {
			current = temp->right;
		}
		cout << data << " was deleted." << endl;
	}//Keep going left.
	else if (data < temp->data ) {
		RecursiveDelete(data, temp->left);
	}//Keep going right.
	else if (data > temp->data) {
		RecursiveDelete(data, temp->right);
	}//Did not find it.
	else {
		cerr << data << "is not in the tree." << endl;
	}
}


