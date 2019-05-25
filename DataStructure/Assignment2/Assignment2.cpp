// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "AssAvlTree.h"
#include "CustomString.h"

using namespace std;

bool readFile(string filename);

struct DATA
{
	CustomString key;
	float info;
	void update() {
		if (info != NULL)
			info += 1;
		else
			info = 1;
	}
};

ostream& operator<<(ostream& os, const CustomString cs)
{
	os << cs.val;
	return os;
}

bool readFile(string filename)
{
	return true;
}

void print(DATA ss) 
{
	cout << ss.key << "," << ss.info << endl;
}

int main()
{
	AvlTree<DATA, CustomString> tree;
	ifstream readf("article.txt");

	if (!readf.is_open())
	{
		cout << "Error opening file" << endl;
		return -1;
	}
	else
	{

		cout << "Opened file: " << endl;
		if (tree.AVL_Empty())
			cout << "Empty tree." << endl;

		DATA newItem;
		string word = "";
		char c;
		while ((c = readf.get()) != EOF)
		{
			if (isalpha(c))
			{
				word += c;
			}
			else if (c == ' ' || readf.peek() == EOF)
			{
				newItem.info = 1;
				newItem.key = word;
			//	cout << word << " " << endl;
				tree.AVL_Update(word , newItem);
				word = "";
			}
		}


		tree.AVL_Print();
		cout << endl;

		tree.AVL_Traverse(print);

	}
}



