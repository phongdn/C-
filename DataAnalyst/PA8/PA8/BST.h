#pragma once
#include "Node.h"
#include "TransactionNode.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class BST
{
public:
	BST();
	BST(BST *& copy); //Calls duplicateTree()
	~BST();

	BST & operator=(BST *& copy); //Calls duplicateTree()

	Node *& getRoot();

	void setRoot(Node * newRoot);

	void insert(string newData, int newUnits); //Calls Private Function
	void inOrderTraversal(); //Calls private function
	TransactionNode *& findSmallest(); //Traverses to the left-most Node
	TransactionNode *& findLargest(); //Traverses to the right-most Node

	bool isEmpty(); //returns true if empty

	//+destructor // calls destroyTree ()
	//	- destroyTree() // yes, it’s private, and it should visit each node in postOrder to delete them
	//	+ default constructor
	//	+ setter
	//	+ getter
	//	+ insert() // public used to hide pointer information, i.e. won’t pass in the root of the tree into this function, only the private insert () function
	//	- insert() // yes, it’s private, and it dynamically allocates a TransactionNode and inserts recursively in the correct subtree based on mUnits; should pass in a reference to a pointer (i.e. Node *& pT)
	//	+ inOrderTraversal() // yes, once again it’s private to hide pointer information
	//	- inOrderTraversal(), which recursively visits and prints the contents(mData and mUnits) of each node in the tree in order; each node’s printData() should be called
	//	contents should be printed on a separate line; must call the printData() function associated with the TransactionNode
	//	+ findSmallest(), which returns a reference to a TransactionNode(i.e TransactionNode &)  with the smallest mUnits
	//	+ findLargest(), which returns a reference to a TransactionNode with the largest mUnits
private:
	Node * mpRoot;
	void destroyTree(Node *& pCur);
	void insert(string newData, int newUnits, Node *& pT); //Recursive
	void inOrderTraversal(Node *& cur); //Go all the way left, Print, Go all the way right
	void duplicateTree(Node *& pMem, Node *& pCopy); //Called by copy constructor
};