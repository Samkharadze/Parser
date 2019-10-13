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
	int getarrsize() const;
	std::any& operator[](const std::string& key);
	std::any& operator[](int index);
	static Json parse(const std::string& s);
	static Json parsefile(const std::string& path_to_file);
	std::vector<std::any> getarray(const std::string & s, int start) const;
	std::map<std::string, std::any> getmap(const std::string & s, int start) const;
	std::vector<std::any> _arr;
	std::map<std::string, std::any> _obj;
	bool _isarray;
};
