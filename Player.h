#ifndef PLAYER_H
#define PLAYER_H
//#include "Card.h"

class Player
{
public:
	Player(int no);
	~Player(void);
	int getPlayerNo(void);
private:
	int player_no;
	CardSet	cardset;
};

#endif
