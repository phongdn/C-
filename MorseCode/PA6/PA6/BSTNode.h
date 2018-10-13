#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::ostream;

class BSTNode
{
public:
	BSTNode(char Text = 'A', string Morse = ".-"); //Default Constructor. If Object is made with no arguments, it will use the letter 'A' as a default
	BSTNode(const BSTNode &copy); //Shallow Copy
	~BSTNode(); //Destructor - Deletes Left and Right Child Nodes

	BSTNode & operator= (const BSTNode &copy); //Shallow Copy

	char getText() const; //Returns mText
	string getMorse() const; //Returns mMorse
	BSTNode *& getLeft(); //Returns mpLeft
	BSTNode *& getRight(); //Returns mpRight

	void setText(const char newText); //Setter for mText
	void setMorse(const string newMorse); //Setter for mMorse
	void setLeft(BSTNode * const newLeft); //Setter for mpLeft
	void setRight(BSTNode * const newRight); //Setter for mpRight

private:
	char mText; //English Alphabet Text
	string mMorse; //Morse Code Equivalent to the given text
	BSTNode *mpLeft; //Left Child Node
	BSTNode *mpRight; //Right Child Node
};
 
//Possible NonMember Functions to implement 

//fstream & operator>> (fstream &fileHandler, BSTNode &tree);
//fstream & operator<< (fstream &fileHandler, BSTNode &tree);
//ostream & operator<< (ostream &output, const BSTNode *&node);  ---> Could not figure this one out. Code commented out at bottom of BST.cpp