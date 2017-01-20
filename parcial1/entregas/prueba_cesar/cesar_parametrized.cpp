#include "gtest/gtest.h"
#include "cesar.h"

// Compile with g++ -isystem ../../../googletest/include/ -std=c++11 -pthread ../../unitarias/cifrado/cesar.h cesar_parametrized.cpp ../../unitarias/gtest_main.a -o prueba

// Fixture of testing with parameters
class FixValParam : public testing::TestWithParam<string> {
public:
	Cesar c;
	void SetUp() {}
	void TearDown() {}
};

// Test P (parametrize) con nombre Prueba1 y que usa el Fixture FixValParam
TEST_P(FixValParam, Cesar) {
	EXPECT_EQ(15, c.decrypt(GetParam()));
}

INSTANTIATE_TEST_CASE_P(Values, FixValParam, testing::Values("rlcopy"));