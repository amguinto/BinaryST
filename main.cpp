/*
Andy Matthew Guinto
*/

#include "BinaryST.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {

	//vector<int> Tree = { 50, 27, 25, 34, 10, 4 };
	BinaryST bst;

	bst.AddNode(5);
	bst.AddNode(2);
	bst.AddNode(1);
	bst.AddNode(6);
	bst.AddNode(4);

	bst.PrintTraversal();

	bst.DeleteNode(4);
	//bst.PrintTraversal();
	return 0;
}