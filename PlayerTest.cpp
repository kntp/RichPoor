#include "CppUTest/TestHarness.h"
#include "Card.h"
#include "Player.h"

/* Declare TestGroup with name CheatSheet */
TEST_GROUP(Player)
{
/* declare a setup method for the test group. Optional. */
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
TEST(Player, PlayerCreateTest)
{
	Player *pl;
	Card *cd, *cd2;

	pl = new Player(0);
	cd = new Card(Card::SUIT_SPADE, 1);
	pl->addCard(cd);
	cd2 = pl->takeCard(Card::SUIT_SPADE, 1);
	CHECK_EQUAL(Card::SUIT_SPADE, cd2->getSuit());
	CHECK_EQUAL(1, cd2->getNumber());
	delete cd2;
	delete pl;
}



