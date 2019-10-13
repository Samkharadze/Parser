#include <sstream> 
#include <iostream>
#include "Commons.hpp"
#include <cctype>
using namespace std;
bool isspace(char ch)
{
	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

int findend(const string& s, int startInd, char openSym, char closeSym)
{
	int counter = 0;
	auto i = s.begin() + startInd;
	for (; i < s.end(); i++)
	{
		if (s[(i - s.begin())] == openSym)
			counter++;
		if (s[(i - s.begin())] == closeSym)
			counter--;
		if (counter == 0)
			break;
	}

	return (i - s.begin());
}

int missspaces(const string&s, int current)
{
	for (auto i = s.begin() + current; i < s.end(); i++)
		if (!isspace(s[(i - s.begin())]))
			return (i - s.begin());
	     return s.length();
}

string getstring(const string &s, int start)
{
	string::size_type endstr = 0;
	for (auto i = s.begin() + start + 1; i < s.end(); i++)
		if (s[(i - s.begin())] == '\"')
		 endstr = (i - s.begin());
	 if (endstr == s.length() || endstr == 0)
		 throw std::runtime_error("String is not valid!");

	return s.substr(start + 1, endstr - start - 1);
}

bool isdigit(char ch)
{
	return isdigit(ch);
}

void check(string::size_type cur, string& s)
{
	if (cur == s.length())
		throw std::runtime_error("String is not valid!");
}
pair<double, int> getnumwithlen(const string &s, int start)
{
	double result;
	string::size_type cur = start;


	for (;;)
	{
		if (!((cur < s.length() && isdigit(s[cur]))))
			break;
		else
			++cur;
	}
	void check(string::size_type cur, const string& s);
	{
		if (cur == s.length())
			throw std::runtime_error("String is not valid!");
	}

	if (s[cur] == '.')
	{
		++cur;
		for (;;)
		{
			if (!((cur < s.length() && isdigit(s[cur]))))
				break;
			else
				++cur;
		}

	}
	void check(string::size_type cur, const string& s);
	{
		if (cur == s.length())
			throw std::runtime_error("String is not valid!");
	}


	stringstream ss;
	string str = s.substr(start, cur - start);
	ss << str;
	ss >> result;

	return pair(result, cur - start);
}