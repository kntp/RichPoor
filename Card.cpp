/**
 * @file  Card.cpp
 *  @brief カードの取り扱いを記述する
 */

#include <list>
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

void CardSet::clearCards(void)
{
	for(list<Card*>::iterator it = cardset.begin(); it != cardset.end(); it++) {
		delete *it;
	}

	cardset.clear();

	return;
}

void CardSet::addCard(Card *cd){
	cardset.push_back(cd);
	return;
}

void CardSet::insertCard(Card* cd) {
}

unsigned int CardSet::getSize(void) {
	return cardset.size();
}

Card *CardSet::pickCard(void) {
	Card *ret;

	ret = cardset.front();
	cardset.pop_front();

	return ret;
}

bool CardSet::checkCard(unsigned int no, Card **cd) {
	unsigned int i = 0;

	if(no >= cardset.size()) {
		return false;
	}

	for(list<Card*>::iterator it = cardset.begin(); it != cardset.end(); it++) {
		*cd = *it;
		if(i == no) {
			break;
		}
		i++;
	}

	return true;
}

