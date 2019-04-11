// Practical5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void fun(int i)
{
	if (i > 0)
	{
		cout << "*";
		fun(i - 1);
	}
	cout << endl;
	fun(i - 2);
}




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
		else if (n < 0)
		{
			printStars(n + 1);
		}
	}
}

void printLines(int n)
{
	if (n > 0)
	{
		printStars(n);
		printLines(n - 1);
		printStars(-n);
	}
	else if (n < 0)
	{
		printStars(n);
		printLines(n + 1);
		printStars(-n);
	}
}


long power(int x, int y)
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
		return 1 / power(x, -y);
	}

	return -1;
}

int main()
{
	int input = 0;
	cin >> input;
	//fun(input);
	//cout << power(2, input)<< endl;
	printLines(input);
}


//{
//	print stars 4 times
//	print stars 3 times 
//	print stars 2 times
//	print stars 1 times
//
//	print stars 1 times
//	print stars 2 times
//	print stars 3 times
//	print stars 4 times
//
//
//	while x != 0
//		print stars (x y)
//			
//		if (x !=0)
//			print *
//		if x > 0
//			x - 1
//			print stars
//
//
//
//
//		if x < 0
//			x + 1
//			print star
//
//
//		printStar(4)
//
//
//			fun1(4)
//
//			fun(4)
//			fun1 4 -1
//			fun 4

	




			



				







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
