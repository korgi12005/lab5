#pragma once
#include<iostream>

using namespace std;
#include "TList.h"
#include "HeadList.h"

struct TMonom
{
	double coef;
	int px, py, pz;
public:
	bool operator ==(const TMonom &m);
	bool operator >(const TMonom &m);
	bool operator >=(const TMonom &m);
	bool operator <(const TMonom &m);
	bool operator <=(const TMonom &m);
	bool operator !=(const TMonom &m);

	friend istream& operator>>(istream& in, TMonom &m)
	{
		int pxyz;
		cout << "coefficient: ";
		in >> m.coef;
		cout << endl << " power: ";
		in >> pxyz;
		m.px = pxyz / 100;
		m.py = pxyz / 10 % 10;
		m.pz = pxyz % 10;
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMonom &m)
	{
		out << m.coef << "(x^" << m.px << ")" << "(y^" << m.py << ")" << "(z^" << m.pz << ")";
		return out;
	}
};

bool TMonom::operator==(const TMonom &m) {
	if (px == m.px && py == m.py&& pz == m.pz) {
		return true;
	}
	else
	{
		return false;
	}
}

bool TMonom::operator>(const TMonom &m) {
	int st_f, st_s;
	st_f = px * 100 + py * 10 + pz;
	st_s = m.px * 100 + m.py * 10 + m.pz;
	if (st_f>st_s)
	{
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator>=(const TMonom &m) {
	int st_f, st_s;
	st_f = px * 100 + py * 10 + pz;
	st_s = m.px * 100 + m.py * 10 + m.pz;
	if (st_f >= st_s)
	{
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator<(const TMonom &m) {
	int st_f, st_s;
	st_f = px * 100 + py * 10 + pz;
	st_s = m.px * 100 + m.py * 10 + m.pz;
	if (st_f < st_s)
	{
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator<=(const TMonom &m) {
	int st_f, st_s;
	st_f = px * 100 + py * 10 + pz;
	st_s = m.px * 100 + m.py * 10 + m.pz;
	if (st_f <= st_s)
	{
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator!=(const TMonom &m) {
	if (*this == m)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}



class TPolinom :public THeadList<TMonom> {
public:
	TPolinom() :THeadList<TMonom>() {
		pHead->val.coef = 0;
		pHead->val.px = 0;
		pHead->val.py = 0;
		pHead->val.pz = -1;
	}
	TPolinom(int monoms[][2], int n) :THeadList<TMonom>(){
		pHead->val.coef = 0;
		pHead->val.px = 0;
		pHead->val.py = 0;
		pHead->val.pz = -1;
		TMonom M;
		for (int i = 0; i < n; i++)
		{
			M.coef = monoms[i][0];
			M.pz = monoms[i][1] % 10;
			M.px = monoms[i][1] / 100;
			M.py = monoms[i][1] / 10 % 10;
			InsLast(M);
		}
	}
	TPolinom(TPolinom & P) : THeadList<TMonom>() {
		pHead->val.coef = 0;
		pHead->val.px = 0;
		pHead->val.py = 0;
		pHead->val.pz = -1;
		TMonom M;
		for (P.Reset(); !P.IsEnd(); P.GoNext())
		{
			M = P.pCurr->val;
			InsLast(M);
		}
	}
	void AddMonom(const TMonom &M) {
		int flag = 0;
		for (Reset(); !IsEnd(); GoNext()) {
			if (pCurr->val == M)
			{
				pCurr->val.coef += M.coef;
				if (pCurr->val.coef == 0)
				{
					DelCurr();
					flag = 1;
				}
				break;
			}
			else {
				if (pCurr->val < M) {
					InsCurr(M);
					break;
				}
			}
		}
		if (IsEnd() && flag == 0) InsCurr(M);
	}
	TPolinom operator* (double a) {
		TPolinom res(*this);
		for (res.Reset(); !res.IsEnd(); res.GoNext())
		{
			res.pCurr->val.coef *= a;
			if (res.pCurr->val.coef == 0)
			{
				res.DelCurr(); break;
			}
		}
		return res;
	}
	void operator*=(double a) {

		for (Reset(); !IsEnd(); GoNext())
		{
			pCurr->val.coef *= a;
			if (pCurr->val.coef == 0)
			{
				DelCurr(); break;
			}
		}

	}
	void operator*=(TMonom M) {
		for (Reset(); !IsEnd(); GoNext())
		{
			pCurr->val.coef *= M.coef;
			pCurr->val.px += M.px;
			pCurr->val.py += M.py;
			pCurr->val.pz += M.pz;
		}
		
	}
	TPolinom operator *(TMonom M) {
		TPolinom res(*this);
		for (res.Reset(); !res.IsEnd(); res.GoNext()) {
			res.pCurr->val.px += M.px;
			res.pCurr->val.py += M.py;
			res.pCurr->val.pz += M.pz;
			res.pCurr->val.coef *= M.coef;
		}
		return res;
	}
	void operator +=(TPolinom& Q) {
		TMonom pm, qm, rm;
		Reset();
		Q.Reset();
		while (!Q.IsEnd())
		{
			pm = pCurr->val;
			qm = Q.pCurr->val;
			if (pm>qm)
			{
				GoNext();
			}
			else
			{
				if (pm>qm)
				{
					InsCurr(qm);
					Q.GoNext();
				}
				else {
					rm = pm;
					rm.coef += qm.coef;
					if (rm.coef == 0)
					{
						DelCurr();
						Q.GoNext();
					}
					else
					{
						pCurr->val = rm;
						GoNext();
						Q.GoNext();
					}
				}
			}

		}

	}

	friend istream& operator>>(istream &in, TPolinom &p) {
		TMonom m;
		in >> m;
		while (m.coef != 0) {
			p.AddMonom(m);
			in >> m;
		}
		return in;
	}
	friend ostream& operator<<(ostream &out, TPolinom &p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			if (p.pCurr->val.coef < 0 || p.pCurr == p.pFirst)
				out << p.pCurr->val;
			else
				out << " + " << p.pCurr->val;
		}
		return out;
	}
};