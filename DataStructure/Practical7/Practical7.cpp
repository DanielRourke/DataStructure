// Practical7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//Data:  89 27 65 34 12 90 76 3 89 22 55 36 -999
#include "binarySearchTree.h"

using namespace std;

int main()
{
	bSearchTreeType<int>  treeRoot, otherTreeRoot;

	int num;

	cout << "Enter numbers ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		treeRoot.insert(num);
		cin >> num;
	}

	cout << endl << "Tree nodes in inorder: ";
	treeRoot.inorderTraversal();

	cout << endl << "Tree nodes in preorder: ";
	treeRoot.preorderTraversal();

	cout << endl << "Tree nodes in postorder: ";
	treeRoot.postorderTraversal();
	cout << endl;

	cout << "Tree Height: " << treeRoot.treeHeight()
		<< endl;
	cout << "Number of Nodes: "
		<< treeRoot.treeNodeCount() << endl;
	cout << endl;
	cout << "Number of Leaves: "
		<< treeRoot.treeLeavesCount() << endl;
	cout << endl;

	cout << "Enter item to be search: ";
	cin >> num;
	cout << endl;

	if (treeRoot.search(num))
		cout << "Item found in the tree." << endl;
	else
		cout << "Search item not in the tree." << endl;

	cout << "Enter item to be deleted: ";
	cin >> num;
	cout << endl;

	treeRoot.deleteNode(num);

	cout << endl << "Tree nodes in inorder: ";
	treeRoot.inorderTraversal();
	cout << endl << "Tree nodes in preorder: ";
	treeRoot.preorderTraversal();
	cout << endl << "Tree nodes in postorder: ";
	treeRoot.postorderTraversal();
	cout << endl;

	otherTreeRoot.destroyTree();
	cout << endl;

	return 0;
}

