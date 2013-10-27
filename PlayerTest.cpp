#include <list>
using namespace std;
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

	for(int i = 0; i < 10; i++) { 
		pl = new Player(i);
		CHECK_EQUAL(i, pl->getPlayerNo());
		delete pl;
	}
}

TEST(Player, PlayerCreateTest2)
{
	Player *pl;

	pl = new Player(0);
	CHECK_EQUAL(Player::RANK_COMMON, pl->getPlayerRank());
	pl->setPlayerRank(Player::RANK_RICH);
	CHECK_EQUAL(Player::RANK_RICH, pl->getPlayerRank());
	pl->setPlayerRank(Player::RANK_RICHEST);
	CHECK_EQUAL(Player::RANK_RICHEST, pl->getPlayerRank());
	pl->setPlayerRank(Player::RANK_POOR);
	CHECK_EQUAL(Player::RANK_POOR, pl->getPlayerRank());
	pl->setPlayerRank(Player::RANK_POOREST);
	CHECK_EQUAL(Player::RANK_POOREST, pl->getPlayerRank());
	
	delete pl;
}



