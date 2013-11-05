#include <list>
using namespace std;
#include "CppUTest/TestHarness.h"
#include "Card.h"
#include "Field.h"

TEST_GROUP(Field)
{
	Field *fld;

	void setup ()
	{
		fld = new Field();
	}

	void teardown()
	{
		delete fld;
	}
};

TEST(Field, FieldCreateTest)
{
	CHECK_FALSE(fld == 0);
}

TEST(Field, FieldInitTest)
{
	fld->initField();
}

TEST(Field, GetCurFeildTest)
{

}
