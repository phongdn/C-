#pragma once
#include "BST.h"
#include "Node.h"
#include "TransactionNode.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

class DataAnalysis
{
public:
	DataAnalysis();
	DataAnalysis(DataAnalysis & copy);
	~DataAnalysis();

	DataAnalysis & operator=(DataAnalysis & copy);

	void runAnalysis();
	//Member functions :
	//-A function that opens data.csv // yes, it’s private, and must use mCsvStream to open the file
	//	- A function that reads one line from the file and splits the line into units, type, and transaction fields
	//	- A function that loops until all lines are read from the file; calls the function below, and then displays the current contents of both BSTs; use inOrderTraversal() to display the trees
	//	- A function that compares the transaction field and inserts the units and type into the appropriate tree(mTreeSold or mTreePurchased) // note with the way the data.csv file is organized the trees will be fairly balanced
	//	- A function that writes to the screen the trends we see in our tree; the function must display the type and number of units that are least purchased and sold, and the most purchased and sold
	//	+ runAnalysis(), which is the only public function in the class, aside from possibly a constructor and / or destructor; this function calls the other private functions
private:
	BST * mTreeSold;
	BST * mTreePurchased;
	ifstream mCsvStream;

	void openFile(); //Opens the file
	void readFile(); //Reads each line, adds each section to the corret field, and calls insert()
	void insert(int units, string type, string transaction); //Checks to see which tree to insert at and calls the BST insert() function
	void printTrends(); //Prints the trend from each tree
};
