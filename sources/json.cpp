#include "../include/Commons.hpp"
#include "../include/my_json.hpp"
#include <stdexcept>

using namespace std;


Json::Json(const string & s)
{
	int i = 0;
	i = missspaces(s, i);

	if (s[i] == '{')
	{
		_isarray = false;
		_obj = getmap(s, i + 1);
	}
	else if (s[i] == '[')
	{
		_isarray = true;
		_arr = getarray(s, i + 1);
	}
	else
		throw runtime_error("String is not valid!");
}

bool Json::is_array() const
{
	return _isarray;
}

bool Json::is_object() const
{
	return !_isarray;
}

int Json::getarrsize() const
{
	if (is_array())
		return _arr.size();
	else
		throw;
}

pair<any, int> getvalueandlen(const string &s, int start)
{
	any result;
	int i = start;
	int endObj = 0;

	if (s[i] == '{')
	{
		endObj = findend(s, i, '{', '}');

		string str = s.substr(i, endObj - i);
		result = Json(str);
		i = endObj;
	}
	else if (s[i] == '[')
	{
		endObj = findend(s, i, '[', ']');

		string str = s.substr(i, endObj - i);
		result = Json(str);
		i = endObj;
	}
	else if (s[i] == '\"')
	{
		string str = getstring(s, i);
		i += str.length() + 2;
		result = str;
	}
	else if (isnum(s[i]))
	{
		pair<any, int> p = getnumwithlen(s, i);
		i += p.second;
		result = p.first;
	}
	else if (s.substr(i, 5) == "false")
	{
		i += 5;
		result = false;
	}
	else if (s.substr(i, 4) == "true")
	{
		i += 4;
		result = true;
	}
	else if (s.substr(i, 4) == "null")
	{
		i += 4;
		result = nullptr;
	}
	else
		throw runtime_error("String is not Valid!");

	return pair(result, i - start);
}

any & Json::operator[](const std::string & key)
{
	if (is_object())
		return _obj[key];

	throw runtime_error("It is not a object!");
}

any & Json::operator[](int index)
{
	if (is_array())
		return _arr[index];

	throw runtime_error("This is not array!");
}

Json Json::parse(const std::string & s)
{
	return Json(s);
}

vector<any> Json::getarray(const string &s, int start) const
{
	vector<any> result;

	for (auto j = s.begin() + start; j < s.end(); j++)
	{
		int i = j - s.begin() - start;
		i = missspaces(s, i);
		pair<any, int> p = getvalueandlen(s, i);

		i += p.second;
		result.push_back(p.first);

		i = missspaces(s, i);
		if (s[i] == ']')
			break;

		if (s[i++] == ',')
			continue;

		throw runtime_error("String is not Valid");
	}

	return result;
}

std::map<std::string, std::any> Json::getmap(const std::string & s, int start) const
{
	std::map<std::string, std::any> result;


	for (auto j = s.begin() + start; j < s.end(); j++)
	{
		int i = j - s.begin() - start;
		i = missspaces(s, i);
		if (s[i] != '\"')
			throw runtime_error("String is not valid!");

		string key = getstring(s, i);
		i += key.length() + 2;
		i = missspaces(s, i);
		if (s[i++] != ':')
			throw runtime_error("String is not valid!");

		i = missspaces(s, i);
		pair<any, int> p = getvalueandlen(s, i);

		result[key] = p.first;

		i += p.second;

		i = missspaces(s, i);
		if (s[i] == '}')
			break;

		if (s[i++] == ',')
			continue;

		throw runtime_error("String is not Valid");
	}

	return result;
}