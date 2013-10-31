#include "CppUTest/TestHarness.h"
#include <list>
using namespace std;
#include "Card.h"
#include "Brain.h"

TEST_GROUP(Brain)
{
	Brain *brain;
	void setup ()
	{
		brain = new Brain();
	}

	void teardown()
	{
		delete brain;
	}
};

TEST(Brain, BrainCreateTest)
{
	Brain *bn;

	bn = new Brain();
	delete bn;
}

TEST(Brain, selectCardTest)
{
	CardSet *field, *in, *out;
	Card *cd;
	bool result;

	field = new CardSet();
	in = new CardSet();
	out = new CardSet();

	cd = CardFactory::createCard(Card::SUIT_SPADE, 3);
	field->addCard(cd);
	cd = CardFactory::createCard(Card::SUIT_SPADE, 4);
	in->addCard(cd);
	CHECK_EQUAL(1, in->getSize());
	CHECK_EQUAL(0, out->getSize());
	result = brain->selectCard(field, in, out);
	CHECK_TRUE(result);
	CHECK_EQUAL(0, in->getSize());
	CHECK_EQUAL(1, out->getSize());

	field->clearCards();
	delete field;
	in->clearCards();
	delete in;
	out->clearCards();
	delete out;
}

