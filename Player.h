#ifndef PLAYER_H
#define PLAYER_H
//#include "Card.h"

class Player
{
public:
	Player(int no);
	~Player(void);
	void addCard(Card *cd);
	Card *takeCard(int suit, int num);
private:
	int player_no;
	CardSet	cardset;
};

#endif
