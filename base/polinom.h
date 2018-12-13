#pragma once
//#include<iterator>
#include"monom.h"
#include<iostream>
using namespace std;

//template <class T>
class TPolinom
{
private:
	TMonom *pFirst;         //указатель на первое звено списка
	TMonom *pLast;          //указатель на последнее звено списка
	int ListLen;          //количество звеньев в списке

public:
	TPolinom() {
		this->ListLen = 0;
	}

	TPolinom(TMonom *fr, int ln) {
		this->pFirst = fr;
		//this->pLast = ls;
		this->ListLen = ln;
	}

	TMonom* GetFirst() {
		return pFirst;
	}

	TMonom* GetLast() {
		return pLast;
	}

	int GetLen() {
		return ListLen;
	}

	void SetLast(TMonom *p) {
		pLast = p;
	}

	void SetLen(int p) {
		ListLen = p;
	}

	friend TPolinom operator+(const TPolinom& pol1, const TPolinom& pol2) {
		TPolinom *pRes = new TPolinom();
		TMonom *p1, *p2;
		bool pr;
		p1 = pol1.pFirst;
		for (int i = 0; i < pol1.ListLen; i++) {
			p2 = pol2.pFirst;
			pr = true;
			for (int j = 0; j < pol2.ListLen; j++) {
				int ind1 = p1->GetIndex();
				int ind2 = p2->GetIndex();
				if (ind1 == ind2) {
					pRes->SetCurrent(p1->GetCoeff() + p2->GetCoeff(), p1->GetIndex());
					pr = false;
				}
				p2 = p2->GetNext();
			}
			if (pr) {
				
				pRes->SetCurrent(p1->GetCoeff(), p1->GetIndex());
			}
			p1 = p1->GetNext();
		}
		return *pRes;
	}

	friend TPolinom operator-(const TPolinom& pol1, const TPolinom& pol2) {
		TPolinom *pRes = new TPolinom();
		TMonom *p1, *p2;
		bool pr;
		p1 = pol1.pFirst;
		for (int i = 0; i < pol1.ListLen; i++) {
			p2 = pol2.pFirst;
			pr = true;
			for (int j = 0; j < pol2.ListLen; j++) {
				int ind1 = p1->GetIndex();
				int ind2 = p2->GetIndex();
				if (ind1 == ind2) {
					pRes->SetCurrent(p1->GetCoeff() - p2->GetCoeff(), p1->GetIndex());
					pr = false;
				}
				p2 = p2->GetNext();
			}
			if (pr) {

				pRes->SetCurrent(p1->GetCoeff(), p1->GetIndex());
			}
			p1 = p1->GetNext();
		}
		return *pRes;
	}

	 TPolinom& TPolinom::operator=(const TPolinom& pol){
		this->Clean();
		pFirst = pol.pFirst;
		pLast = pol.pLast;
		ListLen = pol.ListLen;
		return *this;
	}

	void Clean() {
		if (GetLen() > 0) {
			TMonom *tmp;
			tmp = pFirst;
			TMonom *pNext;
			for (int i = 0; i < ListLen; i++) {
				pNext = tmp->GetNext();
				delete tmp;
				tmp = pNext;
			}
			this->pFirst = nullptr;
			this->pLast = nullptr;
			this->ListLen = 0;
		}
	}

	void Show() {
		TMonom *tmp;
		tmp = pFirst;
		bool pr = true;
		for (int i = 0; i < ListLen; i++) {
			if ((tmp->GetCoeff() != 0) ) {
				if ((tmp->GetCoeff() > 0) && (!pr)) {
					cout << '+';
				}
				cout << tmp->GetCoeff();
				cout << 'x' << '^' << tmp->GetIndex() / 100 % 10;
				cout << 'y' << '^' << tmp->GetIndex() / 10 % 10;
				cout << 'z' << '^' << tmp->GetIndex() % 10;
				
				pr = false;
			}
			tmp = tmp->GetNext();
		}
	}

	void SetCurrent(int coeff, int index) {
		TMonom *p = new TMonom(coeff, index);
		TMonom *tmp;
		if (ListLen == 0) {
			pFirst = p;
			pLast = p;
		}
		else {
			pLast->SetNext(p);
			pLast = p;
		}
		ListLen++;
	}
};

