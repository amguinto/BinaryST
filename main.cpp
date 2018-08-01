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

	bst.AddNode(7);
	bst.AddNode(5);
	bst.AddNode(8);
	bst.AddNode(3);
	bst.AddNode(6);
	bst.AddNode(6);
	bst.AddNode(4);
	bst.AddNode(0);
	bst.AddNode(9);
	bst.AddNode(12);
	bst.AddNode(9);

	/*bst.PrintTraversal();
	cout << endl;
	bst.DeleteNode(2);

	bst.PrintTraversal();*/
	std::cout << "PreOrder Traversal: " << std::endl;
	bst.PreOrderTraversal ();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "InOrder Traversal: " << std::endl;
	bst.InOrderTraversal ();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "PostOrder Traversal: " << std::endl;
	bst.PostOrderTraversal ();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Breadth First Traversal " << std::endl;
	bst.BreadthFirstTraversal ();
	std::cout << std::endl;

	return 0;
}