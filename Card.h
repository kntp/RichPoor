#ifndef CARD_H
#define CARD_H
class Card {
public:
	static const int SUIT_NONE = 0;
	static const int SUIT_SPADE = 1;
	static const int SUIT_HEART = 2;
	static const int SUIT_DIAMOND = 3;
	static const int SUIT_CLUB = 4;
	static const int SUIT_JOKER = 5;

	Card(int suit, int num);
	~Card(void);
	int getSuit(void);
	int getNumber(void);
private:
	int suit;
	int num;
};

class CardFactory {
public:
	CardFactory(void);
	~CardFactory(void);
	static Card *createCard(int suit, int num);
};

class CardSet {
public:
	CardSet();
	~CardSet();
	void clearCards(void);
	void addCard(Card *cd);
	void insertCard(Card *cd);
	void sortByNum(void);
	Card *pickCard(void);
	Card *checkCard(unsigned int no);
private:
	list<Card*> cardset;
};
#endif /* CARD_H */

