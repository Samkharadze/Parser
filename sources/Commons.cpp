#include <sstream> 
#include <iostream>
#include "Commons.hpp"
#include <cctype>
using namespace std;
bool isSpace(char ch)
{
	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

int findEnd(const string& s, int startInd, char openSym, char closeSym)
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

int missSpaces(const string&s, int current)
{
	for (auto i = s.begin() + current; i < s.end(); i++)
		if (!isSpace(s[(i - s.begin())]))
			return (i - s.begin());

}

string getString(const string &s, int start)
{
	int endStr = 0;
	for (auto i = s.begin() + start + 1; i < s.end(); i++)
		if (s[(i - s.begin())] == '\"')
			endStr = (i - s.begin());

	if (endStr == s.length() || endStr == 0)
		throw exception("String is not valid!");

	return s.substr(start + 1, endStr - start - 1);
}

bool isDigit(char ch)
{
	return isdigit(ch);
}

void check(int cur, string& s)
{
	if (cur == s.length())
		throw exception("String is not valid!");
}
pair<double, int> getNumWithLen(const string &s, int start)
{
	double result;

	int cur = start;
	bool isDouble = false;

	for (;;)
	{
		if (!((cur < s.length() && isDigit(s[cur]))))
			break;
			++cur;
	}
	void check(int cur, const string& s);
	{
		if (cur == s.length())
			throw exception("String is not valid!");
	}

	if (s[cur] == '.')
	{
		++cur;
		for (;;)
		{
			if (!((cur < s.length() && isDigit(s[cur]))))
				break;
				++cur;
		}

	}
	void check(int cur, const string& s);
	{
		if (cur == s.length())
			throw exception("String is not valid!");
	}


	stringstream ss;
	string str = s.substr(start, cur - start);
	ss << str;
	ss >> result;

	return pair(result, cur - start);
}