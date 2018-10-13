#include "Node.h"

Node::Node(string newData)
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}
Node::Node(Node & copy) //Shallow Copy //Left and Right pointers will be taken cared of by BST Copy constructor
{
	this->mData = copy.mData;
}
Node::~Node() //Virtual
{
	//Does Nothing, No Dynamic Memory Allocated for this class
}

Node & Node::operator=(Node & copy)
{
	this->mData = copy.mData;
	return (*this);
}

Node *& Node::getLeft()
{
	return this->mpLeft;
}

Node *& Node::getRight()
{
	return this->mpRight;
}

string Node::getData() const
{
	return this->mData;
}

void Node::setLeft(Node * const newLeft)
{
	this->mpLeft = newLeft;
}

void Node::setRight(Node * const newRight)
{
	this->mpRight = newRight;
}

void Node::setData(string newData)
{
	this->mData = newData;
}

void Node::printData()
{
	cout << "Type: " << this->mData << endl;
}