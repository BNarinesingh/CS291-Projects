//Assignment 4.................................................................................................
//CS291 AddressBookProgram Copyright (c) 2015 Barindra Narinesingh. All rights reserved.

#include <iostream>
using namespace std;

class TreeNode {
private: int value;
		 TreeNode* left;
		 TreeNode* right;
		 friend class IntBinaryTree;
};

class IntBinaryTree {
private:
	TreeNode *root;

	void insert(TreeNode *&nodePtr, TreeNode *&newNode) {
		if (nodePtr == nullptr)
			nodePtr = newNode;
		else if (newNode->value < nodePtr->value)
			insert(nodePtr->left, newNode);
		else
			insert(nodePtr->right, newNode);

	};

	void destorySubTree(TreeNode *nodePtr) {
		if (nodePtr)
		{
			if (nodePtr->left)
				destorySubTree(nodePtr->left);
			if (nodePtr->right)
				destorySubTree(nodePtr->right);
			delete nodePtr;
		}
	};

	void deleteNode(int num, TreeNode *&nodePtr) {
		if (num < nodePtr->value)
			deleteNode(num, nodePtr->left);
		else if (num>nodePtr->value)
			deleteNode(num, nodePtr->right);
		else
			makeDeletion(nodePtr);
	};

	void makeDeletion(TreeNode *&nodePtr) {
		TreeNode *tempNodePtr = nullptr;

		if (nodePtr == nullptr)
			cout << "Cannot delete empty node \n ";
		else if (nodePtr->right == nullptr)
		{
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->left;
			delete tempNodePtr;
		}
		else if (nodePtr->left == nullptr)
		{
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;
		}
		else {
			tempNodePtr = nodePtr->right;
			while (tempNodePtr->left)
				tempNodePtr = tempNodePtr->left;
			tempNodePtr->left = nodePtr->left;
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;
			}

	};

	void displayInOrder(TreeNode *nodePtr) const {
		if (nodePtr)
		{
			displayInOrder(nodePtr->left);
			cout << nodePtr->value << endl;
			displayInOrder(nodePtr->right);
		}
	};

	void displayPreOrder(TreeNode *nodePtr) const {
		if (nodePtr)
		{
			cout << nodePtr->value << endl;
			displayPreOrder(nodePtr->left);
			displayPreOrder(nodePtr->right);
		}
	};

	void displayPostOrder(TreeNode *nodePtr) const {
		if (nodePtr)
		{
			displayPostOrder(nodePtr->left);
			displayPostOrder(nodePtr->right);
			cout << nodePtr->value << endl;
		}
	};
	// as per described in class, checks both sides for null then returns a 1, used recursive for ease
	// of tracking down the nodes.

	int countleaf(TreeNode *nodePtr) const {
		if (nodePtr == nullptr)
			return 0;						// not a leaf
		else if (nodePtr->left == nullptr && nodePtr->right == nullptr)
				return 1;					// 1 leaf
			else
				return countleaf(nodePtr->left) + countleaf(nodePtr->right);

		
	};




public:
	IntBinaryTree() { root = NULL; };
	~IntBinaryTree() { destorySubTree(root); };

	void insertNode(int num) {
		TreeNode *newNode = nullptr;
		newNode = new TreeNode;
		newNode->value = num;
		newNode->left = newNode->right = nullptr;
		insert(root, newNode);
	};

	bool searchNode(int num);
	void remove(int num) { deleteNode(num, root); };
	void displayInOrder()const { displayInOrder(root); };
	void displayPreOrder()const { displayPreOrder(root); };
	void displayPostOrder()const { displayPostOrder(root); };
	void displayleafs()const { cout<<"There are "<< countleaf(root)<< "  leafs "<<endl;};
	
	
};



int main(){

	IntBinaryTree tree1, tree2, tree3;

	cout << "\nCreating tree................................................." << endl;

	for (int x = 1; x <= 5; x++)
		tree1.insertNode(x);

	cout << ".......1................." << endl
		<< "......N...2.............." << endl
		<< "........N...3............" << endl
		<< "..........N...4.........." << endl
		<< "............N...5........" << endl
		<< "..............N...N......" << endl;

	cout << "\nTree contains " << endl;
	tree1.displayInOrder();

	tree1.displayleafs();

	cout << "\nCreating class tree ............................................" << endl;
	tree2.insertNode(10);
	tree2.insertNode(4);
	tree2.insertNode(9);
	tree2.insertNode(11);
	tree2.insertNode(12);
	tree2.insertNode(6);

	cout << ".......10................." << endl
		<< "......4...9..............." << endl
		<< "....N...N...11............" << endl
		<< "...........N..12.........." << endl
		<< ".............N...N........" << endl
		<< ".........................." << endl;

	cout << "The class Tree contains " << endl;
	tree2.displayInOrder();

	tree2.displayleafs(); // should be 2 as the class example

	cout << "\nCreating 3rd tree ............................................" << endl;
	tree3.insertNode(8);
	tree3.insertNode(3);
	tree3.insertNode(2);
	tree3.insertNode(11);
	tree3.insertNode(1);
	tree3.insertNode(12);
	tree3.insertNode(6);
	tree3.insertNode(5);

	cout << "..........8.................." << endl
		<< ".......3.....11.............." << endl
		<< ".....2...6..N..12............" << endl
		<< "...1..N.5..N...N..N.........." << endl
		<< "..N.N..N.N..................." << endl
		<< "............................." << endl;

	cout << "The class Tree contains " << endl;
	tree3.displayInOrder();

	tree3.displayleafs(); // should be 3 leafs




	cout << "\nEnd of Program " << endl << endl;
	system("pause");
	return 0;

}

