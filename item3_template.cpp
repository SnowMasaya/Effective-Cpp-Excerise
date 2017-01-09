
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using boost::typeindex::type_id_with_cvr;

template<typename T>
void f(const T& param){

	cout << "T =" << type_id_with_cvr<T>().pretty_name() << endl;

	cout << "param =" << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int tmp_main6(){

	const int theAnswer = 42;
	auto x = theAnswer;
	auto y = &theAnswer;

	f(theAnswer);

	f(x);

	f(y);

	return 0;
}

