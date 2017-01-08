/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include "case1_const.h"
#include <iostream>
using namespace std;
template<typename T>

void f(const T* param){
     cout << param << endl;
     cout << *param << endl;
}


int tmp_main(){
	int x = 27;
	const int *px = &x;

	f(&x);

	f(px);

	return 0;
}
