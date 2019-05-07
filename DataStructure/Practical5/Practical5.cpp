// Practical5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


//void printStars(int n)
//{
//	if (n == 0)
//	{
//		cout << endl;
//	}
//	else
//	{
//		cout << "*";
//		if (n > 0)
//		{
//			printStars(n - 1);
//		}
//		else if (n < 0)
//		{
//			printStars(n + 1);
//		}
//	}
//}
//
//void printLines(int n)
//{
//	if (n > 0)
//	{
//		printStars(n);
//		printLines(n - 1);
//		printStars(-n);
//	}
//	else if (n < 0)
//	{
//
//		printStars(n);
//		printLines(n + 1);
//		printStars(n);
//	}
//}

void printStars(int n)
{
	if (n == 0)
	{
		cout << endl;
	}
	else
	{
		cout << "*";
		if (n > 0)
		{
			printStars(n - 1);
		}
	}
}

void printLines(int n)
{
	if (n > 0)
	{
		printStars(n);
		printLines(n - 1);
		printStars(n);
	}
}




double power(int x, int y)
{
	if (y >= 0)
	{
		if (y == 0)
		{
			return 1;
		}
		else if (y == 1)
		{
			return x;
		}
		else
		{
			return x * power(x, y - 1);
		}
	}
	else
	{
		return 1.0 / power(x, -y);
	}

	return -1;
}

int main()
{
	int input = 0;
	int input2 = 0;
	cin >> input;
	//cin >> input2;
	//fun(input);
//	cout << power(input, input2)<< endl;
	printLines(input);
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
