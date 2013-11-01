#include <list>
using namespace std;
#include "CppUTest/TestHarness.h"
#include "Card.h"
#include "Field.h"

TEST_GROUP(Field)
{
	void setup ()
	{
	}

	void teardown()
	{
	}
};

TEST(Field, FieldCreateTest)
{
	Field *fd;

	fd = new Field();

	CHECK_FALSE(fd == 0);

	delete fd;
}
