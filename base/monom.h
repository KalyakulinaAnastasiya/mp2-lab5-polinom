#pragma once
//#include<iostream>
 
//template <class T>
class TMonom {
	int Coeff;       //коэффициент
	int Index;       //свертка степеней
	TMonom *pNext;    //указатель на следующее звено
public:
	TMonom(int cf = 1, int ind = 0) {
		Coeff = cf;
		Index = ind;
		this->pNext = nullptr;
	}
	void SetCoeff(int cf) {                
		Coeff = cf;
	}
	void SetIndex(int in) {
		Index = in;
	}
	int GetCoeff() {
		return Coeff;
	}
	int GetIndex() {
		return Index;
	}

	TMonom& operator=(const TMonom &mp) {
		Coeff = mp.Coeff;
		Index = mp.Index;
		return *this;
	}
	
	void SetNext(TMonom *ptr) {
		pNext = ptr;
	}

	TMonom* GetNext() {
		return pNext;
	}
};