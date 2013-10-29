/**
 * @file  Player.cpp
 *  @brief 思考ルーチンなど
 */

#include <list>
using namespace std;
#include "Card.h"
#include "Brain.h"

Brain::Brain(void)
{
}

Brain::~Brain(void)
{
}

bool Brain::selectCard(CardSet *field, CardSet *in, CardSet *out)
{
	Card *cd;

	cd = in->pickCard();
	out->addCard(cd);

	return true;
}


