#include "CppUTest/TestHarness.h"
#include <list>
using namespace std;
#include "Card.h"

/* Declare TestGroup with name CheatSheet */
TEST_GROUP(Card)
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

// CardFactory Test
TEST_GROUP(CardFactory)
{
	void setup ()
	{
	}

	void teardown()
	{
	}
};

TEST(CardFactory, FactoryTest)
{
	Card *cd;

	cd = CardFactory::createCard(Card::SUIT_DIAMOND, 10);
	CHECK(cd != 0);
	CHECK_EQUAL(Card::SUIT_DIAMOND, cd->getSuit());
	CHECK_EQUAL(10, cd->getNumber());

	delete cd;
}


TEST(CardFactory, newFactoryTest)
{
	CardFactory *cf;
	Card *cd;

	cf = new CardFactory();
	cd = cf->createCard(Card::SUIT_DIAMOND, 10);
	CHECK(cd != 0);
	CHECK_EQUAL(Card::SUIT_DIAMOND, cd->getSuit());
	CHECK_EQUAL(10, cd->getNumber());

	delete cd;
	delete cf;
}

TEST(CardFactory, RangeTest)
{
	Card *cd;
	int s;

	for(s = Card::SUIT_SPADE; s < Card::SUIT_JOKER; s++) {
		cd = CardFactory::createCard(s, 14);
		CHECK_EQUAL(0, cd);
		
		cd = CardFactory::createCard(s, -1);
		CHECK_EQUAL(0, cd);
		
		cd = CardFactory::createCard(s, 20);
		CHECK_EQUAL(0, cd);
		
		cd = CardFactory::createCard(s, 65536);
		CHECK_EQUAL(0, cd);
	}
	
	cd = CardFactory::createCard(Card::SUIT_SPADE, 0);
	CHECK_EQUAL(0, cd);
	cd = CardFactory::createCard(Card::SUIT_HEART, -1);
	CHECK_EQUAL(0, cd);
	cd = CardFactory::createCard(Card::SUIT_CLUB, 0);
	CHECK_EQUAL(0, cd);
	cd = CardFactory::createCard(Card::SUIT_DIAMOND, 0);
	CHECK_EQUAL(0, cd);
	cd = CardFactory::createCard(5, 0);
	CHECK_EQUAL(0, cd);
	cd = CardFactory::createCard(100, 0);
	CHECK_EQUAL(0, cd);

	delete cd;
}

// CardFactory Test
TEST_GROUP(CardSet)
{
	CardSet *cset;

	void setup ()
	{
		cset = new CardSet();
	}

	void teardown()
	{

		cset->clearCards();

		delete cset;
	}
};

TEST(CardSet, CreateTest)
{
	Card *cd;

	cd = CardFactory::createCard(Card::SUIT_DIAMOND, 10);
	cset->addCard(cd);
	cd = cset->pickCard();

	CHECK_EQUAL(Card::SUIT_DIAMOND, cd->getSuit());
	CHECK_EQUAL(10, cd->getNumber());

	delete cd;

	cd = CardFactory::createCard(Card::SUIT_SPADE, 1);
	cset->addCard(cd);
	cd = cset->pickCard();

	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(1, cd->getNumber());

	delete cd;
}

TEST(CardSet, AddCardTest)
{
	Card *cd;

	cd = CardFactory::createCard(Card::SUIT_DIAMOND, 10);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_SPADE, 1);
	cset->addCard(cd);
	cd = cset->pickCard();

	CHECK_EQUAL(Card::SUIT_DIAMOND, cd->getSuit());
	CHECK_EQUAL(10, cd->getNumber());

	delete cd;

	cd = cset->pickCard();

	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(1, cd->getNumber());

	delete cd;
}


TEST(CardSet, checkCardTest)
{
	Card *cd;

	cd = CardFactory::createCard(Card::SUIT_HEART, 10);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_CLUB, 3);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_SPADE, 4);
	cset->addCard(cd);
	cd = cset->checkCard(0);

	CHECK_EQUAL(Card::SUIT_HEART, cd->getSuit());
	CHECK_EQUAL(10, cd->getNumber());

	cd = cset->checkCard(1);

	CHECK_EQUAL(Card::SUIT_CLUB, cd->getSuit());
	CHECK_EQUAL(3, cd->getNumber());

	cd = cset->checkCard(2);

	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(4, cd->getNumber());

	cd = cset->checkCard(3);

	CHECK_EQUAL(0, cd);
}
