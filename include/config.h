#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <map>
using namespace std;

class Config {
private:
	map<string, bool> boolValues_;
	map<string, int> intValues_;
	map<string, float> doubleValues_;
	map<string, string> strValues_;
public:
	Config(){};
	~Config(){};

	bool LoadFromJson(const string& jsonFilePath);

	bool GetValue(const string& name, bool& value);
	bool GetValue(const string& name, int& value);
	bool GetValue(const string& name, double& value);
	bool GetValue(const string& name, string& value);
};
#endif//_CONFIG_H_

