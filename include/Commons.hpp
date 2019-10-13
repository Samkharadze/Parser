#pragma once

#include <string>


//ok
bool isspace(char ch);
int findend(const std::string& s, int startInd, char openSym, char closeSym);
int missspaces(const std::string&s, int current);
std::string getstring(const std::string &s, int start);
bool isnum(char ch);
std::pair<double, int> getnumwithlen(const std::string &s, int start); 
