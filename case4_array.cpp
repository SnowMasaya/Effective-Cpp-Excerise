/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
using namespace std;
template<typename T>

void f4(T param){
     cout << param << endl;
}


int tmp_main4(){
	const char name[] = "J. P. Briggs";

	const char * ptrToName = name;

	f4(name);

	f4(ptrToName);

	return 0;
}
