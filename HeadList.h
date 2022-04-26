#pragma once

#include <iostream>
#include "TList.h"

using namespace std;

template <class T>
class THeadList :public TList<T> {

protected:
	TNode<T> *pHead;
public:
	THeadList() :TList<T>() {
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pStop = pFirst = pLast = pHead;
	}

	~THeadList() {
		delete pHead;
	}

	void InsFirst(T val) {
		TList::InsFirst(val);
		pHead->pNext = pFirst;
	}

	void DelFirst() {
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
};