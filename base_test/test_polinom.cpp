#include "polinom.h"
#include <gtest.h>
#include "monom.h"

TEST(TPolinom, can_create_polinom)
{
	TMonom *fr = new TMonom;
	int ln = 1;

	ASSERT_NO_THROW(TPolinom p(fr, ln));
}

TEST(TPolinom, can_create_polinom_default)
{
	ASSERT_NO_THROW(TPolinom p);
}


TEST(TPolinom, can_polinom)
{
	TMonom *fr = new TMonom;
	int ln = 1;
	TPolinom p(fr, ln);

	ASSERT_NO_THROW(TPolinom p1(p));
}

TEST(TPolinom, copied_polinom_has_its_own_memory)
{
	TMonom *fr = new TMonom;
	int ln = 0;
	TPolinom p(fr, ln);
	TPolinom p1(p);

	EXPECT_NE(&p, &p1);
}

TEST(TPolinom, can_add_monom_to_polinom)
{
	TMonom *fr = new TMonom;
	int ln = 0;
	TPolinom p(fr, ln);

	ASSERT_NO_THROW(p.SetCurrent(5, 433));
}

TEST(TPolinom, can_add_two_polinoms){
    TMonom *fr = new TMonom;
    int ln = 0;
    TPolinom p(fr, ln);
    int _ln = 0;
    TPolinom p1(fr, _ln);

	ASSERT_NO_THROW(p + p1);
}