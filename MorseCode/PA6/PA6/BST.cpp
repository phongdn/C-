#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
	mfileHandler.open("MorseTable.txt");
	if (mfileHandler.is_open())
	{
		char t;
		string m;

		while (!mfileHandler.eof())
		{
			mfileHandler >> t; //Extracts first Char
			mfileHandler >> m; //Extracts the String on the same line
			insert(t, m); //Calls insert to create a node and add it to BST
		}
	}
	mfileHandler.close();
}

BST::BST(BST &copy) 
{
	if (copy.mpRoot == nullptr)
		mpRoot = nullptr;
	else
		copyTree(this->mpRoot, copy.mpRoot); //Calls Private Function
}

BST::~BST()
{
	delete mpRoot; //This will recursively delete the BST with the destructor from the BSTNode class
	//this->deleteTree(this->mpRoot); //Calls Private Function
}

BST & BST::operator= (BST &copy) 
{
	if (copy.mpRoot == nullptr)
		mpRoot = nullptr;
	else
		copyTree(this->mpRoot, copy.mpRoot); //Calls Private Function
	return(*this);
}

BSTNode * BST::getRoot() const
{
	return this->mpRoot;
}

void BST::setRoot(BSTNode * const newRoot)
{
	this->mpRoot = newRoot;
}

void BST::print()
{
	print(mpRoot);
}

string BST::Search(char text)
{
	BSTNode * pMem;
	pMem = Search(text, mpRoot); //Returns nullptr if not in BST, otherwise returns the node with the correct text
	if (pMem == nullptr)
	{
		return "Character not in Tree!";
	}
	return pMem->getMorse();
}

void BST::insert(char text, string morse)
{
	insert(mpRoot, text, morse); //Calls a Private Function
}

void BST::run() //Runs the Program
{
	mfileHandler.open("Convert.txt"); //Given English Sentence to Convert
	if (mfileHandler.is_open())
	{
		char c;
		while (true)
		{

			mfileHandler.get(c); //Extracts a single character per loop
			//cout << c << endl; --> Test Code for Operator Function
			if (mfileHandler.eof())
			{
				break; //Exits Loop
			}

			if (c == 32) //Space character in ASCII
			{
				cout << "  ";
			}
			else if (c == '\n') //NewLine
			{
				cout << endl;
			}
			else
			{
				cout << Search(toupper(c)) << " "; //Converts character to uppercase and search BST for extracted Character
			}
		}
	}
	mfileHandler.close(); 
}

void BST::copyTree(BSTNode *& pMem, BSTNode *& pCopy) //PreOrder Traversal
{
	if (pCopy == nullptr)
	{
		pMem = nullptr; 
	}
	else
	{
		pMem = new BSTNode(pCopy->getText(), pCopy->getMorse()); //Allocates a new node
		copyTree(pMem->getLeft(), pCopy->getLeft());
		copyTree(pMem->getRight(), pCopy->getRight());
	}
}

//Apparently this function is not needed as C++ already has its own default destructor to deal with BST by using the BSTNode destructor to
// recursively delete the BST. 
//This Function provides another way to recursively delete the BST
//void BST::deleteTree(BSTNode *& pMem) //PostOrder Traversal
//{
//	if (pMem != nullptr) 
//	{
//		deleteTree(pMem->getLeft());
//		deleteTree(pMem->getRight());
//		delete(pMem); //Deletes current node
//	}
//}

void BST::print(BSTNode *& cur) //InOrder Traversal
{
	if (cur != nullptr)
	{
		print(cur->getLeft());
		//cout << cur;
		cout << "English Text: " << cur->getText() << endl;
		cout << "Morse Code: " << cur->getMorse() << endl;
		cout << " " << endl;
		print(cur->getRight());
	}
}

BSTNode * BST::Search(char text, BSTNode *& cur) //Recursively searches BST
{
	if (cur == nullptr)
	{
		return nullptr;
	}
	BSTNode * pMem = cur;
	if (text < pMem->getText())
	{
		Search(text, pMem->getLeft());
	}
	else if (text > pMem->getText())
	{
		Search(text, pMem->getRight());
	}
	else
	{
		return pMem;
	}
}

void BST::insert(BSTNode *& pTree, char text, string morse)
{
	if (pTree == nullptr) //Checks if the BST is empty
	{
		pTree = new BSTNode(text, morse);
	}
	else if (text < pTree->getText())
	{
		insert(pTree->getLeft(), text, morse);
	}
	else if (text > pTree->getText())
	{
		insert(pTree->getRight(), text, morse);
	}
	else
	{
		cout << "Duplicate Text" << endl;
	}
}

bool BST::isEmpty() //Checks to see if BST is empty
{
	if (mpRoot == nullptr)
		return true;
	return false;
}

//ostream & operator<< (ostream &output, const BSTNode *& node) //Non Member Function
//{
//	output << node->getText() << endl;
//	output << node->getMorse() << endl;
//	return output;
//}

