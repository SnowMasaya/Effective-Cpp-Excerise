
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<type_traits>

using namespace std;

template<class T1, class T2>
void print_is_same(){
	cout << is_same<T1, T2>() << endl;
}

int tmp_main28() {
	cout << boolalpha;

	print_is_same<int, int>();
	print_is_same<int, int &>();
	print_is_same<int, int &&>();

	print_is_same<int, remove_reference<int>::type>();
	print_is_same<int, remove_reference<int &>::type>();
	print_is_same<int, remove_reference<int &&>::type>();
}
