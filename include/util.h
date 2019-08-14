#ifndef _UTIL_H_
#define _UTIL_H_
#include <string>
#include <map>
#include <iostream>
using namespace std;

namespace util{//ns util

void show(const string& typeName, const string& fileName, const string& trajectoryFileName = "");
bool loadConfig(const string& configFilePath/*, map<int, int>& config*/);

};//eof ns util
#endif//_UTIL_H_
