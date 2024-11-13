/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password)
{
    Password my_password;
    int result = my_password.count_leading_characters("");

    ASSERT_EQ(0, result);
}

TEST(PasswordTest, upper_and_lower)
{
    Password my_password;
    bool result = my_password.has_mixed_case("aA");

    ASSERT_TRUE(result);
}

TEST(PasswordTest, all_lower)
{
    Password my_password;
    bool result = my_password.has_mixed_case("aaaa");

    ASSERT_FALSE(result);
}

TEST(PasswordTest, all_upper)
{
    Password my_password;
    bool result = my_password.has_mixed_case("AAAA");

    ASSERT_FALSE(result);
}

TEST(PasswordTest, empty_mixed_string)
{
    Password my_password;
    bool result = my_password.has_mixed_case("");

    ASSERT_FALSE(result);
}
