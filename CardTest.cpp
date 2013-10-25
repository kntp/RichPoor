#include "CppUTest/TestHarness.h"
#include <list>
using namespace std;
#include "Card.h"

TEST_GROUP(Card)
{
	void setup ()
	{
	}

	void teardown()
	{
	}
};

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
	delete cd;
}

TEST(Card, CardCompareTest)
{
	Card *cd1, *cd2;

	cd1 = new Card(Card::SUIT_SPADE, 1);
	cd2 = new Card(Card::SUIT_SPADE, 2);
	CHECK_TRUE(*cd1 < *cd2);
	delete cd1;
	delete cd2;

	cd1 = new Card(Card::SUIT_CLUB, 1);
	cd2 = new Card(Card::SUIT_SPADE, 2);
	CHECK_TRUE(*cd1 < *cd2);
	delete cd1;
	delete cd2;
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
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = cset->pickCard();

	CHECK_EQUAL(Card::SUIT_DIAMOND, cd->getSuit());
	CHECK_EQUAL(10, cd->getNumber());

	delete cd;

	cd = CardFactory::createCard(Card::SUIT_SPADE, 1);
	CHECK(cd != 0);
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
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_SPADE, 1);
	CHECK(cd != 0);
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
	bool result;

	cd = CardFactory::createCard(Card::SUIT_HEART, 10);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_CLUB, 3);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_SPADE, 4);
	CHECK(cd != 0);
	cset->addCard(cd);
	result = cset->checkCard(0, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_HEART, cd->getSuit());
	CHECK_EQUAL(10, cd->getNumber());

	result = cset->checkCard(1, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_CLUB, cd->getSuit());
	CHECK_EQUAL(3, cd->getNumber());

	result = cset->checkCard(2, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(4, cd->getNumber());

	result = cset->checkCard(3, &cd);

	CHECK_EQUAL(false, result);
}

TEST(CardSet, sizeTest)
{
	Card *cd;

	CHECK_EQUAL(0, cset->getSize());

	cd = CardFactory::createCard(Card::SUIT_DIAMOND, 13);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_JOKER, 0);
	CHECK(cd != 0);
	cset->addCard(cd);

	CHECK_EQUAL(2, cset->getSize());

	cd = CardFactory::createCard(Card::SUIT_SPADE, 5);
	CHECK(cd != 0);
	cset->addCard(cd);

	CHECK_EQUAL(3, cset->getSize());
}

TEST(CardSet, clearCardTest)
{
	Card *cd;

	cd = CardFactory::createCard(Card::SUIT_SPADE, 5);
	CHECK(cd != 0);
	cset->addCard(cd);

	CHECK_EQUAL(1, cset->getSize());

	cset->clearCards();

	CHECK_EQUAL(0, cset->getSize());

}


TEST(CardSet, insertCardTest)
{
	Card *cd;
	bool result;

	cd = CardFactory::createCard(Card::SUIT_SPADE, 5);
	CHECK(cd != 0);
	cset->addCard(cd);

	cd = CardFactory::createCard(Card::SUIT_CLUB, 8);
	CHECK(cd != 0);
	cset->insertCard(cd);

	result = cset->checkCard(0, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_CLUB, cd->getSuit());
	CHECK_EQUAL(8, cd->getNumber());

	result = cset->checkCard(1, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(5, cd->getNumber());
}

TEST(CardSet, sortCardTest)
{
	Card *cd;
	bool result;

	cd = CardFactory::createCard(Card::SUIT_SPADE, 2);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_SPADE, 1);
	CHECK(cd != 0);
	cset->addCard(cd);

	result = cset->checkCard(0, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(2, cd->getNumber());

	result = cset->checkCard(1, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(1, cd->getNumber());

	cset->sortByNum();

	result = cset->checkCard(0, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(1, cd->getNumber());

	result = cset->checkCard(1, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(2, cd->getNumber());
}

TEST(CardSet, sortCardTest2)
{
	Card *cd;
	bool result;

	cd = CardFactory::createCard(Card::SUIT_JOKER, 0);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_SPADE, 5);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_CLUB, 1);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_CLUB, 5);
	CHECK(cd != 0);
	cset->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_DIAMOND, 5);
	CHECK(cd != 0);
	cset->addCard(cd);

	cset->sortByNum();

	result = cset->checkCard(0, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_CLUB, cd->getSuit());
	CHECK_EQUAL(1, cd->getNumber());

	result = cset->checkCard(1, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_SPADE, cd->getSuit());
	CHECK_EQUAL(5, cd->getNumber());

	result = cset->checkCard(2, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_DIAMOND, cd->getSuit());
	CHECK_EQUAL(5, cd->getNumber());

	result = cset->checkCard(3, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_CLUB, cd->getSuit());
	CHECK_EQUAL(5, cd->getNumber());

	result = cset->checkCard(4, &cd);

	CHECK_EQUAL(true, result);
	CHECK_EQUAL(Card::SUIT_JOKER, cd->getSuit());
}
