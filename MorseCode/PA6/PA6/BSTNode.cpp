#include "BSTNode.h"

BSTNode::BSTNode(char Text, string Morse) //Constructor
{
	this->mText = Text;
	this->mMorse = Morse;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

BSTNode::BSTNode(const BSTNode &copy) //Shallow Copy
{
	this->mText = copy.mText;
	this->mMorse = copy.mMorse;
	this->mpLeft = copy.mpLeft;
	this->mpRight = copy.mpRight;
}

BSTNode::~BSTNode() //Destructor
{
	delete mpLeft;
	delete mpRight;

	//Will delete child nodes

	//cout << "Inside BSTNode destructor!" << endl;
}

BSTNode & BSTNode::operator= (const BSTNode &copy) //Shallow Copy
{
	this->mText = copy.mText;
	this->mMorse = copy.mMorse;
	this->mpLeft = copy.mpLeft;
	this->mpRight = copy.mpRight;
	return (*this);
}

char BSTNode::getText() const //Returns mText
{
	return this->mText;
}

string BSTNode::getMorse() const //Returns mMorse
{
	return this->mMorse;
}

BSTNode *& BSTNode::getLeft() //Returns address to Left Child 
{
	return this->mpLeft;
}

BSTNode *& BSTNode::getRight() //Returns address to Right Child 
{
	return this->mpRight;
}

void BSTNode::setText(const char newText) //Changes the mText
{
	this->mText = newText;
	//Precondition: Expecting user to also change mMorse to appropriate Morse Code
}

void BSTNode::setMorse(const string newMorse) //Changes the mMorse
{
	this->mMorse = newMorse;
	//Precondition: Expecting user to also change mText to appropriate Text
}
void BSTNode::setLeft(BSTNode * const newLeft) //Changes the mpLeft pointer
{
	this->mpLeft = newLeft;
}

void BSTNode::setRight(BSTNode * const newRight) //Changes the mpRight pointer
{
	this->mpRight = newRight;
}



//ostream & operator<< (ostream &output, const BSTNode &node) //Non Member Function
//{
//	output << "Text: " << node.getText() << endl;
//	output << "Morse: " << node.getMorse() << endl;
//	return output;
//}
