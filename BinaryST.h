/*
Andy Matthew Guinto
*/

class BinaryST {	

protected:
	//What every node should have.
	struct Node {
		int data;
		//Point to nodes.
		Node* left;
		Node* right;
	};
	//Root Node.
	Node* root;

public:
	BinaryST();
	~BinaryST();
};

//Inheritance.
class ManipulateTree : BinaryST {
//Made public to be accessible to main
public:
	Node* CreateNode(int data);

	//Add Node to tree.
	void AddNode(int data);

	//Recursively go through tree.
	void RecursiveAdd(int data, Node* foo);

	//Lowest to Highest Value.
	void PrintTraversalOrder();
	void RecursivePrintTraversalOrder(Node* foo);

	ManipulateTree();
	~ManipulateTree();

	//Delete node from tree.
	void DeleteNode(int data);

	//Recursively delete 
	void RecursiveDelete(int data, Node* foo);
};


