
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<utility>

using namespace std;

void overload (const int& x) { cout << "[lvalue]"; }
void overload (int&& x) { cout << "[rvalue]"; }

template <class T> void fn (T&& x) {
	overload (x);
	overload (forward<T>(x));
}

int tmp_main33() {
	int a;

	cout << "calling fn with lvalue: ";
	fn(a);
	cout << endl;

	cout << "calling fn with rvalue: ";
	fn(0);
	cout << endl;

	return 0;
}
