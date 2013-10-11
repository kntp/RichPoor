#include <vector>
using namespace std;
#include "Card.h"


// Card Class
Card::Card(int suit, int num) :
		suit(suit), num(num) {
	if (suit == SUIT_JOKER) {
		this->num = 0;
	}
}

Card::~Card(void) {
}

int Card::getSuit(void) {
	return this->suit;
}

int Card::getNumber(void) {
	return this->num;
}

CardFactory::CardFactory(void) {
}

CardFactory::~CardFactory(void) {
}

// CardFactory Class
Card *CardFactory::createCard(int suit, int num) {
	Card *cd;

	if ((suit < 0) || (suit > 4)) {
		return 0;
	}

	if ((num < 1) || (num > 13)) {
		return 0;
	}

	cd = new Card(suit, num);

	return cd;
}

// CardSet Class

CardSet::CardSet()
{
	// TODO 自動生成されたコンストラクター・スタブ

}

CardSet::~CardSet() {
	// TODO Auto-generated destructor stub
}

void CardSet::addCard(Card *cd){
	return;
}

void CardSet::insertCard(Card* cd) {
}

Card *CardSet::pickCard(void) {

	return 0;
}

