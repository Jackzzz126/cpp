#include "catch.hpp"

#ifdef CATCH_CONFIG_MAIN
#include "util.h"
TEST_CASE("util test", "util") {
	SECTION("split str") {
		REQUIRE(util::splitStr("", ":").size() == 0);

		REQUIRE(util::splitStr("aaa:bbb", ":").size() == 2);
		REQUIRE(util::splitStr("aaa:bbb", ":")[1] == "bbb");

		REQUIRE(util::splitStr("aaa:bbb:", ":").size() == 3);
		REQUIRE(util::splitStr("aaa:bbb:", ":")[2] == "");

		REQUIRE(util::splitStr(":aaa:bbb:", ":").size() == 4);
		REQUIRE(util::splitStr(":aaa:bbb:", ":")[3] == "");
	}
}
#endif// CATCH_CONFIG_MAIN
