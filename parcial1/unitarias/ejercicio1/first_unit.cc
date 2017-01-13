#include "first.h"
#include "gtest/gtest.h"

// To compile g++ -isystem ../../googletest/include/ -pthread first.cc first_unit.cc gtest_main.a -o prueba

TEST(Factorial, positivos) {
	ASSERT_EQ(1, factorial(1));
	ASSERT_EQ(120, factorial(5));
}

TEST(Factorial, cero) {
	ASSERT_EQ(1, factorial(0));
}

TEST(Factorial, negativos) {
	ASSERT_EQ(0, factorial(-2));
	ASSERT_EQ(0, factorial(-1));
}