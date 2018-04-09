/*
Andy Matthew Guinto
*/

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

public:
	BinaryST();
	~BinaryST();
	Node* CreateNode(int data);	
	void AddNode(int data);		
	void PrintTraversal();
	void DeleteNode(int data);
	
};


