#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#include "Open3D/Open3D.h"
using namespace open3d;

#include "util.h"
#include "cmdline.h"

//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#ifndef CATCH_CONFIG_MAIN
int main(int argc, char *argv[]) {
	cmdline::parser parser;

	parser.add<string>("operation", 'o', "operation name", false, "make", cmdline::oneof<string>("make", "intergration"));
	parser.add<string>("config", 'c', "config file", false, "./config.json");

	parser.parse_check(argc, argv);
	string op = parser.get<string>("operation");
	string configFilePath = parser.get<string>("config");

	map<string, string> config;
	config["aaa"] = "aaa";
	config["bbb"] = "bbb";
	config["ccc"] = "ccc";
	//if(!util::loadConfig(configFilePath/*, gConfig*/)) {
	//	utility::PrintError("Read config file error");
	//	return 1;
	//}
	for(auto k : config) {
		cout<<k.first<<":"<<k.second<<endl;
	}
}
#endif//CATCH_CONFIG_MAIN
