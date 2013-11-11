/**
 * @file  Field.cpp
 * @brief 場の取り扱いを記述する
 */

#include <list>
using namespace std;
#include "Card.h"
#include "Field.h"

Field::Field(void)
{
	curField = new CardSet();
	postField = new CardSet();
}

Field::~Field(void)
{
	delete curField;
	delete postField;
}

void Field::initField(void)
{
	return;
}

CardSet *Field::CheckCurField(void)
{
	return curField;
}

