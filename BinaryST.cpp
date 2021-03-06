/*
Andy Matthew Guinto
*/

#include "BinaryST.h"
#include <iostream>
#include <cstdlib>

#include <queue>

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

		//No Children.
		if(temp->left == NULL && temp->right == NULL) {
			delete temp;
		}//1 Right Child.
		else if (temp->left == NULL) {
			temp = temp->right;
			delete temp->right;
		}//1 Left Child.
		else if (temp->right == NULL) {
			temp = temp->left;
			delete temp->left;
		}//Has both left and a right child.
		else {

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
};

void BinaryST::RecursivePreOrder ( Node*& root )
{
	if (root == NULL)
	{
		return;
	}
	std::cout << root->data << " ";

	RecursivePreOrder ( root->left );
	RecursivePreOrder ( root->right );
};

void BinaryST::PreOrderTraversal ()
{
	RecursivePreOrder ( root );
};

void BinaryST::RecursiveInOrder ( Node*& root )
{
	if (root == NULL)
	{
		return;
	}
	RecursiveInOrder ( root->left );
	std::cout << root->data << " ";
	RecursiveInOrder ( root->right );
};

void BinaryST::InOrderTraversal ()
{
	RecursiveInOrder ( root );
}

void BinaryST::RecursivePostOrder ( Node*& root )
{
	if (root == NULL)
	{
		return;
	}
	RecursivePostOrder ( root->left );
	RecursivePostOrder ( root->right );
	std::cout << root->data << " ";
};

void BinaryST::PostOrderTraversal ()
{
	RecursivePostOrder ( root );
};

void BinaryST::RecursiveBreadthFirstTraversal ( Node*& root, std::queue<Node*>& q )
{
	//Going level by level.
	
	if (root->left != NULL)
	{
		q.push ( root->left );
	}
	if (root->right != NULL)
	{
		q.push ( root->right );
	}

	//myQueue.front();
	std::cout << root->data << " ";
	q.pop ();
	if (!q.empty())
	{
		RecursiveBreadthFirstTraversal ( q.front (), q);
	}
	
};

void BinaryST::BreadthFirstTraversal ()
{
	std::queue<Node*> myQueue{};
	myQueue.push ( root );
	RecursiveBreadthFirstTraversal ( root, myQueue );
};

int BinaryST::RecursiveFindHeight ( Node*& root )
{
	if (root == NULL)
	{
		return -1;
	}
	return std::max( RecursiveFindHeight ( root->left ), RecursiveFindHeight ( root->right ) ) + 1;
}

void BinaryST::FindHeight ()
{
	RecursiveFindHeight ( root );
}
