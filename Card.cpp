#include "Card.h"

Card::Card(int suit, int num):suit(suit),num(num)
{
	if(suit == SUIT_JOKER) {
		this->num = 0;
	}
}

Card::~Card(void)
{
}

int Card::getSuit(void)
{
	return this->suit;
}

int Card::getNumber(void)
{
	return this->num;
}

