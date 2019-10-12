#include "stdafx.h"
#include "Task3.hpp"

using namespace std;

class TextStorage
{
public:
	stringstream storage;
	public void put(string input)
	{
		storage << input;
	}
	public stringstream get()
	{
		return storage;
	}
}
Json Transform(const std::string & s)
{
	Json data(s);

	if (!data.is_array() || data.GetArrSize() != 3)
		throw exception("Wrong string");


	TextStorage ss;

	int size = any_cast<Json>(data[0]).GetArrSize();
	if (size != any_cast<Json>(data[1]).GetArrSize() || size != any_cast<Json>(data[2]).GetArrSize())
		throw exception("Wrong string");

	ss.put("[");
	for (int i = 0; i < size; ++i)
	{

		ss.put("{");
		ss.put("\"ticker\":\"");
		ss.put(any_cast<string>(any_cast<Json>(data[0])[i]));
		ss.put("\",");
		ss.put("\"id\":");
		ss.put(any_cast<double>(any_cast<Json>(data[1])[i]))
			ss.put(",");
		ss.put("\"description\":\"");
		ss.put(any_cast<string>(any_cast<Json>(data[2])[i]));
		ss.put("\"");
		ss.put("}");

		if (i != size - 1)
			ss.put(",");
	}

	ss.put("]");

	string str;
	getline(ss.get(), str);

	return Json(str);
}