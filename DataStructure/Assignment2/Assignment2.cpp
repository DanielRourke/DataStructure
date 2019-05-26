// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "AssAvlTree.h"
#include "CustomString.h"

using namespace std;


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
	bool operator<(const DATA d) const{
		return (info < d.info); //Check if the direction is correct
	}

};


bool addFileToTree(string filename, AvlTree<DATA, CustomString> * tree);

//struct DATA
//{
//	int key;
//	float info;
//	void update() {
//		if (info != NULL)
//			info += 1;
//		else
//			info = 1;
//	}
//
//};


ostream& operator<<(ostream& os, const CustomString cs)
{
	os << cs.val;
	return os;
}



void print(DATA ss) 
{
	cout << ss.key << "," << ss.info << endl;
}

int main()
{
	
	AvlTree<DATA, CustomString> tree;

	cout << "Trying to Open " << "\\Textfiles\\AI_articles_1.txt" << endl;
	addFileToTree("Textfiles/AI_articles_1.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_2.txt" << endl;
	addFileToTree("Textfiles/AI_articles_2.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_3.txt" << endl;
	addFileToTree("Textfiles/AI_articles_3.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_4.txt" << endl;
	addFileToTree("Textfiles/AI_articles_4.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_5.txt" << endl;
	addFileToTree("Textfiles/AI_articles_5.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_6.txt" << endl;
	addFileToTree("Textfiles/AI_articles_6.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_7.txt" << endl;
	addFileToTree("Textfiles/AI_articles_7.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_8.txt" << endl;
	addFileToTree("Textfiles/AI_articles_8.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_9.txt" << endl;
	addFileToTree("Textfiles/AI_articles_9.txt", &tree);
	cout << "Trying to Open " << "\\Textfiles\\AI_articles_10.txt" << endl;
	addFileToTree("Textfiles/AI_articles_10.txt", &tree);


	string min = "";
	cout << "Please enter a word to search for" << endl;
	cin >> min;
	string max = "";

	priority_queue<DATA> results;

	//TODO : rollover z
	results = tree.AVL_RetrieveInRange(min, max += min[0] + 1);

	for (int i = 0; i < 5 && !results.empty(); i++)
	{
		cout << "Key: " << results.top().key << "  Fequency: " << results.top().info << endl;
		results.pop();
	}

	//tree.AVL_Print();
	//cout << endl;

	//tree.AVL_Traverse(print);
}



bool addFileToTree(string filename, AvlTree<DATA, CustomString> * tree)
{
	ifstream readf(filename);

	if (!readf.is_open())
	{
		cout << "Error opening file" << endl;
		return false;
	}
	else
	{

		cout << "Opened file: " << endl;
		if ((*tree).AVL_Empty())
			cout << "Empty tree." << endl;

		DATA newItem;
		string word = "";
		char c;
		while ((c = readf.get()) != EOF)
		{
			if (c > 255 || c < 0)
			{
				continue;
			}
			if (isalpha(c))
			{
				word += tolower(c);
			}
			else if (c == ' ' || readf.peek() == EOF)
			{
				newItem.info = 1;
				newItem.key = word;
				(*tree).AVL_Update(word, newItem);
				word = "";
			}
		}

		cout << "File added to tree." << endl;

	}
	return true;
}

//template <class TYPE>
//bool addEntryToHeap(TYPE data)
//{
//	//for the length of string
//	for (int i = 0; i < input.length(); i++)
//	{
//		if (data.key[i] != input[i])
//		{
//			return false;
//		}
//	}
//	
//	//
//
//}