#include "gtest.h"
#include "..\TPolinom\TPolinom.h"
#include"TPolinom.h"
#include <iostream>
TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m);
}

TEST(TMonom, can_ins_monom_with_pos_coef)
{
	TMonom m;
	m.px = 0;
	m.py = 0;
	m.pz = 0;
	ASSERT_NO_THROW(m.coef = 1);
}

TEST(TMonom, can_ins_monom_with_neg_coef)
{
	TMonom m;
	m.px = 0;
	m.py = 0;
	m.pz = 0;
	ASSERT_NO_THROW(m.coef = -1);
}

TEST(TMonom, can_ins_monom_with_neg_step)
{
	TMonom m;
	m.px = 1;
	m.py = 1;
	m.pz = 1;
	ASSERT_NO_THROW(m.coef = 5);
}

TEST(TMonom, can_ins_monom_with_pos_step)
{
	TMonom m;
	m.px = -1;
	m.py = -1;
	m.pz = -1;
	ASSERT_NO_THROW(m.coef = -5);
}

TEST(TMonom, can_compare_the_monomials)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coef = 7;
	m2.px = 1;
	m2.py = 1;
	m2.pz = 1;
	EXPECT_EQ(m1 == m2, 1);
}

TEST(TMonom, can_ne_monoms)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coef = 7;
	m2.px = 1;
	m2.py = 2;
	m2.pz = 3;
	EXPECT_EQ(m1 != m2, 1);
}

TEST(TMonom, Sravnenie)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coef = 7;
	m2.px = 1;
	m2.py = 2;
	m2.pz = 3;
	EXPECT_EQ(m1 <m2, 1);
	EXPECT_EQ(m1 > m2, 0);
}

TEST(TPolinom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, can_create_polynom_with_arr)
{
	int arr[2][2];
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[0][1] = 1;
	arr[1][1] = 1;
	ASSERT_NO_THROW(TPolinom p(arr, 2));
}

TEST(TPolinom, can_copy_polynom)
{
	int arr[2][2];
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[0][1] = 1;
	arr[1][1] = 1;
	TPolinom p(arr, 2);
	ASSERT_NO_THROW(TPolinom p_copy(p));
}

TEST(TPolinom, can_add_monom)
{
	TPolinom p;
	TMonom a;
	a.coef = 1;
	a.px = 1;
	a.py = 1;
	a.pz = 1;
	ASSERT_NO_THROW(p.AddMonom(a));
	ASSERT_NO_THROW(p * 5);
	ASSERT_NO_THROW(p *= 5);
	ASSERT_NO_THROW(p * a);
	ASSERT_NO_THROW(p *= a);
}
TEST(TPolinom, Add_monoms_s_protiv_coef){
	TPolinom P;
	TMonom m[3];
	for (int i = 0; i < 3; i++)
	{
		m[i].coef = 4;
		m[i].px = 3;
		m[i].py = 2;
		m[i].pz = 1;
		P.AddMonom(m[i]);
	}
	m[2].coef = -4;
	P.AddMonom(m[2]);
	P.Reset();
	EXPECT_EQ(P.GetCurrEl() == m[1], 1);
}

TEST(TPolinom, correct_coef){
	TPolinom P;
	TMonom m;
	m.coef = 4;
	m.px = 1;
	m.py = 1;
	m.pz = 1;
	P.AddMonom(m);
	m.coef = 4;
	P.AddMonom(m);
	P.Reset();
	EXPECT_EQ(P.GetCurrEl().coef == 8, 1);
}
TEST(TPolinom, Can_add_monoms_with_different_coef){
	TPolinom P;
	TMonom m[3];
	for (int i = 0; i < 3; i++)
	{
		m[i].coef = 4 * i;
		m[i].px = 3 * i;
		m[i].py = 2 * i;
		m[i].pz = i;
		P.AddMonom(m[i]);
	}
	m[0].coef = -4;
	P.AddMonom(m[0]);
	P.Reset();
	P.GoNext();
	EXPECT_EQ(P.GetCurrEl() == m[1], 1);
}
TEST(TPolinom, stop)
{
	system("pause");
}
