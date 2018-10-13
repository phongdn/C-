#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData, int newUnits)
{
	this->mData = newData;
	this->mUnits = newUnits;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}
TransactionNode::TransactionNode(TransactionNode & copy) //Shallow Copy //Left and Right pointers will be taken cared of by BST Copy constructor
{
	this->mData = copy.mData;
	this->mUnits = copy.mUnits;
}
TransactionNode::~TransactionNode()
{
	//Does Nothing, No Dynamic Memory Allocated for this class
}

TransactionNode & TransactionNode::operator=(TransactionNode & copy) //Shallow Copy //Left and Right pointers will be taken cared of by BST Copy constructor
{
	this->mData = copy.mData;
	this->mUnits = copy.mUnits;
	return (*this);
}

int TransactionNode::getUnits() const
{
	return this->mUnits;
}
void TransactionNode::setUnits(int newUnits)
{
	this->mUnits = newUnits;
}
void TransactionNode::printData()
{
	cout << "Type: " << this->mData << endl << "Units: " << this->mUnits << endl;
}