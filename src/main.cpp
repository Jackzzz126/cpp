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
#include "config.h"

//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#ifndef CATCH_CONFIG_MAIN
int main(int argc, char *argv[]) {
	cmdline::parser parser;

	parser.add<string>("operation", 'o', "operation name", false, "make", cmdline::oneof<string>("make", "intergration"));
	parser.add<string>("config", 'c', "config file", false, "./config.json");
	parser.add<string>("intrinsic", 'i', "intrinsic matrix", false, "./camera.json");

	parser.parse_check(argc, argv);
	string op = parser.get<string>("operation");
	string configFilePath = parser.get<string>("config");
	string intrinsicFilePath = parser.get<string>("config");

	Config config;
	if(!config.LoadFromJson(intrinsicFilePath)) {
		return 1;
	}

	return 0;
}
#endif//CATCH_CONFIG_MAIN
