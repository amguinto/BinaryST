/*
Andy Matthew Guinto
*/

#include "BinaryST.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {

	vector<int> Tree = { 50, 27, 25, 34, 10, 4 };
	BinaryST bst;

	ManipulateTree mt;

	//Test.
	mt.PrintTraversalOrder();

	//cout << "Setting up tree..." << endl;
	//Create Tree.
	for (unsigned int i = 0; i < Tree.size(); i++) {
		mt.AddNode(Tree[i]);
		cout << "Adding " << Tree[i] << " into the tree." << endl;
	}
	mt.PrintTraversalOrder();

	return 0;
}