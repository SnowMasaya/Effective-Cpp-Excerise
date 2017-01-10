
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
#include <vector>
using namespace std;

template<typename C, typename V>
void findAndInsert(C& container,
		const V& targetVal,
		const V& insertVal)
{
	auto it = find(cbegin(container), end(container), targetVal);

	container.insert(it, insertVal);
}

int tmp_main13(){

	vector<int> values;

	vector<int>::iterator it = find(values.begin(), values.end(), 1983);
	auto it2 = find(values.begin(), values.end(), 1983);
	values.insert(it, 1983);
	values.insert(it2, 1983);

	return 0;
}

