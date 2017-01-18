
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int tmp_main31() {
	vector<int> c = {1, 2, 3, 4, 5, 6, 7};
	int x = 5;
	c.erase(remove_if(c.begin(), c.end(), [x](int n){ return n < x; }), c.end());

	cout << "c: ";
	for_each(c.begin(), c.end(), [](int i){ cout << i << " "; });
	cout << endl;

	auto func1 = [](int i){ return i + 4; };
	cout << "func1: " << func1(6) << endl;

	function<int(int)> func2 = [](int i){ return i + 4; };
	cout << "func2: " << func2(6) << endl;

	auto func3 = func2;
	cout << "func3: " << func3(6) << endl;
}
