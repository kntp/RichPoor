#include <list>
using namespace std;
#include "Card.h"
#include "Player.h"

Player::Player(int no):player_no(no)
{
}

Player::~Player(void)
{
}

int Player::getPlayerNo(void)
{
	return player_no;
}
int Player::getPlayerRank(void)
{
	return 0;
}

