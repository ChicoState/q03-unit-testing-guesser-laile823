/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

//3 consecutive test
TEST(GuesserTest, CorrectMatchTest) {
    Guesser guesser("password");
		ASSERT_FALSE(guesser.match("password1"));
    ASSERT_FALSE(guesser.match("password2"));
		ASSERT_FALSE(guesser.match("password3"));
		ASSERT_TRUE(guesser.match("password"));
		ASSERT_EQ(guesser.remaining(), 3);
}

TEST(GuesserTest, WrongMatchTest) {
    Guesser guesser("password");
    ASSERT_FALSE(guesser.match("passwo"));
		ASSERT_FALSE(guesser.match("passwo"));
		ASSERT_FALSE(guesser.match("passwo"));
		ASSERT_FALSE(guesser.match("passwo"));
		ASSERT_FALSE(guesser.match("password"));
}

TEST(GuesserTest, DistanceTest) {
    Guesser guesser("password");
    ASSERT_FALSE(guesser.match("drSsword"));
    ASSERT_TRUE(guesser.is_locked());
		ASSERT_FALSE(guesser.match("password"));
}

TEST(GuesserTest, RemainingGuessesTest) {
    Guesser guesser("password");
    guesser.match("password1");
    guesser.match("password2");
    ASSERT_EQ(guesser.remaining(), 1);
}


TEST(GuesserTest, SecretTooLongTest) {
    Guesser guesser("superlongpasswordthatiswaytoolongforitsowngoodihopethisisgreaterthan32");
    ASSERT_EQ(guesser.m_secret_length(), 32);
}
