#include "CppUTest/TestHarness.h"
#include "Card.h"

/* Declare TestGroup with name CheatSheet */
TEST_GROUP(Card)
{
/* declare a setup method for the test group. Optional. */
	Card *cd;

	void setup ()
	{
/* Set method real_one to stub. Automatically restore in teardown */
	}

/* Declare a teardown method for the test group. Optional */
	void teardown()
	{
	}
}; /* Do not forget semicolumn */

/* Declare one test within the test group */
TEST(Card, CardCreateTest)
{
	Card *cd;

	cd = new Card(Card::SUIT_SPADE, 1);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(1, cd->getNumber());
	delete cd;
}

TEST(Card, ContinuousCreateTest)
{
	Card *cd[2];

	cd[0] = new Card(Card::SUIT_HEART, 3);
	cd[1] = new Card(Card::SUIT_CLUB, 12);
	CHECK_EQUAL(Card::SUIT_HEART, cd[0]->getSuit());
	CHECK_EQUAL(3, cd[0]->getNumber());
	CHECK_EQUAL(Card::SUIT_CLUB, cd[1]->getSuit());
	CHECK_EQUAL(12, cd[1]->getNumber());
	delete cd[0];
	delete cd[1];
}

TEST(Card, AllCardTest)
{
	Card *cd;
	int i, j;

	for(i = 0; i < 4; i++) {
		for(j = 1; j < 14; j++) {
			cd = new Card(i, j);
			CHECK_EQUAL(i, cd->getSuit());
			CHECK_EQUAL(j, cd->getNumber());
			delete cd;
		}
	}
}

TEST(Card, JokerCreateTest)
{
	Card *cd;

	cd = new Card(Card::SUIT_JOKER, 1);
	CHECK_EQUAL(Card::SUIT_JOKER, cd->getSuit());
	CHECK_EQUAL(0, cd->getNumber());
	delete cd;
}

