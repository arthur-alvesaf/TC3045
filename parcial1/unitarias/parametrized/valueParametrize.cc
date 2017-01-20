#include "gtest/gtest.h"
#include "functions.h"

// Compile with g++ -isystem ../../../googletest/include/ -std=c++11 -pthread valueParametrize.cc ../gtest_main.a -o prueba

// Fixture of testing with parameters
class FixValParam : public testing::TestWithParam<int> {
public:
	void SetUp() {}
	void TearDown() {}
};

// Test P (parametrize) con nombre Prueba1 y que usa el Fixture FixValParam
TEST_P(FixValParam, Pares) {
	if (GetParam() % 2 == 0)
		EXPECT_EQ(true, isEven(GetParam()));
	else
		EXPECT_EQ(false, isEven(GetParam()));
}

TEST_P(FixValParam, Impares) {
	if (GetParam() % 2 == 0)
		EXPECT_EQ(false, isOdd(GetParam()));
	else
		EXPECT_EQ(true, isOdd(GetParam()));
}

INSTANTIATE_TEST_CASE_P(Values, FixValParam, testing::Values(0, 1, 2, 3, 4, 5, 6, 7, 8));

int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
INSTANTIATE_TEST_CASE_P(UsingValuesIn, FixValParam, testing::ValuesIn(array));