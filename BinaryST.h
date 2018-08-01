/*
Andy Matthew Guinto
*/
#include <queue>

class BinaryST {	
private:
	//What every node should have.
	struct Node {
		int data;
		Node* left;
		Node* right;
	};
	Node* root;

	//Main cannot call these.
	void RecursiveAdd(int data, Node* addPtr);
	void RecursivePrintTraversal(Node* temp);
	void RecursiveDelete(int data, Node* temp);
	
	void RecursivePreOrder ( Node*& root );
	void RecursiveInOrder ( Node*& root );
	void RecursivePostOrder ( Node*& root );

	void RecursiveBreadthFirstTraversal ( Node*& root, std::queue<Node*>& q );

	int RecursiveFindHeight ( Node*& root );

public:
	BinaryST();
	~BinaryST();
	Node* CreateNode(int data);	
	void AddNode(int data);		
	void PrintTraversal();
	void DeleteNode(int data);
	
	//Depth First Search.
	void PreOrderTraversal ( );
	void InOrderTraversal ();
	void PostOrderTraversal ();

	//Level-Order Traversal.
	void BreadthFirstTraversal ();

	//Find Height.
	void FindHeight ();
};


