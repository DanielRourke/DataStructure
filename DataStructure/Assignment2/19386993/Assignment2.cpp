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
	vector<string> files;
	void update(DATA d)
	{
		if (info != NULL)
			info += 1;
		else
			info = 1;

		if (!d.files.empty() && d.files.back() != files.back())
			files.push_back(d.files.back());
			
	}

	friend ostream & operator <<(ostream& os, const DATA d)
	{
		os << d.key << "," << d.info;
		for (auto filename : d.files)
		{
			os << "," << filename ;
		}
		return os;
	}


	bool operator<(const DATA d) const{
		return (info < d.info); //Check if the direction is correct
	}

};


bool addFileToTree(string filename, AvlTree<DATA, CustomString> * tree);
AvlTree<DATA, CustomString> * loadFile(string filename, AvlTree<DATA, CustomString> * tree);
bool clearFile(string filename);

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



void print(DATA d) 
{
	cout << d.key << "," << d.info << (d.files.size() + 1)<< endl;
}


void findWords(AvlTree<DATA, CustomString> *tree)
{
	string min = "";
	cout << "Please enter a word to search for" << endl;
	cin >> min;
	string max = "";

	priority_queue<DATA> results;

	//TODO : rollover z
	results = (*tree).AVL_RetrieveInRange(min, max += min[0] + 1);

	for (int i = 0; i < 5 && !results.empty(); i++)
	{
		cout << "Key: " << results.top().key << "  Fequency: " << results.top().info << endl;
		results.pop();
	}
}

void pruneTree(AvlTree<DATA, CustomString> *tree, float prune)
{
	cout <<"Current Tree Size" << (*tree).AVL_Count() << endl;
	(*tree).AVL_PruneTree(prune);
	cout << "Prunned Tree Size" << (*tree).AVL_Count() << endl;
}

bool findWord(AvlTree<DATA, CustomString> *tree)
{
	string input;
	DATA d;
	cout << "Please enter a word to search for" << endl;
	cin >> input;
	d.key = input;
	bool ret = (*tree).AVL_Retrieve(d.key, d);
	cout << d << endl;

	return ret;
}
bool deleteWord(AvlTree<DATA, CustomString> *tree)
{
	string input;
	DATA d;
	cout << "Please enter a word to Delete" << endl;
	cin >> input;
	d.key = input;
return (*tree).AVL_Delete(d.key);

}

void menu(AvlTree<DATA, CustomString> *tree)
{
	string input = "";
	cout << "		Menu" << endl;
	do
	{
		cout << "1. Prune Tree" << endl;
		cout << "2. Pedict Text search" << endl;
		cout << "3. Search" << endl;
		cout << "4. Delete" << endl;
		cout << "5. Save Tree" << endl;
		cout << "6. Print Tree" << endl;
		cout << "7. Print words" << endl;
		cout << "8. Exit" << endl;
		cin >> input;
	} while (input < "1" && input > "9");

	string word;
	if (input == "1")
	{
		cout << "Enter frequency" << endl;
		cin >> input;
		pruneTree(tree, 3);
	}
	else if (input == "2")
	{
		findWords(tree);
	}
	else if (input == "3")
	{
		findWord(tree);
	}
	else if (input == "4")
	{
		deleteWord(tree);
	}
	else if (input == "5")
	{
		clearFile("Textfiles/tree.txt");
		(*tree).AVL_Save("Textfiles/tree.txt");
	}
	else if (input == "6")
	{
		(*tree).AVL_Print();
	}
	else if (input == "7")
	{
		(*tree).AVL_Traverse(print);
	}
	else if (input == "8")
	{
		return;
	}
	menu(tree);
}

int main()
{
	
	AvlTree<DATA, CustomString> tree1;
	AvlTree<DATA, CustomString> tree2;
	AvlTree<DATA, CustomString> *tree = &tree1;
	
	string input;
	cout << "		Menu" << endl;
	do
	{
		cout << "1. Make Tree from files" << endl;
		cout << "2. Make tree from saved tree" << endl;
		cout << "3. Exit" << endl;
		cin >> input;
	} while (input != "1" && input != "2");

	if (input == "1")
	{
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_1.txt" << endl;
		addFileToTree("Textfiles/AI_articles_1.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_2.txt" << endl;
		addFileToTree("Textfiles/AI_articles_2.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_3.txt" << endl;
		addFileToTree("Textfiles/AI_articles_3.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_4.txt" << endl;
		addFileToTree("Textfiles/AI_articles_4.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_5.txt" << endl;
		addFileToTree("Textfiles/AI_articles_5.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_6.txt" << endl;
		addFileToTree("Textfiles/AI_articles_6.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_7.txt" << endl;
		addFileToTree("Textfiles/AI_articles_7.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_8.txt" << endl;
		addFileToTree("Textfiles/AI_articles_8.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_9.txt" << endl;
		addFileToTree("Textfiles/AI_articles_9.txt", tree);
		cout << "Trying to Open " << "\\Textfiles\\AI_articles_10.txt" << endl;
		addFileToTree("Textfiles/AI_articles_10.txt", tree);
	}
	else if (input == "2")
		tree = loadFile("Textfiles/tree.txt", &tree2);
	
	menu(tree);

	return 0;
}




bool addFileToTree(string filename, AvlTree<DATA, CustomString>* tree)
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
		string twoWord = "";
		string threeWord = "";
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
				newItem.files.push_back(filename);
				(*tree).AVL_Update(word, newItem);

				if (threeWord != "")
				{
					newItem.key = threeWord + " " + twoWord + " " + word;
					(*tree).AVL_Update(threeWord + " " + twoWord + " " + word, newItem);
				}

				if (twoWord != "")
				{
					newItem.key = twoWord + " "+ word;
					(*tree).AVL_Update(twoWord + " " + word, newItem);
					threeWord = twoWord;
				}
				twoWord = word;
				word = "";

				newItem.files.clear();
			}
		}

		cout << "File added to tree." << endl;

	}

	readf.close();
	return true;
}

bool clearFile(string filename)
{
	ofstream file;

	file.open(filename);

	if (file.is_open())
	{
		file << "";
	}
	else
	{
		return false;
	}
	file.close();

	return true;

}

AvlTree<DATA, CustomString> *loadFile(string filename, AvlTree<DATA, CustomString> * tree)
{
	ifstream readf;
	readf.open(filename);

	DATA newItem;
	char c;
	string key = "";
	string info = "";
	string fileString;
	int section = 0;
	if (readf.is_open())
	{
		cout << "Opened file: " << endl;
		while ((c = readf.get()) != EOF)
		{
			if (c == '[')
			{
				section = 0;
			}
			else if (c == ',')
			{
				switch (section)
				{
				case 0:
					newItem.key = key;
					key = "";
					section = 1;
					break;
				case 1:
					newItem.info = stof(info);
					info = "";
					section = 2;
					break;
				case 2:
					newItem.files.push_back(fileString);
					fileString = "";
					break;
				default:
					break;
				}
			}
			else if (c == ']')
			{
				if (key != "NULL")
				{
					newItem.files.push_back(fileString);
					(*tree).AVL_Insert(newItem);
				}
				key = "";
				info = "";
				fileString = "";
				newItem.files.clear();
				section = -1;
			}
			else
			{
				switch (section)
				{
				case 0:
					key += c;
					break;
				case 1:
					info += c;
					break;
				case 2:
					fileString += c;
					break;
				case 3:
					break;
				}
			}
		}
	}
	else
	{
		cout << "Error opeing file";
	}
	cout << " Tree Loaded From " << filename << endl;
	readf.close();
	

    return tree;
}


