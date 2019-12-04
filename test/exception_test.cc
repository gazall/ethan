#define CATCH_CONFIG_MAIN

#include <base/Exception.h>
#include <test/Catch2/catch.hpp>
#include <sstream>
#include <string>

TEST_CASE("test Exception", "Exception") {
    try {
        std::stringstream ss;
        ss << "hello";
        throw Exception(ss.str());
    } catch (const Exception &e) {
        std::string msg(e.what());
        REQUIRE(msg == "hello");
    }
}