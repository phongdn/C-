#include "BST.h"

int main(void)
{
	BST * Test = new BST();
	cout << "--------------Printing Morse BST----------" << endl;
	cout << endl;
	Test->print(); //Prints the BST of the Morse Table
	cout << endl;
	cout << "---------Converting Sentence in \"Convert.txt\" to Morse Code--------" << endl;
	cout << endl;
	cout << endl;
	Test->run(); //Runs the program
	cout << endl;
	cout << endl;
	return 0;
}