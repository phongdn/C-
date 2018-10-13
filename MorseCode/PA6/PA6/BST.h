#pragma once
/*******************************************************************************************
* Programmer: Phong Nguyen                                                                       *
* Class: CptS 122, Spring 2017; Lab Section 2                                            *
* Programming Assignment: PA-6                                                  *
* Date: March 20, 2017                                                                         *
* Description: This program extracts characters from a file and converts it into morse code and displays it to the screen*
*******************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::ostream;

class BST
{
public:
	BST(); //Constructor
	BST(BST &copy); //Deep Copy - Calls copyTree Function
	~BST(); //Destructor 

	BST & operator= (BST &copy); //Deep Copy - Calls copyTree Function

	BSTNode * getRoot() const; //Returns mpRoot

	void setRoot(BSTNode * const newRoot); //Changes mpRoot
	void print(); //Calls the Private Print Function
	string Search(char text); //Calls the Private Search Function
	void insert(char text, string morse); //Calls the Private Insert Function

	bool BST::isEmpty(); //Checks if BST is empty

	void run(); //Runs the program

private:
	BSTNode *mpRoot; //Top of the BST
	fstream mfileHandler; //File Handler

	void print(BSTNode *& cur); //Prints the BST of the Morse Table
	BSTNode * Search(char text, BSTNode *& cur); //Search the BST for the Text and returns the Morse Code Equivalent
	void insert(BSTNode *& pTree, char text, string morse); //Creates BSTNodes and Adds them to the BST

	void copyTree(BSTNode *& pMem, BSTNode *& pCopy); //Called by Copy Constructor and Operator= function. Does a Deep copy of the BST to new Tree
	
	//This function is not needed. It is another way to recursively delete the BST
	//void deleteTree(BSTNode *& pMem); //Called by the destructor. Deletes the tree recursively in a PostOrder Traversal
};

//Possible NonMember Functions to implement

//fstream & operator>> (fstream &fileHandler, BST &tree);
//fstream & operator<< (fstream &fileHandler, BST &tree);
//ostream & operator<< (ostream &output, const BST &tree);
