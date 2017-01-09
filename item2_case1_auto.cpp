/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
#include <initializer_list>
using namespace std;

template<typename T>
void func_for_x(T param){
     cout << param << endl;
}


int tmp_main5(){
	{
	    auto x = 27;

	    const auto cx = x;

	    const auto& rx = x;

	    func_for_x(x);

	    func_for_x(cx);

	    func_for_x(rx);

	    auto&& uref1 = x;

	    auto&& uref2 = cx;

	    auto&& uref3 = rx;

	    func_for_x(uref1);

	    func_for_x(uref2);

	    func_for_x(uref3);
	}
	{
		const char name[] = "R. N. Briggs";

		auto arr1 = name;

		auto& arr2 = name;

		func_for_x(arr1);

		func_for_x(arr2);
	}
	return 0;
}

