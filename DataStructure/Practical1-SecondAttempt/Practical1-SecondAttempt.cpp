// Practical1-SecondAttempt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

template<typename Type>
static int methodOne(vector<Type> *original, vector<Type> *randomized)
{
	int randCallCount = 0;
	vector<Type> temp = *original;
	while (temp.size() > 0)
	{
		int index = rand() % (int)temp.size();
		randomized->push_back(temp[index]);
		temp.erase(temp.begin() + index);
		randCallCount++;
	}
	return randCallCount;
}

template<typename Type>
static int methodTwo(vector<Type> *original, vector<Type> *randomized)
{
	int randCallCount = 0;
	while (randomized->size() < original->size())
	{
		int index = rand() % (int)original->size();
		if (!containedInRandomized(randomized,original[index]))
		{
			randomized->push_back(original[index]);
		}

		randCallCount++;
	}

	return randCallCount;
}

template<typename Type>
bool containedInRandomized(vector<Type> *randomized,Type item)
{
	bool ret = false;
	for (Type listedItem : randomized)
	{
		if (listedItem == item)
		{
			ret = true;
			break;
		}
	}

	return ret;
}


template<typename Type>
void testMethod(int(method*)(*vector<Type>, *vector<Type>), int count, vector<Type> *orignial, vector<Type> *randomized)
{

	int totalUnchanged = 0;
	randomized.clear();

	for (int i = 0; i < count; i++)
	{
		int unchanged = 0;
		(method)(orignial, randomized);



		for (unsigned int j = 0; j < original.size(); j++)
		{
			cout << randomized[j] << " ";
			if (original[j] == randomized[j])
			{
				unchanged++;
			}
		}

		totalUnchanged += unchanged;

		cout << "unchanged: " << unchanged
			<< " random calls to rand() : " << randCallCount
			<< endl;

	}


	cout << "Total Unchanged : " << totalUnchanged << endl;
}

int main()
{
	vector<int> original = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> randomized;
	//methodOne(&original, &randomized);
	//methodTwo(&original, &randomized);

	testMethod(&methodOne(original, randomized), 20);
	testMethod(&methodTwo(original, randomized), 20);


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
