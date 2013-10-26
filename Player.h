#ifndef PLAYER_H
#define PLAYER_H
//#include "Card.h"

class Player
{
public:
	static const int RANK_COMMON = 0;

	Player(int no);
	~Player(void);
	int getPlayerNo(void);
	int getPlayerRank(void);
private:
	int player_no;
	CardSet	cardset;
};

#endif
