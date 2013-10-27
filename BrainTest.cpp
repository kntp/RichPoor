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
	bool result;

	field = new CardSet();
	in = new CardSet();
	out = new CardSet();
	result = brain->selectCard(field, in, out);
	CHECK_TRUE(result);
	field->clearCards();
	delete field;
	in->clearCards();
	delete in;
	out->clearCards();
	delete out;
}

