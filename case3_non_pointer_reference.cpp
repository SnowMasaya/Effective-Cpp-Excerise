/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
using namespace std;
template<typename T>

void f3(T param){
     cout << param << endl;
}


int main(){
	int x = 27;
	const int cx = x;
	const int& rx = x;
	const char* const ptr = "Fun with pointers";

	f3(x);

	f3(cx);

	f3(rx);

	f3(ptr);

	return 0;
}
