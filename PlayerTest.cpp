#include <list>
using namespace std;
#include "CppUTest/TestHarness.h"
#include "Card.h"
#include "Player.h"

/* Declare TestGroup with name CheatSheet */
TEST_GROUP(Player)
{
/* declare a setup method for the test group. Optional. */
	Player *pl;

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
	for(int i = 0; i < 10; i++) { 
		pl = new Player(i);
		CHECK_EQUAL(i, pl->getPlayerNo());
		delete pl;
	}
}

TEST(Player, PlayerCreateTest1)
{
	pl = new Player(0);
	CHECK_EQUAL(Player::RANK_COMMON, pl->getPlayerRank());
	pl->setPlayerRank(Player::RANK_RICH);
	CHECK_EQUAL(Player::RANK_RICH, pl->getPlayerRank());
	delete pl;
}

TEST(Player, PlayerCreateTest2)
{
	int rank[] = {Player::RANK_COMMON, 
						Player::RANK_RICH, 
						Player::RANK_RICHEST, 
						Player::RANK_POOR, 
						Player::RANK_POOREST};

	pl = new Player(0);
	for(int i = 0; i < (sizeof(rank) / sizeof(int)); i++) {
		pl->setPlayerRank(rank[i]);
		CHECK_EQUAL(rank[i], pl->getPlayerRank());
	}
	
	delete pl;
}

TEST(Player, PlayerGiveCardTest2)
{
	Card	*cd;

	cd = new Card(Card::SUIT_CLUB, 1);
	pl = new Player(0);
	CHECK_TRUE(pl->giveCard(cd));

	delete cd;
	delete pl;
}



