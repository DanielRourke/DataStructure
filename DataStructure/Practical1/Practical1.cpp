// Practical1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

template <typename Type>
void funcExp(Type list[], int size)
{
	Type x = list[0];
	Type y = list[size - 1];
	for (int j = 1; j < size; j++)//goes through array
	{
		if (x < list[j])//Keeps the lowest number
			x = list[j];

		if (y > list[size - 1 - j])//keeps the highest number
			y = list[size - 1 - j];
	}
	cout << x << endl;//prints lowest number to screen
	cout << y << endl;//prints highest number to screen
}

template <typename Type>
class RandomList
{
public:
	RandomList()
	{
	}
	RandomList(Type list[])
	{
		for (unsigned int i = 0 ; i < list.size; i++)
		{
			original.push_back(list[i]);
		}

		randCallCount = 0;
	}

	RandomList(vector<Type> list)
	{
		randCallCount = 0;
		original = list;
	}

	void methodOne()
	{
		randCallCount = 0;
		vector<Type> temp;
		while (temp.size() > 0)
		{
			int index = rand() % (int)temp.size();
			randomized.push_back(original[index]);
			randCallCount++;
		}

	}

	void testMethod(void(*function_ptr)(), int count)
	{
		
		int totalUnchanged = 0;

		for (int i = 0; i < count; i++)
		{
			randomized.clear();
			(*function_ptr)();
			int unchanged = 0;

			for (unsigned int j = 0; i < original.size(); j++)
			{
				cout << randomized[j] << " ";
				if (original[j] == randomized[j])
				{
					unchanged++;
				}
			}
			cout << "unchanged: " << unchanged 
				 << " random calls to rand() : " <<randCallCount 
				 << endl;

		}


		cout << "Total Unchanged : " << totalUnchanged << endl;
	}
private:
	vector<Type> original;
	vector<Type> randomized;
	int randCallCount;
};







//template <typename Type>
//void compareAndPrint(vector<Type> originalList, vector<Type> randomList, )
//{
//	int randCallCount = 0;
//	vector<Type> retList;
//	while (list.size() > 0)
//	{
//		int index = rand() % (int)list.size();
//		retList.push_back(list[index])
//			randCallCount++;
//	}
//
//	return retList;
//}
//
//template <typename Type>
//vector<Type> methodOne(vector<Type> list)
//{
//	int randCallCount = 0;
//	vector<Type> retList;
//	while (list.size() > 0)
//	{
//		int index = rand() % (int)list.size();
//		retList.push_back(list[index])
//		randCallCount++;
//	}
//
//	return retList;
//}


int main()
{
	//Explain to your tutor the meaning and functionalities of this program.Test it with the
	//	following data :
	int list[10] = { 5,3,2,10,4,19,45,13,61,11 };
	string strList[] = { "One", "Hello", "Four", "Three", "How", "Six" };
	//Run the code in an IDE with necessary declarations and a main function to show the
	//	output of the following statements ?
	
	//a
	funcExp(list, 10);

	//b
	funcExp(strList, 6);

	//int listNormal[10] = {0,1,2,3,4,5,6,7,8,9};
	RandomList<int> numbers({ 0,1,2,3,4,5,6,7,8,9 });
	numbers.testMethod(nmethodOne(), 20);

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
