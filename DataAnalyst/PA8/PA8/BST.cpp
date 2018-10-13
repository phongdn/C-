#include "BST.h"

BST::BST()
{
	this -> mpRoot = nullptr;
}
BST::BST(BST *& copy)
{
	if (copy->mpRoot == nullptr)
	{
		this->mpRoot == nullptr;
	}
	else
	{
		duplicateTree(this->mpRoot, copy->mpRoot);
	}
}
BST::~BST()
{
	delete this->mpRoot;
}

BST & BST::operator=(BST *& copy)
{
	duplicateTree(this->mpRoot, copy->mpRoot);
	return (*this);
}

Node *& BST::getRoot()
{
	return this->mpRoot;
}

void BST::setRoot(Node * newRoot)
{
	this->mpRoot = newRoot;
}

void BST::insert(string newData, int newUnits) //public
{
	insert(newData, newUnits, this->mpRoot);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

TransactionNode *& BST::findSmallest()
{
	Node * pTemp = this->mpRoot;
	while (pTemp->getLeft() != nullptr)
	{
		pTemp = pTemp->getLeft();
	}
	TransactionNode * pReturn = dynamic_cast<TransactionNode*>(pTemp);
	return pReturn;
}

TransactionNode *& BST::findLargest()
{
	Node * pTemp = this->mpRoot;
	while (pTemp->getRight() != nullptr)
	{
		pTemp = pTemp->getRight();
	}
	TransactionNode * pReturn = dynamic_cast<TransactionNode*>(pTemp);
	return pReturn;
}

bool BST::isEmpty() //returns true if empty
{
	if(this->mpRoot == nullptr)
		return true;
	return false;
}

//------------Private Functions------------

void BST::destroyTree(Node *& pCur) //PostOrder
{
	if (pCur == nullptr)
		return;
	destroyTree(pCur->getLeft());
	destroyTree(pCur->getRight());
	delete pCur;
}

void BST::insert(string newData, int newUnits, Node *& pT)
{
	if (pT == nullptr)
	{
		pT = new TransactionNode(newData, newUnits);
		return;
	}

	int units = 0;
	units = dynamic_cast<TransactionNode*>(pT)->getUnits();
	if (newUnits > units)
	{
		insert(newData, newUnits, pT->getRight());
	}
	else  //Less than or equal to
	{
		insert(newData, newUnits, pT->getLeft());
	}
}

void BST::inOrderTraversal(Node *& cur)
{
	if (cur != nullptr)
	{
		inOrderTraversal(cur->getLeft());
		dynamic_cast<TransactionNode*>(cur)->printData();
		inOrderTraversal(cur->getRight());
	}
}

void BST::duplicateTree(Node *& pMem, Node *& pCopy) //Recursion PreOrder
{
	if (pCopy == nullptr)
	{
		pMem = nullptr;
	}
	else
	{
		int units = dynamic_cast<TransactionNode*>(pCopy)->getUnits();
		pMem = new TransactionNode(pCopy->getData(), units);
		duplicateTree(pMem->getLeft(), pCopy->getLeft());
		duplicateTree(pMem->getRight(), pCopy->getRight());
	}
}
