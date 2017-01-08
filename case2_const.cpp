/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
using namespace std;
template<typename T>

void f2(T&& param){
     cout << param << endl;
}


int tmp_main2(){
	int x = 27;
	const int& rx = x;

	f2(x);

	f2(rx);

	f2(27);

	return 0;
}
