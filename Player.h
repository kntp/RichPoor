#ifndef PLAYER_H
#define PLAYER_H
//#include "Card.h"

class Player
{
public:
	static const int RANK_COMMON = 0;
	static const int RANK_RICH = 1;
	static const int RANK_RICHEST = 2;
	static const int RANK_POOR = 3;
	static const int RANK_POOREST = 4;

	Player(int no);
	~Player(void);
	int getPlayerNo(void);
	int getPlayerRank(void);
	void setPlayerRank(int rank);
private:
	int player_no;
	int player_rank;
	CardSet	cardset;
};

#endif
