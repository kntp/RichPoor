#ifndef CARD_H
#define CARD_H
class Card
{
public:
	static const int SUIT_SPADE = 0;
	static const int SUIT_HEART = 1;
	static const int SUIT_DIAMOND = 2;
	static const int SUIT_CLUB = 3;
	static const int SUIT_JOKER = 4;

	Card(int suit, int num);
	~Card(void);
	int getSuit(void);
	int getNumber(void);
private:
	int suit;
	int num;
};

class CardFactory
{
public:
	CardFactory(void);
	~CardFactory(void);
	static Card *createCard(int suit, int num);
};

#endif /* CARD_H */
