// Practical2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
	int start = 0;
	int end = size - 1;
	int middle = start + end /2;
	while (start < end)
	{
		if (arr[middle] == target)
		{
			return middle;
			break;
		}
		else if (arr[middle] < target)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	return -1;
}

int linearSearch(int arr[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}

//void sum(int mata[][], int matb[][], int *matc[][], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			matc[i][j] = mata[i][j]
//		}
//	}
//}

void printResult(int target, int result)
{
	if (result != -1)
	{
		cout << target << " is located at index " << result << endl;
	}
	else
	{
		cout << "Target not found" << endl;
	}
}

int main()
{
	int orderedNumbers[] = { 1, 3, 8, 9, 12, 14, 22, 25, 33, 34, 38, 59, 61, 66, 68, 73, 75, 99, 101, 203, 454 };
	int target;


	cout << "Enter a number to search for : ";
	cin >> target;
	printResult(target, linearSearch(orderedNumbers, 21, target));


	cout << "Enter a number to search for : ";
	cin >> target;
	printResult(target, binarySearch(orderedNumbers, 21, target));
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
