#include <vector>
using namespace std;
#include "Card.h"
#include "Player.h"

Player::Player(int no):player_no(no)
{
}

Player::~Player(void)
{
}

void Player::addCard(Card *cd)
{
	delete cd;
}

Card *Player::takeCard(int suit, int num)
{
	Card *cd;

	cd = new Card(Card::SUIT_SPADE, 1);

	return cd;
}
