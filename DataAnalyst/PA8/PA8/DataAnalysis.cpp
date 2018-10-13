#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
	this->mTreePurchased = new BST();
	this->mTreeSold = new BST();
}
DataAnalysis::DataAnalysis(DataAnalysis & copy)
{
	this->mTreePurchased = new BST(copy.mTreePurchased); //Uses the BST Copy Constructor
	this->mTreeSold = new BST(copy.mTreeSold);
}
DataAnalysis::~DataAnalysis()
{
	delete mTreePurchased;
	delete mTreeSold;
}

DataAnalysis & DataAnalysis::operator=(DataAnalysis & copy)
{
	this->mTreePurchased = new BST(copy.mTreePurchased); //Uses the BST Copy Constructor
	this->mTreeSold = new BST(copy.mTreeSold);
	return (*this);
}

void DataAnalysis::runAnalysis() //Calls Private Functions
{
	openFile();
	printTrends();
}


//-------Private Functions---------
void DataAnalysis::openFile() //Calls readFile()
{
	this->mCsvStream.open("data.csv");
	readFile();
	this->mCsvStream.close();
}
void DataAnalysis::readFile() //Calls insert()
{
	if (!this->mCsvStream.is_open())
		return;
	int units = 0;
	string type = "N/A", transaction = "N/A";
	char line[100];
	mCsvStream.getline(line, 100); //Title/Tags/ No Needed
	while (!mCsvStream.eof())
	{
		mCsvStream.getline(line, 100, ',');
		units = atoi(line);
		mCsvStream.getline(line, 100, ',');
		type = line;
		mCsvStream.getline(line, 100, '\n');
		transaction = line;

		if (mCsvStream.eof()) //Takes care of last empty line
			break;
		//cout << units << "," << type << "," << transaction << endl;
		
		insert(units, type, transaction); // BST Function
	}
	cout << "\n\nPrinting Purchased BST: \n" << endl;
	mTreePurchased->inOrderTraversal();
	cout << "\n\nPrinting Sold BST: \n" << endl;
	mTreeSold->inOrderTraversal();
}
void DataAnalysis::insert(int units, string type, string transaction)
{
	if (transaction == "Purchased")
	{
		this->mTreePurchased->insert(type, units);
	}
	else
	{
		this->mTreeSold->insert(type, units);
	}
}
void DataAnalysis::printTrends()
{
	TransactionNode * pTemp = this->mTreePurchased->findSmallest();
	cout << "\n\n----------Purchased Trend-----------\n" << endl;
	cout << "Purchased Smallest Number of Units:  " << endl;
	pTemp->printData();
	cout << "Purchased Largest Number of Units:  " << endl;
	pTemp = this->mTreePurchased->findLargest();
	pTemp->printData();
	cout << "\n\n----------Sold Trend-----------\n" << endl;
	cout << "Sold Smallest Number of Units:  " << endl;
	pTemp = this->mTreeSold->findSmallest();
	pTemp->printData();
	cout << "Sold Largest Number of Units:  " << endl;
	pTemp = this->mTreeSold->findLargest();
	pTemp->printData();
}