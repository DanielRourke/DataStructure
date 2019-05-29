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
	CustomString(const CustomString &);
	~CustomString();
	bool operator<(const CustomString&) const;
	bool operator>(const CustomString&) const;
	bool operator==(const CustomString&) const;
	void operator=(string&);
	friend ostream & operator <<(ostream& os, const CustomString cs);
};

ostream& operator<<(ostream& os, const CustomString cs)
{
	os << cs.val;
	return os;
}


CustomString::CustomString()
{
	val = "";
}

CustomString::CustomString(string s)
{
	this->val = s;
}

CustomString::CustomString(const CustomString& s)
{
	this->val = s.val;
}

CustomString::~CustomString()
{
}

//compares lenght and each character in string case sensative
//when using tree will clean words to not contain UpperCase
//attempting to compare strings in lexicographic order

inline bool CustomString::operator<(const CustomString& other) const
{
	for (int i = 0; i < this->val.length() || i < other.val.length(); i++)
	{
		if (this->val[i] == '\0' || this->val[i] < other.val[i])
		{
			return true;
		}
		else if (other.val[i] == '\0' || this->val[i] > other.val[i])
		{
			return false;
		}

	}

	//return (this->val.length() != other.val.length());
	return false;

}

inline bool CustomString::operator>(const CustomString& other) const
{

	for (int i = 0; i < this->val.length() || i < other.val.length(); i++)
	{
		if (other.val[i] == '\0' || this->val[i] > other.val[i])
		{
			return true;
		}
		else if (this->val[i] == '\0' || this->val[i] < other.val[i])
		{
			return false;
		}

	}

	return false;

}

inline bool CustomString::operator==(const CustomString& other) const
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