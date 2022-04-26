#pragma once
#include<iostream>
#include"TPolinom.h"
#include"TList.h"
#include<math.h>

int main() {
	try {
		TPolinom p, p1,p2,p3;
		TMonom m[3];
		cin >> p ;
		cout << p;
		cin >> p1 ;
		cout << p1 << endl;
		p += p1;
		cout << p << endl;
		cin >> p2;
		p2 *= -1;
		cout << p2 << endl;
	
		cin >> p3;
		p3 += p2;
		cout << p3 << endl;
		
	}
	catch (char *s) {
		cout << s;
	}
	system("pause");
	return 0;
}