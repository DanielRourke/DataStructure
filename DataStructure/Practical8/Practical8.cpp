// Practical8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "AVL_Tree/AVL_ADT.h"

using namespace std;

int taskOne();
int taskTwo();
int taskThree();

int main()
{
	taskThree();
}


int taskOne()
{
	ifstream readf("article.txt");
	map<string, int> dictoinary;


	if (!readf.is_open())
	{
		cout << "Error opening file" << endl;
		return -1;
	}
	else
	{
		string word = "";
		char c;
		while ((c = readf.get()) != EOF)
		{
			if (isalpha(c))
			{
				word += c;
			}
			else if (c == ' ' || c ==','|| readf.peek() == EOF)
			{
				//add word to tree
				cout << word << endl;
				dictoinary[word] += 1;
				word = "";
			}
		}

		for (auto entry : dictoinary)
		{
			cout << entry.first << " " << entry.second << endl;
		}

	} 
}


struct DATA
{
	int key;
	string info;
};

void print(DATA ss) {
	cout << ss.key << "," << ss.info << endl;
}

int taskTwo() {
	AvlTree<DATA, int> tree;
	if (tree.AVL_Empty())
		cout << "Empty tree." << endl;

	DATA newItem;
	newItem.info = "Dongmo";
	newItem.key = 10;
	tree.AVL_Insert(newItem);

	newItem.info = "John";
	newItem.key = 20;
	tree.AVL_Insert(newItem);

	newItem.info = "Jane";
	newItem.key = 30;
	tree.AVL_Insert(newItem);

	tree.AVL_Print();

	cout << "More to go ..." << endl;

	newItem.info = "Daniel";
	newItem.key = 40;
	tree.AVL_Insert(newItem);
	newItem.info = "Michelle";
	newItem.key = 50;
	tree.AVL_Insert(newItem);

	tree.AVL_Print();

	cout << endl;

	tree.AVL_Traverse(print);

	return 0;
}

int taskThree()
{

	AvlTree<DATA, int> tree;
	ifstream readf("pledge.txt");

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
				//add word to tree
				cout << word << endl;
				newItem.info = word;
				newItem.key = word.length();
				tree.AVL_Insert(newItem);
				//dictoinary[word] += 1;
				word = "";
			}
		}


	}


	tree.AVL_Print();
	cout << endl;

	tree.AVL_Traverse(print);
	return 0;
}



