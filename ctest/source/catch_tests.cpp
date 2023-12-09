#include <catch2/catch_test_macros.hpp>

#include "lib.h"

TEST_CASE( "Add function tests, positive values", "[add]" ) {
    REQUIRE( add(1, 2) == 3 );
    REQUIRE( add(3, 3) == 6 );
}

TEST_CASE( "Add function tests, negative values", "[add]" ) {
    REQUIRE( add(1, -2) == -1 );
    REQUIRE( add(3, -3) == 0 );
}

TEST_CASE( "Add function tests, expected fails", "[add]" ) {
    REQUIRE_FALSE( add(1, 1) == -1 );
    REQUIRE_FALSE( add(0, 0) > 0 );
}
