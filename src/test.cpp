#include "catch.hpp"
#include "util.h"

TEST_CASE("util test", "util") {
	SECTION("split str") {
		REQUIRE(util::splitStr("", ":").size() == 0);
		REQUIRE(util::splitStr("aaa:bbb", ":")[1] == "bbb");
		REQUIRE(util::splitStr("aaa:bbb:", ":")[2] == "");
		REQUIRE(util::splitStr(":aaa:bbb:", ":")[3] == "");
	}
}
