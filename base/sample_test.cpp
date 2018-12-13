#include <iostream>
//#include <string>
#include "polinom.h"

using namespace std;

void main() {

	TPolinom *pol1 = new TPolinom();
	TPolinom *pol2 = new TPolinom();
	pol1->SetCurrent(2, 543);
	pol1->SetCurrent(-3, 421);
	pol1->SetCurrent(7, 211);
	pol2->SetCurrent(6, 543);
	pol2->SetCurrent(3, 421);
	
	TPolinom *pol3 = new TPolinom();
	*pol3 = *pol1 + *pol2;
	pol3->Show();
	cout << '\n';

	*pol3 = *pol1 - *pol2;
	pol3->Show();
}