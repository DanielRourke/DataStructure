#pragma once
#include "pch.h"
using namespace std;

class CustomString
{
private:
	string val;
public:
	CustomString();
	CustomString(string);
	~CustomString();
	bool operator<(CustomString&);
	bool operator>(CustomString&);
	bool operator==(CustomString&);
	void operator=(string&);
	friend ostream & operator <<(ostream& os, const CustomString cs);
};


CustomString::CustomString()
{
	val = "";
}

CustomString::CustomString(string s)
{
	this->val = s;
}

CustomString::~CustomString()
{
}


//compares lenght and each character in string case sensative
//when using tree will clean words to not contain UpperCase
//attempting to compare strings in lexicographic order

inline bool CustomString::operator<(CustomString& other)
{
	for (int i = 0; i < this->val.length() || i < other.val.length(); i++)
	{
		if (other.val[i] == '\0' || this->val[i] > other.val[i])
		{
			return false;
		}
		else if (this->val[i] == '\0')
		{
			return true;
		}

	}

	return (this->val.length() != other.val.length());

}

inline bool CustomString::operator>(CustomString& other)
{

	for (int i = 0; i < this->val.length() || i < other.val.length(); i++)
	{
		if (this->val[i] == '\0' || this->val[i] < other.val[i])
		{
			return false;
		}
		else if (other.val[i] == '\0')
		{
			return true;
		}

	}

	return (this->val.length() != other.val.length());


}

inline bool CustomString::operator==(CustomString& other)
{
	if (this->val.length() == other.val.length())
	{
		for (int i = 0; i < this->val.length(); i++)
		{
			if (this->val[i] != other.val[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

inline void CustomString::operator=(string& s)
{
	this->val = s;
}