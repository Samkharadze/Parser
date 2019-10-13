#pragma once

#include <string>


//ok
bool isSpace(char ch);
int findEnd(const std::string& s, int startInd, char openSym, char closeSym);
int missSpaces(const std::string&s, int current);
std::string getString(const std::string &s, int start);
bool isNum(char ch);
std::pair<double, int> getNumWithLen(const std::string &s, int start); 
