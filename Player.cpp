/**
 * @file  Player.cpp
 *  @brief プレーヤーの取り扱いを記述する
 */

#include <list>
using namespace std;
#include "Card.h"
#include "Player.h"

Player::Player(int no):player_no(no), player_rank(RANK_COMMON)
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
	return player_rank;
}

void Player::setPlayerRank(int rank)
{
	player_rank = rank;

	return;
}

bool Player::giveCard(Card *cd)
{
	return true;
}
