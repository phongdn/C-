#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
class Node
{
public:
	Node(string newData = "N/A");
	Node(Node & copy);
	virtual ~Node(); //Virtual

	Node & operator=(Node & copy);

	Node *& getLeft();
	Node *& getRight();
	string getData() const;

	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);
	void setData(string newData);

	virtual void printData() = 0; //Pure Virtual Function

protected:
	string mData;
	Node * mpLeft;
	Node * mpRight;
};