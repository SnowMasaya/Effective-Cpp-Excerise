
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Widget.h"
using namespace std;

int main(){

	Widget w;
	vector<bool> features(const Widget& w);

	auto highPriority = static_cast<bool>(features(w)[5]);

	return 0;
}

