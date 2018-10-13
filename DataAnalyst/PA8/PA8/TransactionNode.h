#pragma once
#include "Node.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class TransactionNode : public Node
{
public:
	TransactionNode(string newData = "N/A", int newUnits = 0);
	TransactionNode(TransactionNode & copy);
	~TransactionNode();

	TransactionNode & operator=(TransactionNode & copy);

	int getUnits() const;
	void setUnits(int newUnits);

	void printData();
	//+destructor // + denotes public
	//	+ constructor which accepts a string to set the data and an integer to set the number of units in the node; should invoke class Node’s constructor
	//	+ setter
	//	+ getter
	//	+ printData(), which overrides the pure virtual function in class Node
private:
	int mUnits;
};