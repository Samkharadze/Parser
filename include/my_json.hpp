#pragma once

#include <string>
#include <any>
#include <vector>
#include <map>

class Json 
{
public:
	Json(const std::string& s);
	bool is_array() const;
	bool is_object() const;
	int GetArrSize() const;
	std::any& operator[](const std::string& key);
	std::any& operator[](int index);
	static Json parse(const std::string& s);
	static Json parseFile(const std::string& path_to_file);
	std::vector<std::any> GetArray(const std::string & s, int start) const;
	std::map<std::string, std::any> GetMap(const std::string & s, int start) const;
	std::vector<std::any> _arr;
	std::map<std::string, std::any> _obj;
	bool _isArray;
};
